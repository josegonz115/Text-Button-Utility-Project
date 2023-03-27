//
// Created by joseg on 3/26/2023.
//

#ifndef TEXTBOXPROJECT_DROPDOWNMENU_H
#define TEXTBOXPROJECT_DROPDOWNMENU_H
#include "../GUIComponent/GUIComponent.h"
#include "ItemList.h"
#include "InputBox.h"

//This is the class that brings the Item, ItemList and InputBox together. This class must also be a child of GUIComponent

class DropdownMenu : public GUIComponent
{
private:
    InputBox inputBox;
    ItemList itemList;

public:
    //Constructor
    DropdownMenu(const sf::Vector2f& position = {10,10}, const sf::Vector2f& size = {100, 30}, const std::string& text = "Dropdown menu");

    //Mutators
    //void addItem(const Item& item);
    void addItem(const std::string& text);
    void setPosition(const sf::Vector2f& position);

    //Accessors
    sf::FloatRect getGlobalBounds() const;
    //std::string getText() const;

    //Overriden methods
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;

};


#endif //TEXTBOXPROJECT_DROPDOWNMENU_H
