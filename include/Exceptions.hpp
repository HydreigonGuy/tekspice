/*
** EPITECH PROJECT, 2022
** nanoteckspice
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>

namespace Exceptions
{
    class Arguments : public std::exception
    {
    public:
        Arguments()
        {
        }
        ~Arguments() = default; 
        const char* what() const noexcept override
        {
            return ("Incorrect arguments!\nUsage: ./nanotekspice filename");
        }
    };

    class FileOpen : public std::exception
    {
    public:
        FileOpen()
        {
        }
        ~FileOpen() = default; 
        const char* what() const noexcept override
        {
            return ("Could not open file!");
        }
    };

    class Components : public std::exception
    {
    public:
        Components()
        {
        }
        ~Components() = default; 
        const char* what() const noexcept override
        {
            return ("Failed to create components from file!");
        }
    };

    class Command : public std::exception
    {
    public:
        Command()
        {
        }
        ~Command() = default; 
        const char* what() const noexcept override
        {
            return ("Invalid command!\nValid commands are: display, simulate, loop, dump, (component name)=(state), and exit");
        }
    };

    class UnexistingComponent : public std::exception
    {
    public:
        UnexistingComponent()
        {
        }
        ~UnexistingComponent() = default; 
        const char* what() const noexcept override
        {
            return ("Component doesn't exist!");
        }
    };

    class UnexistingPin : public std::exception
    {
    public:
        UnexistingPin()
        {
        }
        ~UnexistingPin() = default; 
        const char* what() const noexcept override
        {
            return ("Pin doesn't exist!");
        }
    };

    class NotInput : public std::exception
    {
    public:
        NotInput()
        {
        }
        ~NotInput() = default; 
        const char* what() const noexcept override
        {
            return ("Component isn't Input or Clock!");
        }
    };
}


#endif /* !EXCEPTIONS_HPP_ */
