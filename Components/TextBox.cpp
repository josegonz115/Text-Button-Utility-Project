//
// Created by joseg on 3/18/2023.
//

#include "TextBox.h"
#include "TextBox.h"

TextBox::TextBox() {
    boxShape.setSize(sf::Vector2f(350, 30));
    boxShape.setOutlineColor(sf::Color::White);
    boxShape.setOutlineThickness(1);
    boxShape.setFillColor(sf::Color(240, 240, 240));
}

TextBox::TextBox(const TextBox& copy): GUIComponent(copy),boxShape(copy.boxShape), _snapshot(copy._snapshot){}





void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(boxShape, states);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void TextBox::update()
{

}

Snapshot& TextBox::getSnapshot()
{
    _snapshot = new TextBox(*this);
    return _snapshot;
}

void TextBox::applySnapshot(const Snapshot &snapshot)
{
    GUIComponent* prev = (snapshot);
    TextBox* prevState = static_cast<TextBox*>(prev);
    if(prevState){
        *this = *prevState;
    }
}


void TextBox::setPosition(sf::Vector2f position) {
    // Update the box shape position
    boxShape.setPosition(position);
}


//getters
sf::Vector2f TextBox::getPosition() const{
    return boxShape.getPosition();
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return boxShape.getGlobalBounds();
}