#include "Format.h"
#include "Colorstream.h"

int main()
{
    std::ostream& os = std::cout;
    uint8_t ut = 82;
    uint8_t ut2 = 196;

    Colorstream stream(os, ut, ut2, Format::Underlined | Format::Blink);
    Colorstream stream2(os, Colorterm16::FG::Red, Colorterm16::BG::Blue, Format::Bold_Bright | Format::Blink);
    Colorstream stream3(os, Colorterm16::FG::Green, Colorterm16::BG::Magenta, Format::Bold_Bright);
    Colorstream stream4(os, 254, 243, Format::Reverse);

    stream << "ice is nice \n";
    std::cout << "ice is nice \n";
    stream2 << "ice is very nice \n";
    stream3 << "the more ice the more nice\n";
    stream4 << "future is now " << 1 << " more ice \n";
    stream4 << 1 << " more ice \n" << 3.45 << "\n\n";

    stream << 'l' << 'u' << 'a' << '\n';
    stream2 << 'l' << 'i' << 's' << 'p' << '\n';

    return 0;
}
