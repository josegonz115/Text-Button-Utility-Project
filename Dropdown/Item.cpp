//
// Created by joseg on 3/26/2023.
//

#include "Item.h"
// Constructors---------------------------------------------------------------------------------------------------------
Item::Item(){ } //never used but needed for inheritance

Item::Item(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text)
{
    enableState(DISABLED);
    setPosition(position);
    //initialize box
    box.setSize(size);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(3);


    //initialize text
    this->text.setFont(Font::getFont());
    this->text.setString(text);
    this->text.setCharacterSize(15);
    this->text.setFillColor(sf::Color::Red);

}

// Mutators-------------------------------------------------------------------------------------------------------------
void Item::setText(const std::string &text){
    this->text.setString(text);
    this->text.setPosition(box.getPosition().x + (box.getSize().x/ 2) - (this->text.getGlobalBounds().width / 2),
                     box.getPosition().y + (box.getSize().y / 2) - (this->text.getGlobalBounds().height / 2));

}

void Item::setPosition(const sf::Vector2f &position)
{
    box.setPosition(position);
    // put text in middle of box
    text.setPosition(position.x + (box.getSize().x/ 2) - (text.getGlobalBounds().width / 2),
                     position.y + (box.getSize().y / 2) - (text.getGlobalBounds().height / 2));
}

void Item::setHightlight(bool highlight)
{
    if(highlight){
        enableState(HIGHLIGHTED);
        disableState(DISABLED);
        box.setFillColor(sf::Color::Blue);
    }
    else{
        enableState(DISABLED);
        disableState(HIGHLIGHTED);
        box.setFillColor(sf::Color::White);
    }
}

// Accessors------------------------------------------------------------------------------------------------------------
sf::FloatRect Item::getGlobalBounds() const
{
    return box.getGlobalBounds();
}

std::string Item::getText() const
{
    return text.getString();
}


// Overriden Methods----------------------------------------------------------------------------------------------------
void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    if(checkState(VISIBLE) || checkState(HIGHLIGHTED)){ //checkState(ACTION) &&
        window.draw(box, states);
        window.draw(text, states);
    }
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<Item>::hovered(*this, window)){
        setHightlight(true);
    }
    else{
        setHightlight(false);
    }
}

void Item::update(){}

Snapshot &Item::getSnapshot()
{
    return this->getSnapshot();
}

void Item::applySnapshot(const Snapshot &snapshot)
{

}
