/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** Ctrue
*/

#ifndef CTRUE_HPP_
#define CTRUE_HPP_

#include "Component.hpp"

class Ctrue: public Component {
    public:
        Ctrue();
        ~Ctrue();
        virtual void simulate(size_t tick) override;
        virtual void changePinState(size_t pin, nts::Tristate state)override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !CTRUE_HPP_ */
