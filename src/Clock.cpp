/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Clock
*/

#include "../include/Clock.hpp"

#include <iostream>

Clock::Clock() : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (0, new Pin()));
    this->_pins.insert(std::pair<size_t, Pin *> (1, new Pin()));
}

Clock::~Clock()
{
}

void Clock::simulate(size_t tick)
{
    this->_pins[1]->change_state(this->_pins[0]->get_state());
}

void Clock::dump() const
{
            std::cout << "Clock component" << std::endl;
            std::cout << "1 pin\n" << std::endl;
}