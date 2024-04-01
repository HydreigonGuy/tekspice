/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Component
*/

#include "../include/Component.hpp"
#include "../include/Exceptions.hpp"

#include <iostream>

Component::Component()
{
    _simulating = nts::Tristate::FALSE;
    _restimulate = 0;
}

Component::~Component()
{
}

void Component::simulate(size_t tick)
{
    if (this->_simulating)
        return;
    this->_simulating = nts::Tristate::TRUE;
    for (std::pair<size_t, Pin *> curr : this->_pins)
        curr.second->simulate(tick);
    this->_simulating = nts::Tristate::FALSE;
}

Pin *Component::getPin(size_t pin)
{
    try
    {
        return this->_pins.at(pin);
    }
    catch(const std::exception &e)
    {
        std::cerr << "Out of bounds pin!" << std::endl;
        return (NULL);
    }
}

nts::Tristate Component::compute(size_t pin)
{
    if (this->getPin(pin) != NULL)
        return (this->_pins[pin]->get_state());
    return (nts::UNDEFINED);
}

void Component::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (this->getPin(pin) == NULL)
        throw (Exceptions::Components());
    this->_pins[pin]->createLink(&other, otherPin);
    this->simulate(0);
}

void Component::dump() const
{
}

void Component::changePinState(size_t pin, nts::Tristate state)
{
    if (this->getPin(pin) != NULL)
        this->_pins[pin]->change_state(state);
    else
        throw (Exceptions::UnexistingPin());
}