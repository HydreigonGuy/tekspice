/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** operations
*/

#ifndef OPERATIONS_HPP_
#define OPERATIONS_HPP_

#include "IComponent.hpp"
#include "../include/Pins.hpp"

nts::Tristate myNOR(nts::Tristate s1, nts::Tristate s2);
nts::Tristate myNAND(nts::Tristate s1, nts::Tristate s2);
nts::Tristate myXOR(nts::Tristate s1, nts::Tristate s2);
nts::Tristate myOR(nts::Tristate s1, nts::Tristate s2);
nts::Tristate myAND(nts::Tristate s1, nts::Tristate s2);
nts::Tristate myINVERTER(nts::Tristate s1);
void myAdd(nts::Tristate s1, nts::Tristate s2, nts::Tristate s3, Pin *p1, Pin *p2);

#endif /* !OPERATIONS_HPP_ */
