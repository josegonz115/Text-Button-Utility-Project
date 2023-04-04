//
// Created by joseg on 4/2/2023.
//

#include "MenuBar.h"

// Constructor ---------------------------------------------------------------------------------------------------------
MenuBar::MenuBar()
{
    lastPosition = {0,0};
    size = {100,40};
}

MenuBar::MenuBar(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &name)
{
    menus.insert({name, Menu(position, size, name)});
    lastPosition = position;
    this->size = size;
}


// Mutators ------------------------------------------------------------------------------------------------------------
void MenuBar::addMenu(const std::string &name)
{
    if(menus.empty()){
        menus.insert({name, Menu(lastPosition, size, name)});
    }
    else{
        lastPosition.x += size.x;
        menus.insert({name, Menu(lastPosition, size, name)});
    }
}

void MenuBar::addItem(const std::string &menuName, const std::string &itemName)
{
    if(menus.find(menuName) != menus.end()){
        menus[menuName].addItem(itemName);
    }
}

// Overriden methods ---------------------------------------------------------------------------------------------------
void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(auto& menu : menus){
        window.draw(menu.second);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(auto& menu : menus){
        menu.second.addEventHandler(window, event);
    }
}

void MenuBar::update()
{
    for(auto& menu : menus){
        menu.second.update();
    }
}

Snapshot *MenuBar::getSnapshot()
{
    return nullptr;
}

void MenuBar::applySnapshot(const Snapshot *snapshot)
{

}

