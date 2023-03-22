//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_EVENTHANDLER_H
#define TEXTBOXPROJECT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler
{
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

};


#endif //TEXTBOXPROJECT_EVENTHANDLER_H
