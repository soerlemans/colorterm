#ifndef FORMAT_H
#define FORMAT_H

#include <type_traits>

#include "General.h"

//for terminals that support 255 colors you can give a

//the sources for these are found here
//https://misc.flogisoft.com/bash/tip_colors_and_formatting#terminals_compatibility

//set and reset the format options
enum class Format : uint8_t
{

    Bold_Bright = 1,
    Dim         = 1 << 1,
    Underlined  = 1 << 2,
    Blink       = 1 << 3,
    Reverse     = 1 << 4,
    Hidden      = 1 << 5

};

template<typename E>
constexpr auto to_integral(E e) -> typename std::underlying_type<E>::type;

extern uint8_t operator&(Format t_lval, Format t_rval);
extern uint8_t operator|(Format t_lval, Format t_rval);

#endif // FORMAT_H
