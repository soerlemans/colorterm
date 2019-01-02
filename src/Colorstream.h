#ifndef COLORSTREAM_H
#define COLORSTREAM_H

#include <iostream>

#include "Format.h"

using namespace ControlSeq;
using namespace Colorterm16;

class Colorstream
{
private:
    ostream& m_stream = std::cout;
    string m_term_set = "";

public:
    Colorstream(ostream& t_stream, const string  t_color_fg, const string  t_color_bg, const Format  t_flags);
    Colorstream(ostream& t_stream, const uint8_t t_color_fg, const uint8_t t_color_bg, const Format  t_flags);

    Colorstream(ostream& t_stream, const string  t_color_fg, const string  t_color_bg, const uint8_t t_flags);
    Colorstream(ostream& t_stream, const uint8_t t_color_fg, const uint8_t t_color_bg, const uint8_t t_flags);

    void SetFormat(const Format  t_flags);
    void SetFormat(const uint8_t t_flags);

    void SetColor16 (string  t_color_fg = FG::Default,  string  t_color_bg =BG::Default );
    void SetColor255(uint8_t t_color_fg = 0, uint8_t t_color_bg = 0);

    void Clear();

    ~Colorstream();

    std::ostream& operator<<(string str);

};

#endif // COLORSTREAM_H
