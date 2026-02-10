/*
** EPITECH PROJECT, 2026
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#ifndef INCLUDED_CIRCUIT_HPP
    #define INCLUDED_CIRCUIT_HPP

#include <csignal>
#include <iostream>
#include <memory>
#include <utility>
#include "AComponent.hpp"
#include "IComponent.hpp"

class Circuit {
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> components;
    public:
        void addComponent(std::string name, std::unique_ptr<nts::IComponent> c)
        {
            components[name] = std::move(c); //uniqueptr can only be moved not copied
        }
        std::unique_ptr<nts::IComponent> &getComponent(std::string const &name)
        {
            if (components.count(name) == 0)
                raise(3);
            return components[name];
        }

        void simulate(std::size_t tick) {
            for (auto &c : components)
                c.second->simulate(tick);
        }

        //void display();

};


#endif
