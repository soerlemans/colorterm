#include "Colorstream.h"

Colorstream::Colorstream(ostream& t_stream, const string t_color_fg, const string t_color_bg, Format t_flags)
    :m_stream(t_stream)
{
    SetFormat(t_flags); std::cout << "yes2";
    SetColor16(t_color_fg, t_color_bg);
}

Colorstream::Colorstream(ostream& t_stream, const uint8_t  t_color_fg, const uint8_t  t_color_bg, Format t_flags)
    :m_stream(t_stream)
{
    SetFormat(t_flags);
    SetColor255(t_color_fg, t_color_bg);
}

Colorstream::Colorstream(ostream& t_stream, const string t_color_fg, const string t_color_bg, uint8_t t_flags)
    :m_stream(t_stream)
{
    SetFormat(t_flags); std::cout << "yes1";
    SetColor16(t_color_fg, t_color_bg);
}

Colorstream::Colorstream(ostream& t_stream, const uint8_t  t_color_fg, const uint8_t  t_color_bg, uint8_t t_flags)
    :m_stream(t_stream)
{
    SetFormat(t_flags);
    SetColor255(t_color_fg, t_color_bg);
}

void Colorstream::SetFormat(const Format t_flags)
{

    if(t_flags & Format::Bold_Bright)
        m_term_set += Formatterm::Bold_Bright;

    if(t_flags & Format::Dim)
        m_term_set += Formatterm::Dim;

    if(t_flags & Format::Underlined)
        m_term_set += Formatterm::Underlined;

    if(t_flags & Format::Blink)
        m_term_set += Formatterm::Blink;

    if(t_flags & Format::Reverse)
        m_term_set += Formatterm::Reverse;

    if(t_flags & Format::Hidden)
        m_term_set += Formatterm::Hidden;

}

void Colorstream::SetFormat(const uint8_t t_flags)
{

    if(t_flags & to_integral(Format::Bold_Bright))
        m_term_set += Formatterm::Bold_Bright;

    if(t_flags & to_integral(Format::Dim))
        m_term_set += Formatterm::Dim;

    if(t_flags & to_integral(Format::Underlined))
        m_term_set += Formatterm::Underlined;

    if(t_flags & to_integral(Format::Blink))
        m_term_set += Formatterm::Blink;

    if(t_flags & to_integral(Format::Reverse))
        m_term_set += Formatterm::Reverse;

    if(t_flags & to_integral(Format::Hidden))
        m_term_set += Formatterm::Hidden;

}

void Colorstream::SetColor16(string t_color_fg, string t_color_bg)
{
    m_term_set += t_color_fg;
    m_term_set += t_color_bg;
}

void Colorstream::SetColor255(uint8_t t_color_fg, uint8_t t_color_bg)
{
    m_term_set  = foreground + uint2string(t_color_fg) + terminate;
    m_term_set += background + uint2string(t_color_bg) + terminate;
}

void Colorstream::Clear()
{
    //reset all options
    m_term_set.clear();
}

Colorstream::~Colorstream()
{

}

std::ostream& Colorstream::operator<<(string str)
{
    m_stream << m_term_set << str << reset;

    return m_stream;
}
