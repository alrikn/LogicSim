/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4512
*/

#ifndef INCLUDED_COMPONENT4512_HPP
    #define INCLUDED_COMPONENT4512_HPP

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {


class Component4512 : public virtual AComponent
{
    private:
    protected:
    public:
        Component4512();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
