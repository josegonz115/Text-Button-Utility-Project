//
// Created by joseg on 3/3/2023.
//

#include "Letter.h"

Letter::Letter(){}

Letter::Letter(char letter, sf::Font& font, sf::Vector2f position, sf::Color color, unsigned int charSize){
    setString(letter);
    setFont(font);
    setPosition(position);
    setFillColor(color);
    setCharacterSize(charSize);
}