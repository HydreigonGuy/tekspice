/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "Component.hpp"

class C4011: public Component {
    public:
        C4011();
        ~C4011();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4011_HPP_ */
