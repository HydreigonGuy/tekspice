/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(size_t tick) = 0;
            virtual nts::Tristate compute(size_t pin) = 0;
            virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual void changePinState(size_t pin, nts::Tristate state) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
