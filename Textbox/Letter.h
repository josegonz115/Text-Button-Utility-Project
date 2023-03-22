//
// Created by joseg on 3/3/2023.
//

#ifndef MULTITEXT_LETTER_H
#define MULTITEXT_LETTER_H
#include <SFML/Graphics.hpp>
#include "Font.h"
class Letter : public sf::Text
{
public:
    Letter();
    Letter(char letter, sf::Font& font, sf::Vector2f position, sf::Color color, unsigned int charSize);
};


#endif //MULTITEXT_LETTER_H
