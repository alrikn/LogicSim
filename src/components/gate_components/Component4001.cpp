/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4001
*/


#include "Component4001.hpp"
#include "AGateComponent.hpp"
#include "NorComponent.hpp"

/*
# NOR logic gates (4001)
#
#           +----------4001----------+
# in_01  -1-|>-+---\         ignored-|-14-
#           |  | or |o-+             |
# in_02  -2-|>-+---/   |      /---+-<|-13- in_13
#           |          |  +-o| or |  |
# out_03 -3-|<---------+   |  \---+-<|-12- in_12
#           |              |         |
# out_04 -4-|<---------+  +--------->|-11- out_11
#           |          |             |
# in_05  -5-|>-+---\   |  +--------->|-10- out_10
#           |  | or |o-+  |          |
# in_06  -6-|>-+---/      |   /---+-<|-9-  in_09
#           |             +-o| or |  |
#        -7-|-ignored         \---+-<|-8-  in_08
#           +-------------------
*/

static std::unique_ptr<nts::NorComponent> make_func()
{
    return std::make_unique<nts::NorComponent>();
}

nts::Component4001::Component4001() : nts::AGateComponent({
                    {{1,2},  3, 3},
                    {{5,6},  4, 3},
                    {{13,12}, 11, 3},
                    {{9, 8},  10, 3},
                },
                make_func
            )
{
    //i could put this entire thing in hpp but then it would be inconsistent
}

