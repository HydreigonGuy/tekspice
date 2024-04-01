/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Brain
*/

#include "../include/Brain.hpp"
#include "../include/C4001.hpp"
#include "../include/C4011.hpp"
#include "../include/C4030.hpp"
#include "../include/C4069.hpp"
#include "../include/C4071.hpp"
#include "../include/C4081.hpp"
#include "../include/C4008.hpp"
#include "../include/Component.hpp"
#include "../include/Input.hpp"
#include "../include/Output.hpp"
#include "../include/Clock.hpp"
#include "../include/Ctrue.hpp"
#include "../include/Cfalse.hpp"
#include "../include/Exceptions.hpp"

#include <iostream>
#include <fstream>
#include <string>

std::string myReadFile(const std::string &filename)
{
    std::ifstream in(filename);

    if (!in)
        return ("ERROR");
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    return (contents);
}

Brain::Brain()
{
    _tick = 0;
}

Brain::~Brain()
{
}

void Brain::display()
{
    nts::Tristate state;

    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (std::pair<std::string, nts::IComponent *> it : this->_components) {
        if (this->_types[it.first] == CompType::INPUT || this->_types[it.first] == CompType::CLOCK) {
            std::cout << "  " << it.first << ": ";
            state = it.second->compute(1);
            if (state == nts::Tristate::TRUE)
                std::cout << "1" << std::endl;
            if (state == nts::Tristate::FALSE)
                std::cout << "0" << std::endl;
            if (state == nts::Tristate::UNDEFINED)
                std::cout << "U" << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (std::pair<std::string, nts::IComponent *> it : this->_components) {
        if (this->_types[it.first] == CompType::OUTPUT) {
            std::cout << "  " << it.first << ": ";
            state = it.second->compute(1);
            if (state == nts::Tristate::TRUE)
                std::cout << "1" << std::endl;
            if (state == nts::Tristate::FALSE)
                std::cout << "0" << std::endl;
            if (state == nts::Tristate::UNDEFINED)
                std::cout << "U" << std::endl;
        }
    }
}

bool Brain::change_value(std::string name, nts::Tristate new_state)
{
    try
    {
        this->_components.at(name);
    }
    catch(const std::exception &e)
    {
        throw (Exceptions::UnexistingComponent());
        return (false);
    }
    if (this->_types[name] == CompType::CLOCK || this->_types[name] == CompType::INPUT) {
        this->_components[name]->changePinState(0, new_state);
        return (true);
    }
    throw (Exceptions::NotInput());
    return (false);
}

void Brain::simulate()
{
    for (std::pair<std::string, nts::IComponent *> it : this->_components)
        it.second->simulate(this->_tick);
    for (std::pair<std::string, nts::IComponent *> it : this->_components) {
        if (this->_types[it.first] == CompType::CLOCK) {
            if (it.second->compute(0) == nts::Tristate::TRUE)
                it.second->changePinState(0, nts::Tristate::FALSE);
            else if (it.second->compute(0) == nts::Tristate::FALSE)
                it.second->changePinState(0, nts::Tristate::TRUE);
        }
    }
    this->_tick++;
}

void Brain::loop()
{
    while (true) {
        this->simulate();
        this->display();
    }
}

void Brain::dump()
{
    for (std::pair<std::string, nts::IComponent *> it : this->_components) {
        it.second->dump();
        std::cout << std::endl;
    }
}

std::string getCompName(std::string file, size_t c)
{
    std::string ret = "";
    size_t i = c;

    for (; file[i] && file[i] != ' ' && file[i] != '\t'; i++);
    for (; file[i] && (file[i] == ' ' || file[i] == '\t'); i++);
    for (; file[i] && file[i] != '\n'; i++)
        ret += file[i];
    return (ret);
}

int getNextPin(std::string file, size_t c, bool end_l)
{
    int i = file.find(":", c);
    int ret = 0;

    for (; file[i] && (file[i] < '0' || file[i] > '9'); i++)
        if (file[i] == ' ' || file[1] == '\t' || file[i] == '\n')
            throw (Exceptions::Components());
    for (; file[i] && file[i] >= '0' && file[i] <= '9'; i++)
        ret = ret * 10 + (file[i] - '0');
    if (end_l) {
        if (ret == 0 || (file[i] != '\n' && file[i] != '\0'))
            throw (Exceptions::Components());
    } else
        if (ret == 0 || (file[i] != ' ' && file[i] != '\t'))
            throw (Exceptions::Components());
    return (ret);
}

bool Brain::createNewLink(std::string file, size_t c)
{
    std::string input;
    std::string output = file.substr(c, file.find(":", c) - c);
    int input_pin = 0;
    int output_pin = getNextPin(file, c, false);
    int i = file.find(":", c);

    for (; file[i] && (file[i] > '9' || file[i] < '0'); i++);
    for (; file[i] && file[i] >= '0' && file[i] <= '9'; i++);
    for (; file[i] && (file[i] == ' ' || file[i] == '\t'); i++);
    input = file.substr(i, file.find(":", i) - i);
    input_pin = getNextPin(file, i, true);
    try
    {
        this->_components.at(input)->changePinState(input_pin, nts::Tristate::UNDEFINED);
        this->_components.at(output)->changePinState(output_pin, nts::Tristate::UNDEFINED);
    }
    catch(const std::exception &e)
    {
        throw (Exceptions::Components());
    }
    this->_components[input]->setLink(input_pin, *this->_components[output], output_pin);
    this->_components[output]->setLink(output_pin, *this->_components[input], input_pin);
    return (true);
}

bool componentDoesntExist(std::string file, size_t c)
{
    if (c == file.find("true", c))
        return (false);
    if (c == file.find("false", c))
        return (false);
    if (c == file.find("input", c))
        return (false);
    if (c == file.find("output", c))
        return (false);
    if (c == file.find("clock", c))
        return (false);
    if (c == file.find("4001", c))
        return (false);
    if (c == file.find("4011", c))
        return (false);
    if (c == file.find("4030", c))
        return (false);
    if (c == file.find("4069", c))
        return (false);
    if (c == file.find("4071", c))
        return (false);
    if (c == file.find("4081", c))
        return (false);
    if (c == file.find("4008", c))
        return (false);
    if (file[c] == '\n' || file[c] == '#')
        return (false);
    return (true);
}

nts::IComponent *createComponent(const std::string &type)
{
    if (type == "input")
        return (new Input);
    if (type == "output")
        return (new Output);
    if (type == "clock")
        return (new Clock);
    if (type == "true")
        return (new Ctrue);
    if (type == "false")
        return (new Cfalse);
    if (type == "4001")
        return (new C4001);
    if (type == "4011")
        return (new C4011);
    if (type == "4030")
        return (new C4030);
    if (type == "4069")
        return (new C4069);
    if (type == "4071")
        return (new C4071);
    if (type == "4081")
        return (new C4081);
    if (type == "4008")
        return (new C4008);
    return (NULL);
}

std::string getCompType(std::string file, int c)
{
    size_t size = 0;

    for (; file[c + size] && file[c + size] != ' ' && file[c + size] != '\t'; size++);
    return (file.substr(c, size));
}

bool Brain::createComponents(std::string file)
{
    size_t c = 0;

    c = file.find(".chipsets:\n", c);
    if (c == std::string::npos)
        return (false);
    c += 11;
    while (file.find("\n", c) != std::string::npos && c != file.find(".links:\n", 0)) {
        try
        {
            this->_components.at(getCompName(file, c));
            return (false);
        }
        catch(const std::exception& e)
        {
        }
        if (c == file.find("input", c))
            this->_types.insert(std::pair<std::string, CompType> (getCompName(file, c), CompType::INPUT));
        else if (c == file.find("output", c))
            this->_types.insert(std::pair<std::string, CompType> (getCompName(file, c), CompType::OUTPUT));
        else if (c == file.find("clock", c))
            this->_types.insert(std::pair<std::string, CompType> (getCompName(file, c), CompType::CLOCK));
        else
            this->_types.insert(std::pair<std::string, CompType> (getCompName(file, c), CompType::OTHER));
        if (createComponent(getCompType(file, c)) != NULL)
            this->_components.insert(std::pair<std::string, nts::IComponent *> (getCompName(file, c), createComponent(getCompType(file, c))));
        if (componentDoesntExist(file, c))
            throw (Exceptions::UnexistingComponent());
        c = file.find("\n", c) + 1;
    }
    if (this->_components.size() == 0)
        return (false);
    c = 0;
    c = file.find(".links:\n", c);
    if (c == std::string::npos)
        return (true);
    c += 8;
    while (file.find("\n", c) != std::string::npos) {
        if (file[c] != '#' && file[c] != '\n') {
            if (file.find(":", c) == std::string::npos)
                return (false);
            if (!this->createNewLink(file, c))
                return (false);
        }
        c = file.find("\n", c) + 1;
    }
    return (true);
}

void Brain::fill_commponents(std::string filename)
{
	std::string file = myReadFile(filename);

    if (file == "ERROR")
        throw (Exceptions::FileOpen());
    if (!this->createComponents(file))
        throw (Exceptions::Components());
}

void Brain::handleStandardInput()
{
    std::string str;

    std::cout << "> ";
    while (std::getline(std::cin, str) && str != "exit") {
        try {
            if (str == "display")
                this->display();
            else if (str == "simulate")
                this->simulate();
            else if (str == "loop")
                this->loop();
            else if (str == "dump")
                this->dump();
            else if (str.find("=", 0) == str.size() - 2 && str[str.size() - 1] == '0')
                this->change_value(str.substr(0, str.find("=", 0)), nts::Tristate::FALSE);
            else if (str.find("=", 0) == str.size() - 2 && str[str.size() - 1] == '1')
                this->change_value(str.substr(0, str.find("=", 0)), nts::Tristate::TRUE);
            else if (str.find("=", 0) == str.size() - 2 && str[str.size() - 1] == 'U')
                this->change_value(str.substr(0, str.find("=", 0)), nts::Tristate::UNDEFINED);
            else
                throw (Exceptions::Command());
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        std::cout << "> ";
    }
}