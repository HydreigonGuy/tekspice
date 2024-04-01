/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** Ctrue
*/

#include "../include/Ctrue.hpp"
#include "../include/operations.hpp"
#include "../include/Exceptions.hpp"

#include <iostream>

Ctrue::Ctrue()  : Component()
{
    this->_pins.insert(std::pair<size_t, Pin *> (1, new Pin()));
    this->_pins[1]->change_state(nts::Tristate::TRUE);
}

Ctrue::~Ctrue()
{
}

void Ctrue::simulate(size_t tick)
{
}

void Ctrue::changePinState(size_t pin, nts::Tristate state)
{
    if (this->getPin(pin) == NULL)
        throw (Exceptions::UnexistingPin());
}

void Ctrue::dump() const
{
            std::cout << "True component" << std::endl;
            std::cout << "1 pin\n" << std::endl;
}