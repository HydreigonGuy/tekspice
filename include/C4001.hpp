/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "Component.hpp"

class C4001: public Component {
    public:
        C4001();
        ~C4001();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4001_HPP_ */
