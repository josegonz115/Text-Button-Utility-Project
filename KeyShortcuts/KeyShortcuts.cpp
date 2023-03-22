//
// Created by joseg on 3/18/2023.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo(){
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl);
}


bool KeyShortcuts::isRedo() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl);
}