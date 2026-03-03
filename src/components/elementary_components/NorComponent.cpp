/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** NorComponent
*/

#include "NorComponent.hpp"
#include "Circuit.hpp"

nts::NorComponent::NorComponent()
{
    component_links = {
        {1, InputType},
        {2, InputType},
        {3, OutputType},
    };
}

nts :: Tristate nts::NorComponent::compute ( std :: size_t pin )
{
    if (pin != 3) //the return pin
        return Undefined;
    auto a = getLink(1);
    auto b = getLink(2);

    return !(a | b);
}
