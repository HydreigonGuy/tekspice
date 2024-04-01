/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** main
*/

#include "../include/Brain.hpp"
#include "../include/Exceptions.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int ac, char **av)
{
    Brain brain;

    try {
        if (ac != 2)
            throw (Exceptions::Arguments());
        brain.fill_commponents(av[1]);
        brain.handleStandardInput();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (84);
    }
}