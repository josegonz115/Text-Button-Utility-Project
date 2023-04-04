//
// Created by joseg on 4/2/2023.
//

#ifndef TEXTBOXPROJECT_MENU_H
#define TEXTBOXPROJECT_MENU_H

#include "../Dropdown/DropdownMenu.h"

//This class should reuse the Item and ItemList class from the previous assignment.
//When the Item object is clicked, it should toggle the ItemList object.
class Menu : public DropdownMenu
{
private:

public:
    Menu(const sf::Vector2f& position = {0,0}, const sf::Vector2f& size = {100, 40}, const std::string& text = "Menu");

    //Overriden methods
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
};


#endif //TEXTBOXPROJECT_MENU_H
