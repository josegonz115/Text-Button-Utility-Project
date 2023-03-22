#include "Font.h"

sf::Font Font::font;

void Font::loadFont()
{
    font.loadFromFile("Textbox\\fonts\\OpenSans-Bold.ttf");
    //font.loadFromFile("C:\\Users\\joseg\\OneDrive\\Documents\\PCC\\CS-8\\cs8week9\\textboxProject\\Textbox\\fonts\\OpenSans-Bold.ttf");
}

sf::Font &Font::getFont()
{
    loadFont();
    return font;
}

