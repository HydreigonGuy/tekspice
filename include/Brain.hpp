/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Brain
*/

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include "IComponent.hpp"

#include <map>
#include <string>

enum CompType {
    INPUT,
    OUTPUT,
    CLOCK,
    OTHER
};

class Brain {
    public:
        Brain();
        ~Brain();
        void display();
        bool change_value(std::string name, nts::Tristate new_state);
        void simulate();
        void loop();
        void dump();
        void fill_commponents(std::string filename);
        bool createComponents(std::string file);
        bool createNewLink(std::string file, size_t c);
        void handleStandardInput();

    private:
        size_t _tick;
        std::map<std::string, nts::IComponent *> _components;
        std::map<std::string, CompType> _types;
};

#endif /* !BRAIN_HPP_ */
