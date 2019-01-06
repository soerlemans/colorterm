#include "Colors.h"

//not my code
//gets the underlying value
//from a an enum class
template<typename E>
constexpr auto to_integral(E e) -> typename std::underlying_type<E>::type
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

uint8_t operator&(Format t_lval, Format t_rval)
{

    auto   u_lval = to_integral(t_lval);
    auto   u_rval = to_integral(t_rval);

    return u_lval & u_rval;
}

uint8_t operator|(Format t_lval, Format t_rval)
{

    auto   u_lval = to_integral(t_lval);
    auto   u_rval = to_integral(t_rval);

    return u_lval | u_rval;
}
