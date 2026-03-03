/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** operator
*/

#include "IComponent.hpp"
namespace nts {


//and
nts::Tristate operator&(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::False || b == nts::False)
        return nts::False;
    if (a == nts::Undefined || b == nts::Undefined)
        return nts::Undefined;
    return nts::True;
}

//or
nts::Tristate operator|(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::True || b == nts::True)
        return nts::True;
    if (a == nts::Undefined || b == nts::Undefined)
        return nts::Undefined;
    return nts::False;
}

//xor
nts::Tristate operator^(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Undefined || b == nts::Undefined)
        return nts::Undefined;
    if (a == b)
        return nts::False;
    return nts::True;
}

//not
nts::Tristate operator!(nts::Tristate a)
{
    if (a == nts::Undefined)
        return nts::Undefined;
    if (a == nts::True)
        return nts::False;
    return nts::True;
}
}
