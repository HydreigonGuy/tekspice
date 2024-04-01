/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "Component.hpp"

class C4081: public Component {
    public:
        C4081();
        ~C4081();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4081_HPP_ */
