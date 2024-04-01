/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Pin
*/

#include "../include/Pins.hpp"

Pin::Pin()
{
    _state = nts::Tristate::UNDEFINED;
}

void Pin::change_state(nts::Tristate state)
{
    this->_state = state;
}

nts::Tristate Pin::get_state()
{
    return (this->_state);
}

void Pin::simulate(size_t tick)
{
}

void Pin::createLink(nts::IComponent *component, size_t pin)
{
}

// PIN LINK

PinLink::PinLink(nts::IComponent *component, size_t pin)
{
    _component_link = component;
    _pin_link = pin;
}

nts::IComponent *PinLink::get_component_link()
{
    return (this->_component_link);
}

size_t PinLink::get_pin_link()
{
    return (this->_pin_link);
}

// INPUT

InputPin::InputPin(): Pin()
{
    _link = nullptr;
}

void InputPin::createLink(nts::IComponent *component, size_t pin)
{
    if (this->_link)
        this->_link->~OutputPin();
    this->_link = new OutputPin();
    this->_link->createLink(component, pin);
}

void InputPin::simulate(size_t tick)
{
    if (!this->_link)
        return;
    this->_link->simulate(tick);
    this->_state = this->_link->get_state();
}

// OUTPUT

OutputPin::OutputPin(): Pin()
{
    _link = nullptr;
}

void OutputPin::createLink(nts::IComponent *component, size_t pin)
{
    if (this->_link)
        this->_link->~PinLink();
    this->_link = new PinLink(component, pin);
}

void OutputPin::simulate(size_t tick)
{
    this->_link->get_component_link()->simulate(tick);
    this->_state = this->_link->get_component_link()->compute(this->_link->get_pin_link());
}
