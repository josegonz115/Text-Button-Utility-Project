//
// Created by joseg on 3/26/2023.
//

#include "DropdownMenu.h"

//Constructor-----------------------------------------------------------------------------------------------------------
DropdownMenu::DropdownMenu(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text)
:inputBox(position, size, text), itemList({position.x, position.y + size.y}, size){} //3rd param 5

//Mutators--------------------------------------------------------------------------------------------------------------
void DropdownMenu::addItem(const std::string &text)
{
    itemList.add(text);
}

void DropdownMenu::setPosition(const sf::Vector2f &position)
{
    inputBox.setPosition(position);
    itemList.setPosition({position.x, position.y + inputBox.getGlobalBounds().height});
}

//Accessors--------------------------------------------------------------------------------------------------------------
sf::FloatRect DropdownMenu::getGlobalBounds() const
{
    // Create size adding width and height of both boxes
    sf::Vector2f size(inputBox.getGlobalBounds().width, inputBox.getGlobalBounds().height + itemList.getSize().y);
    sf::FloatRect bounds(inputBox.getPosition(), size);

    return bounds;
}

//Overriden methods------------------------------------------------------------------------------------------------------
void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(inputBox);
    for(const Item& item : itemList){
        window.draw(item);
    }
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    inputBox.addEventHandler(window, event);
    if(inputBox.checkState(ACTION)){
        itemList.setVisible(true);
        for(Item& item : itemList){
            item.addEventHandler(window, event);
            if(MouseEvents<Item>::mouseClicked(item,window,event)){
                inputBox.setInputText(item.getText());
                itemList.setHightlight(false);
                inputBox.disableState(ACTION);
                itemList.setVisible(false);
                break;
            }
        }
    }
}

void DropdownMenu::update(){}

Snapshot* DropdownMenu::getSnapshot()
{


}

void DropdownMenu::applySnapshot(const Snapshot* snapshot){
}
