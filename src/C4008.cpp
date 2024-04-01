/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** C4008
*/

#include "../include/C4008.hpp"
#include "../include/operations.hpp"

#include <iostream>

C4008::C4008() : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (1, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (2, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (3, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (4, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (5, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (6, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (7, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (8, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (9, new InputPin()));
    this->_pins.insert(std::pair<size_t, Pin *> (10, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (11, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (12, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (13, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (14, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (15, new InputPin()));
}

C4008::~C4008()
{
}

void C4008::simulate(size_t tick)
{
    Pin *pin = new Pin();

    for (std::pair<size_t, Pin *> curr : this->_pins)
        curr.second->simulate(tick);
    myAdd(this->getPin(9)->get_state(), this->getPin(7)->get_state(), this->getPin(6)->get_state(), this->getPin(10), pin);
    myAdd(pin->get_state(), this->getPin(4)->get_state(), this->getPin(5)->get_state(), this->getPin(11), pin);
    myAdd(pin->get_state(), this->getPin(2)->get_state(), this->getPin(3)->get_state(), this->getPin(12), pin);
    myAdd(pin->get_state(), this->getPin(15)->get_state(), this->getPin(1)->get_state(), this->getPin(13), this->getPin(14));
}

void C4008::dump() const
{
            std::cout << "4008 component" << std::endl;
            std::cout << "14 pins\n" << std::endl;
}