/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4514
*/

#ifndef INCLUDED_COMPONENT4514_HPP
#define INCLUDED_COMPONENT4514_HPP

#include "AComponent.hpp"

namespace nts {

class Component4514 : public virtual AComponent {
private:
    Tristate _lastStrobe = False;
    Tristate _A = Undefined;
    Tristate _B = Undefined;
    Tristate _C = Undefined;
    Tristate _D = Undefined;

public:
    Component4514();
    void simulate(size_t tick) override;
    Tristate compute(size_t pin) override;
};

}

#endif
