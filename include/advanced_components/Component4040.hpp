/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4040
*/

#ifndef INCLUDED_COMPONENT4040_HPP
#define INCLUDED_COMPONENT4040_HPP

#include "AComponent.hpp"
#include <cstdint>

namespace nts {

class Component4040 : public virtual AComponent {
private:
    uint16_t _counter = 0;
    Tristate _lastClock = False;

public:
    Component4040();
    void simulate(size_t tick) override;
    Tristate compute(size_t pin) override;
};

}

#endif
