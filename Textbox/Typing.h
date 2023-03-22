//
// Created by joseg on 3/2/2023.
//

#ifndef CS8_WEEK8_TYPINGINSFML_TYPING_H
#define CS8_WEEK8_TYPINGINSFML_TYPING_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include <string>
#include "MultiText.h"

class Typing : public sf::Drawable
{
private:
    // holds all text typed in window
    MultiText text;
public:
    Typing();


    // This function should be in the pollEvent loop and is used to detect when a key is pressed on the keyboard
    // and concatenates the character to the sf::Text object
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    // This function should be called outside of the pollEvent loop and is used for updates,
    // if any, needed after an event is handled and before the object is drawn on the screen
    void update();

    //This function is to draw your text
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //CS8_WEEK8_TYPINGINSFML_TYPING_H
