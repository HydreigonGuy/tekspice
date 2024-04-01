/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Pins
*/

#ifndef PINS_HPP_
#define PINS_HPP_

#include "IComponent.hpp"

#include <list>

class PinLink
{
    private:
        nts::IComponent *_component_link;
        size_t _pin_link;
    public:
        PinLink(nts::IComponent *, size_t);
        ~PinLink() = default;
        nts::IComponent *get_component_link();
        size_t get_pin_link();
};

class Pin
{
    protected:
        nts::Tristate _state;
    public:
        Pin();
        virtual ~Pin() = default;
        void change_state(nts::Tristate);
        nts::Tristate get_state();
        virtual void createLink(nts::IComponent *component, size_t pin);
        virtual void simulate(size_t tick);
};

class OutputPin;

class InputPin: public Pin
{
    public:
        InputPin();
        ~InputPin() = default;
        void createLink(nts::IComponent *component, size_t pin) override;
        void simulate(size_t tick) override;
    private:
        OutputPin *_link;
};

class OutputPin: public Pin
{
    public:
        OutputPin();
        ~OutputPin() = default;
        void createLink(nts::IComponent *component, size_t pin) override;
        void simulate(size_t tick) override;
    private:
        PinLink *_link;
};

#endif /* !PINS_HPP_ */
