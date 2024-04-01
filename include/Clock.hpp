/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Component.hpp"

class Clock: public Component {
    public:
        Clock();
        ~Clock();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !CLOCK_HPP_ */
