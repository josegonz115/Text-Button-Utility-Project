//
// Created by joseg on 3/26/2023.
//

#ifndef TEXTBOXPROJECT_ITEMLIST_H
#define TEXTBOXPROJECT_ITEMLIST_H
#include <list>
#include <SFML/Graphics.hpp>
#include "Item.h"


//This is a list of Items. The items should be vertically aligned.

class ItemList : public std::list<Item>
{
private:
    float xStart, yStart, yPadding;
    sf::Vector2f size;

    void updateAlignment();
    void push_back(const Item& item);
public:
    //Constructor
    ItemList(sf::Vector2f startPos = {10,10}, sf::Vector2f size = {100, 50}, float padding = 0);

    //Mutators
    void setPosition(sf::Vector2f);
    void add(const std::string& text);
    void setHightlight(bool highlight);
    void setVisible(bool visible);

    iterator insert(const_iterator position, const Item& item);

    //Accessors
    sf::Vector2f getSize() const;
};


#endif //TEXTBOXPROJECT_ITEMLIST_H
