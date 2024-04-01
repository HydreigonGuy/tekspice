/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4069
*/

#include "../include/C4069.hpp"
#include "../include/operations.hpp"

#include <iostream>

C4069::C4069() : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (1, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (2, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (3, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (4, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (5, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (6, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (7, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (8, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (9, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (10, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (11, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (12, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (13, new InputPin()));
}

C4069::~C4069()
{
}

void C4069::simulate(size_t tick)
{
    if (this->_simulating != nts::Tristate::FALSE) {
        if (this->_simulating == nts::Tristate::TRUE)
            this->_restimulate++;
        else
            this->_restimulate--;
        return;
    }
    this->_simulating = nts::Tristate::TRUE;
    for (std::pair<size_t, Pin *> curr : this->_pins)
        curr.second->simulate(tick);
    this->_simulating = nts::Tristate::UNDEFINED;
    this->getPin(2)->change_state(myINVERTER(this->getPin(1)->get_state()));
    this->getPin(4)->change_state(myINVERTER(this->getPin(3)->get_state()));
    this->getPin(6)->change_state(myINVERTER(this->getPin(5)->get_state()));
    this->getPin(8)->change_state(myINVERTER(this->getPin(9)->get_state()));
    this->getPin(10)->change_state(myINVERTER(this->getPin(11)->get_state()));
    this->getPin(12)->change_state(myINVERTER(this->getPin(13)->get_state()));

    while (this->_restimulate > 0) {
    for (std::pair<size_t, Pin *> curr : this->_pins)
        curr.second->simulate(tick);
        this->getPin(2)->change_state(myINVERTER(this->getPin(1)->get_state()));
        this->getPin(4)->change_state(myINVERTER(this->getPin(3)->get_state()));
        this->getPin(6)->change_state(myINVERTER(this->getPin(5)->get_state()));
        this->getPin(8)->change_state(myINVERTER(this->getPin(9)->get_state()));
        this->getPin(10)->change_state(myINVERTER(this->getPin(11)->get_state()));
        this->getPin(12)->change_state(myINVERTER(this->getPin(13)->get_state()));
    }
    this->_simulating = nts::Tristate::FALSE;
    this->_restimulate = 0;
}


void C4069::dump() const
{
            std::cout << "4069 component" << std::endl;
            std::cout << "14 pins\n" << std::endl;
}