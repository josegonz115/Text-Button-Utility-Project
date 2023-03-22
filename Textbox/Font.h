
#ifndef CS8_SPRING23_SFML_CALCULATOR_FONT_H
#define CS8_SPRING23_SFML_CALCULATOR_FONT_H
#include <SFML/Graphics.hpp>

class Font
{
private:
    static sf::Font font;
    static void loadFont();
public:

    static sf::Font& getFont();
};



#endif //CS8_SPRING23_SFML_CALCULATOR_FONT_H
