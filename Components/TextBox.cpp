//
// Created by joseg on 3/18/2023.
//

#include "TextBox.h"

//Constructors----------------------------------------------------------------------------------------------------------
TextBox::TextBox() {
    boxShape.setSize(sf::Vector2f(350, 30));
    boxShape.setOutlineColor(sf::Color::White);
    boxShape.setOutlineThickness(1);
    boxShape.setFillColor(sf::Color(240, 240, 240));
}

TextBox::TextBox(const TextBox& copy): GUIComponent(copy),boxShape(copy.boxShape){}

// Mutators-------------------------------------------------------------------------------------------------------------
void TextBox::setPosition(sf::Vector2f position) {
    // Update the box shape position
    boxShape.setPosition(position);
}

void TextBox::setSize(sf::Vector2f size) {
    // Update the box shape size
    boxShape.setSize(size);
}

// Accessors------------------------------------------------------------------------------------------------------------
sf::Vector2f TextBox::getPosition() const{
    return boxShape.getPosition();
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return boxShape.getGlobalBounds();
}

// Overriden Methods----------------------------------------------------------------------------------------------------
void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(boxShape, states);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void TextBox::update()
{

}

Snapshot* TextBox::getSnapshot()
{
//    TextBoxSnapshot* p = new TextBox;
//    p->setData(boxShape.getText());
}

void TextBox::applySnapshot(const Snapshot* snapshot)
{

//    boxShape.applySnapshot(snapshot);
}