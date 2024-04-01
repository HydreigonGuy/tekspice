/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** operations
*/

#include "../include/operations.hpp"

nts::Tristate myNOR(nts::Tristate s1, nts::Tristate s2)
{
    if (s1 == nts::Tristate::TRUE || s2 == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    if (s1 == nts::Tristate::UNDEFINED || s2 == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}

nts::Tristate myNAND(nts::Tristate s1, nts::Tristate s2)
{
    if (s1 == nts::Tristate::FALSE || s2 == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    if (s1 == nts::Tristate::UNDEFINED || s2 == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::FALSE);
}

nts::Tristate myXOR(nts::Tristate s1, nts::Tristate s2)
{
    if (s1 == nts::Tristate::UNDEFINED || s2 == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    if ((s1 == nts::Tristate::FALSE && s2 == nts::Tristate::FALSE) || (s1 == nts::Tristate::TRUE && s2 == nts::Tristate::TRUE))
        return (nts::Tristate::FALSE);
    return (nts::Tristate::TRUE);
}

nts::Tristate myOR(nts::Tristate s1, nts::Tristate s2)
{
    if (s1 == nts::Tristate::TRUE || s2 == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    if (s1 == nts::Tristate::UNDEFINED || s2 == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::FALSE);
}

nts::Tristate myAND(nts::Tristate s1, nts::Tristate s2)
{
    if (s1 == nts::Tristate::FALSE || s2 == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    if (s1 == nts::Tristate::UNDEFINED || s2 == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}

nts::Tristate myINVERTER(nts::Tristate s1)
{
    if (s1 == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    if (s1 == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::UNDEFINED);
}

void myAdd(nts::Tristate s1, nts::Tristate s2, nts::Tristate s3, Pin *p1, Pin *p2)
{
    char c = 0;
    char u = 0;

    if (s1 == nts::Tristate::TRUE)
        c++;
    if (s2 == nts::Tristate::TRUE)
        c++;
    if (s3 == nts::Tristate::TRUE)
        c++;
    if (s1 == nts::Tristate::UNDEFINED)
        u++;
    if (s2 == nts::Tristate::UNDEFINED)
        u++;
    if (s3 == nts::Tristate::UNDEFINED)
        u++;
    if (c >=2)
        p2->change_state(nts::Tristate::TRUE);
    else if (c + u >= 2)
        p2->change_state(nts::Tristate::UNDEFINED);
    else
        p2->change_state(nts::Tristate::FALSE);
    if (u != 0)
        p1->change_state(nts::Tristate::UNDEFINED);
    else if (c % 2 == 1)
        p1->change_state(nts::Tristate::TRUE);
    else
        p1->change_state(nts::Tristate::FALSE);
}