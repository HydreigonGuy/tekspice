/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "Pins.hpp"

#include <map>
#include <string>

    class Component: public nts::IComponent {
        public:
            Component();
            virtual ~Component();
            virtual void simulate(size_t tick);
            virtual nts::Tristate compute(size_t pin);
            virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
            virtual void dump() const;
            virtual void changePinState(size_t pin, nts::Tristate state);
            Pin *getPin(size_t pin);

        protected:
            std::map<size_t, Pin *> _pins;
            nts::Tristate _simulating;
            size_t _restimulate;
    };

#endif /* !COMPONENT_HPP_ */
