//
// Created by joseg on 3/18/2023.
//
#ifndef TEXTBOXPROJECT_MOUSEEVENTS_CPP
#define TEXTBOXPROJECT_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window, sf::Event event)
{
    bool hover = object.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    if(hover){
        return mouseClicked(window, event);
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event)
{
    // if the mouse is clicked anywhere in the window, return true
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        countClicks(event);
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked()
{
    // if the mouse is clicked twice within 500 milliseconds, return true
    return clicks == 2;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked()
{
    // if the mouse is clicked three times within 500 milliseconds, return true
    return clicks == 3;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event)
{
    // if the mouse is clicked and dragged over the object, return true
    return mouseClicked(object, window) && hovered(object,window);
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window)
{
    return object.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}

template<class T>
void MouseEvents<T>::countClicks(sf::Event event)
{
    // if the mouse is clicked, increment the clicks based on time between clicks
    // use this to determine if a double click or triple click occurred
    if(event.type == sf::Event::MouseButtonPressed){
        clicks++;
    }
    if(clock.getElapsedTime().asMilliseconds() > 500){
        clicks = 0;
    }
    //when does the clock reset?
    //clock.restart();
}

#endif //TEXTBOXPROJECT_MOUSEEVENTS_CPP
