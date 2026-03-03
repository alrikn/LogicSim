/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component2716
*/

#ifndef INCLUDED_COMPONENT2716_HPP
#define INCLUDED_COMPONENT2716_HPP

#include "AComponent.hpp"
#include <vector>
#include <cstdint>
namespace nts {

class Component2716 : public virtual AComponent {
private:
    uint8_t _rom[2048];

    int computeAddress();

public:
    Component2716();
    void simulate(size_t tick) override;
    Tristate compute(size_t pin) override;
};

}

#endif
