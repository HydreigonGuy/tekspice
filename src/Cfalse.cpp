/*
** EPITECH PROJECT, 2022
** En_cour
** File description:
** Cfalse
*/

#include "../include/Cfalse.hpp"
#include "../include/operations.hpp"
#include "../include/Exceptions.hpp"

#include <iostream>

Cfalse::Cfalse()  : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (1, new Pin()));
    this->_pins[1]->change_state(nts::Tristate::FALSE);
}

Cfalse::~Cfalse()
{
}

void Cfalse::simulate(size_t tick)
{
}

void Cfalse::changePinState(size_t pin, nts::Tristate state)
{
    if (this->getPin(pin) == NULL)
        throw (Exceptions::UnexistingPin());
}

void Cfalse::dump() const
{
            std::cout << "False component" << std::endl;
            std::cout << "1 pin\n" << std::endl;
}