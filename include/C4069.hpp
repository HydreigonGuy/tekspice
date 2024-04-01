/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "Component.hpp"

class C4069: public Component {
    public:
        C4069();
        ~C4069();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4069_HPP_ */
