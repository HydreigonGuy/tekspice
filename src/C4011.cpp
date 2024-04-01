/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** C4011
*/

#include "../include/C4011.hpp"
#include "../include/operations.hpp"

#include <iostream>

C4011::C4011() : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (1, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (2, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (3, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (4, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (5, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (6, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (7, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (8, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (9, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (10, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (11, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (12, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (13, new InputPin()));
}

C4011::~C4011()
{
}

void C4011::simulate(size_t tick)
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
    this->getPin(3)->change_state(myNAND(this->getPin(1)->get_state(), this->getPin(2)->get_state()));
    this->getPin(4)->change_state(myNAND(this->getPin(5)->get_state(), this->getPin(6)->get_state()));
    this->getPin(10)->change_state(myNAND(this->getPin(8)->get_state(), this->getPin(9)->get_state()));
    this->getPin(11)->change_state(myNAND(this->getPin(12)->get_state(), this->getPin(13)->get_state()));
    while (this->_restimulate > 0) {
    for (std::pair<size_t, Pin *> curr : this->_pins)
        curr.second->simulate(tick);
        this->getPin(3)->change_state(myNAND(this->getPin(1)->get_state(), this->getPin(2)->get_state()));
        this->getPin(4)->change_state(myNAND(this->getPin(5)->get_state(), this->getPin(6)->get_state()));
        this->getPin(10)->change_state(myNAND(this->getPin(8)->get_state(), this->getPin(9)->get_state()));
        this->getPin(11)->change_state(myNAND(this->getPin(12)->get_state(), this->getPin(13)->get_state()));
    }
    this->_simulating = nts::Tristate::FALSE;
    this->_restimulate = 0;
}

void C4011::dump() const
{
            std::cout << "4011 component" << std::endl;
            std::cout << "14 pins\n" << std::endl;
}