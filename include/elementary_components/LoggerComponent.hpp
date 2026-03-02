/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Logger
*/

#ifndef INCLUDED_LOGGER_HPP
    #define INCLUDED_LOGGER_HPP

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {


class LoggerComponent : public virtual AComponent
{
    private:
        nts::Tristate _lastClock = nts::False;
    protected:
    public:
        LoggerComponent();
        void simulate(size_t tick) override;
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}

#endif
