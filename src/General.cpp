#include "General.h"

std::string uint2string(uint8_t uint)
{
    //uint8_t isnt really treated as an int
    //so it must be converted to int

    ostringstream oss;
    oss << int{uint};

    return oss.str();
}

template<typename T>
string to_string(T val){

    ostringstream oss;
    oss << val;

    return oss.str();
}
