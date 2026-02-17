/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4081
*/

/*
#           +---------4081---------+
# in_01  -1-|>-+---\       ignored-|-14-
#           |  | &  |-+            |
# in_02  -2-|>-+---/  |     /---+-<|-13- in_13
#           |         |  +-|  & |  |
# out_03 -3-|<--------+  |  \---+-<|-12- in_12
#           |            |         |
# out_04 -4-|<--------+  +-------->|-11- out_11
#           |         |            |
# in_05  -5-|>-+---\  |  +-------->|-10- out_10
#           |  | &  |-+  |         |
# in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
#           |            +-|  & |  |
#        -7-|-ignored       \---+-<|-8-  in_08
#           +----------------------+
*/



#include "Component4081.hpp"
#include "AGateComponent.hpp"
#include "AndComponent.hpp"

static std::unique_ptr<nts::AndComponent> make_func()
{
    return std::make_unique<nts::AndComponent>();
}

nts::Component4081::Component4081() : nts::AGateComponent({
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
