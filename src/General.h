#ifndef GENERAL_H
#define GENERAL_H

#include <sstream>
#include <string>
#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
#   define WINDOWS
#elif defined(__APPLE__)
#   define MACOS
#elif defined(__unix__) || defined(__unix)
#   define LINUX
#else
#   error unsupported platform
#endif

#if defined(LINUX) || defined(MACOS)
#   include <unistd.h>
#elif defined(WINDOWS)
#   include <io.h>
#   include <windows.h>
#   define WINVER 0xA00
#endif

//#define _WIN32_WINNT_WIN10 0x0A00
//#define NTDDI_WIN10 0x0A00

//Disclaimer this project was heavily inspired
//on termcolor from: https://github.com/ikalnytskyi/termcolor
//i just thought it could be done better

//get rid of as many std:: as possible
//without using namespace std
using string        = std::string;
using ostream       = std::ostream;
using ostringstream = std::ostringstream;

extern string uint2string(uint8_t uint);

template<typename T>
extern string to_string(T val);

//only if the platform supports
//ANSI escape codes
#if defined(WINVER) || defined(LINUX) || defined(MACOS)

//contains the ANSI / ASCII control sequences
namespace ControlSeq
{

const string terminate {"m"};
const string escape {"\e["};

const string reset {escape + '0' + terminate};

const string foreground {escape + "38;5;"};
const string background {escape + "48;5;"};

};


inline std::string Syntax(unsigned int val)
{

    std::ostringstream oss;
    oss << ControlSeq::escape << val << ControlSeq::terminate;

    return oss.str();
}

namespace Formatterm
{

const string

Bold_Bright {Syntax(1)},
            Dim         {Syntax(2)},
            Underlined  {Syntax(4)},
            Blink       {Syntax(5)},
            Reverse     {Syntax(7)},
            Hidden      {Syntax(8)};

};

//all the 16 bit color options
namespace Colorterm16
{

//TODO wrap this in a class
//cause the difference in the FG and BG
//is always 10 so it can easily be tidied up
//but know i think off it this wont change much

namespace FG  //for the foreground colors
{
const string
Default {Syntax(39)},
        Black   {Syntax(30)},
        Red     {Syntax(31)},
        Green   {Syntax(32)},
        Yellow  {Syntax(33)},
        Blue    {Syntax(34)},
        Magenta {Syntax(35)},
        Cyan    {Syntax(36)},

        LightGray    {Syntax(37)},
        DarkGray     {Syntax(90)},
        LightRed     {Syntax(91)},
        LightGreen   {Syntax(92)},
        LigthYellow  {Syntax(93)},
        LightBlue    {Syntax(94)},
        LightMagneta {Syntax(95)},
        LightCyan    {Syntax(96)},

        White {Syntax(97)};
};

namespace BG  //for the background colors colors
{
const string
Default {Syntax(49)},
        Black   {Syntax(40)},
        Red     {Syntax(41)},
        Green   {Syntax(42)},
        Yellow  {Syntax(43)},
        Blue    {Syntax(44)},
        Magenta {Syntax(45)},
        Cyan    {Syntax(46)},

        LightGray    {Syntax(47)},
        DarkGray     {Syntax(100)},
        LightRed     {Syntax(101)},
        LightGreen   {Syntax(102)},
        LigthYellow  {Syntax(103)},
        LightBlue    {Syntax(104)},
        LightMagneta {Syntax(105)},
        LightCyan    {Syntax(106)},

        White {Syntax(107)};
};
};

//if its a window version lower than 10
//so if it doesnt have ANSI escape codes
//initialize all strings to zero
#else

namespace ControlSeq
{

const string terminate;
const string escape;

const string reset;

const string foreground;
const string background;

};

namespace Formatterm
{

const string

Bold_Bright,
Dim,
Underlined,
Blink,
Reverse,
Hidden;

};

//all the 16 bit color options
namespace Colorterm16
{

//TODO wrap this in a class
//cause the difference in the FG and BG
//is always 10 so it can easily be tidied up
//but know i think off it this wont change much

namespace FG  //for the foreground colors
{
const string
Default,
Black,
Red,
Green,
Yellow,
Blue,
Magenta,
Cyan,

LightGray,
DarkGray,
LightRed,
LightGreen,
LigthYellow,
LightBlue,
LightMagneta,
LightCyan,

White;
};

namespace BG  //for the background colors colors
{
const string
Default,
Black,
Red,
Green,
Yellow,
Blue,
Magenta,
Cyan,

LightGray,
DarkGray,
LightRed,
LightGreen,
LigthYellow,
LightBlue,
LightMagneta,
LightCyan,

White;
};
};

#endif

#endif // GENERAL_H
