//
// Created by joseg on 3/26/2023.
//

#include "ItemList.h"

// Constructors---------------------------------------------------------------------------------------------------------
ItemList::ItemList(sf::Vector2f startPos, sf::Vector2f size, float padding):
xStart(startPos.x), yStart(startPos.y), size(size), yPadding(padding) {}

// Mutators-------------------------------------------------------------------------------------------------------------
void ItemList::setPosition(sf::Vector2f position) {
    xStart = position.x;
    yStart = position.y;
    updateAlignment();
}

void ItemList::push_back(const Item& item) {
    Item temp(item);
    std::list<Item>::push_back(item);
    updateAlignment();
}

void ItemList::add(const std::string& text) {
    Item temp({xStart,yStart}, size, text);
    this->push_back(temp);
    updateAlignment();
}

ItemList::iterator ItemList::insert(const_iterator position, const Item& item) {
    iterator result = std::list<Item>::insert(position, item);
    updateAlignment();
    return result;
}

void ItemList::updateAlignment() {
    float yPos = yStart;
    for (Item& item : *this) {
        sf::Vector2f position(xStart, yPos);
        item.setPosition(position);
        yPos += item.getGlobalBounds().height + yPadding; // + padding if needed
    }
}

void ItemList::setHightlight(bool highlight){
    for(Item& item : *this){
        item.setHightlight(highlight);
    }
}

void ItemList::setVisible(bool visible){
    if(visible)
        for(Item& item : *this){
            item.enableState(VISIBLE);
        }
    else
        for(Item& item : *this){
            item.disableState(VISIBLE);
        }
}

// Accessors------------------------------------------------------------------------------------------------------------
sf::Vector2f ItemList::getSize() const{
    float x = size.x;
    float y = 0;
    for(const Item& item : *this){
        y += item.getGlobalBounds().height;
    }
    return {x,y};
}