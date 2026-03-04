/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4040
*/

#include "Component4040.hpp"
#include "IComponent.hpp"
#include <cstdio>

/*
# 12-bits Binary Counter (4040)
#
#      cl_clock -10-+     +-11- in_reset
#                   |     |
#    +------4040----v-----v--------------+
# -8-|-ign   12-bit Binary Counter   ign-|-16-
#    +------v-v-v-v-v-v-v-v-v-v-v-v------+
#           | | | | | | | | | | | |
# out_00 -9-+ | | | | | | | | | | +-1- out_11
#   out_01 -7-+ | | | | | | | | +-15- out_10
#     out_02 -6-+ | | | | | | +-14- out_09
#       out_03 -5-+ | | | | +-12- out_08
#         out_04 -3-+ | | +-13- out_07
#           out_05 -2-+ +-4- out_06

*/

nts::Component4040::Component4040()
{
    component_links = {
        {1, OutputType}, //out_11
        {2, OutputType}, //out_05
        {3, OutputType}, //out_04
        {4, OutputType}, //out_06
        {5, OutputType}, //out_03
        {6, OutputType}, //out_02
        {7, OutputType}, //out_01
        {8, UndefinedType}, //ignored
        {9, OutputType}, //out_00
        {10, InputType}, //cl_clock
        {11, InputType}, //in_reset
        {12, OutputType},//out_08
        {13, OutputType}, //out_07
        {14, OutputType}, //out_09
        {15, OutputType}, //out_10
        {16, UndefinedType} //ignored
    };
}

void nts::Component4040::simulate(size_t tick)
{
    //we need to update the counter on the rising edge of the clock, but we also need to update the outputs on every tick since they depend on the counter value
    compute(0); //this will update the outputs based on the current counter value
}


nts::Tristate nts::Component4040::compute(size_t pin) //this is causing a stack
{
    nts::Tristate clock = getLink(10);
    nts::Tristate reset = getLink(11);

    if (reset == nts::Tristate::True) {
        counter = 0;
        if (get_type(size_t(pin)) == OutputType)
            return nts::Tristate::False;
        return nts::Tristate::Undefined;
    }
    //on rising edge of clock, no change
    //on falling edge increment counter
    if (clock == nts::Tristate::False && last_clock == nts::Tristate::True) {
        counter = (counter + 1) % 4096; // 12 bits counter
    }
    //printf("counter = %zu\n", counter);
    last_clock = clock;

    int bit = -1;

    switch (pin) {
        case 9:  bit = 0; break;
        case 7:  bit = 1; break;
        case 6:  bit = 2; break;
        case 5:  bit = 3; break;
        case 3:  bit = 4; break;
        case 2:  bit = 5; break;
        case 4:  bit = 6; break;
        case 13: bit = 7; break;
        case 12: bit = 8; break;
        case 14: bit = 9; break;
        case 15: bit = 10; break;
        case 1:  bit = 11; break;
    }

    if (bit != -1)
        return (counter & (1 << bit)) ? nts::Tristate::True : nts::Tristate::False;
    return nts::Tristate::Undefined;
}