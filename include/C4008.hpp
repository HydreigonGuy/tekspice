/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "Component.hpp"

class C4008: public Component {
    public:
        C4008();
        ~C4008();
        virtual void simulate(size_t tick) override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !C4008_HPP_ */
