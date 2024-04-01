/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Component.hpp"

#include <iostream>

class Input: public Component {
    public:
        Input()
        {
            this->_pins.insert(std::pair<size_t, Pin *> (1, new Pin()));
            this->_pins.insert(std::pair<size_t, Pin *> (0, new Pin()));
        }
        ~Input() = default;
        virtual void simulate(size_t tick) override
        {
            this->_pins[1]->change_state(this->_pins[0]->get_state());
        }
        virtual void dump() const override
        {
            std::cout << "Input component" << std::endl;
            std::cout << "1 pin\n" << std::endl;
        }

    protected:
    private:
};

#endif /* !INPUT_HPP_ */
