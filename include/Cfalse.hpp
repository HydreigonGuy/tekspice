/*
** EPITECH PROJECT, 2022
** En_cour
** File description:
** Cfalse
*/

#ifndef CFALSE_HPP_
#define CFALSE_HPP_

#include "Component.hpp"

class Cfalse: public Component {
    public:
        Cfalse();
        ~Cfalse();
        virtual void simulate(size_t tick) override;
        virtual void changePinState(size_t pin, nts::Tristate state)override;
        virtual void dump() const override;

    protected:
    private:
};

#endif /* !CFALSE_HPP_ */
