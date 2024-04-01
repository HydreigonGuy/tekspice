/*
** EPITECH PROJECT, 2022
** B-OOP-400-TLS-4-1-tekspice-roxane.baert
** File description:
** C4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "Component.hpp"

class C4071: public Component {
    public:
        C4071();
        ~C4071();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4071_HPP_ */
