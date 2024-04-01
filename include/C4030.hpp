/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "Component.hpp"

class C4030: public Component {
    public:
        C4030();
        ~C4030();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4030_HPP_ */
