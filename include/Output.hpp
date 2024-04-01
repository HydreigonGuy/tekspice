/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "Component.hpp"

class Output: public Component {
    public:
        Output()
        {
            this->_pins.insert(std::pair<size_t, Pin *> (1, new InputPin()));
        }
        ~Output() = default;
        virtual void dump() const override
        {
            std::cout << "Output component" << std::endl;
            std::cout << "1 pin\n" << std::endl;
        }

    protected:
    private:
};

#endif /* !OUTPUT_HPP_ */
