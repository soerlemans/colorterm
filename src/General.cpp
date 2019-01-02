#include "General.h"

std::string uint2string(uint8_t uint)
{
    //uint8_t isnt really an int
    //so it must be converted to int

    std::ostringstream oss;
    oss << int{uint};

    return oss.str();
}
