//
// Created by joseg on 3/18/2023.
//
#include "TextInput.h"
#include <iostream>

//Constructors-------------------------------------------------------------------------------------------------------
TextInput::TextInput(){
    //label.setString("Jose's Typing Box");
}

//Big 2-------------------------------------------------------------------------------------------------------
TextInput::TextInput(const sf::RenderWindow &window):suggestion("./AutoCorrect/jNames.txt") {
    // Set up labels
    labelFirstName.setFont(Font::getFont());
    labelFirstName.setString("First Name: ");
    labelFirstName.setCharacterSize(24);
    labelFirstName.setFillColor(sf::Color::White);

    labelLastName.setFont(Font::getFont());
    labelLastName.setString("Last Name: ");
    labelLastName.setCharacterSize(24);
    labelLastName.setFillColor(sf::Color::White);

    // Calculate screen center and positioning
    float screenWidth = static_cast<float>(window.getSize().x);
//    float screenHeight = static_cast<float>(window.getSize().y);
//    float centerX = screenWidth / 2.0f;

    // Set positions for labels and textboxes
    setPosition({10,10});

}

TextInput::TextInput(const TextInput& copy): GUIComponent(),labelFirstName(copy.labelFirstName),labelLastName(copy.labelLastName),
textBoxFirstName(copy.textBoxFirstName),textBoxLastName(copy.textBoxLastName),cursorFirstName(copy.cursorFirstName),
cursorLastName(copy.cursorLastName),multiTextFirstName(copy.multiTextFirstName),multiTextLastName(copy.multiTextLastName){}

TextInput& TextInput::operator=(const TextInput& other) {
    if (this == &other) {
        return *this;
    }

    //GUIComponent::operator=(other); keep for future adaptibility

    labelFirstName = other.labelFirstName;
    labelLastName = other.labelLastName;
    textBoxFirstName = other.textBoxFirstName;
    textBoxLastName = other.textBoxLastName;
    cursorFirstName = other.cursorFirstName;
    cursorLastName = other.cursorLastName;
    multiTextFirstName = other.multiTextFirstName;
    multiTextLastName = other.multiTextLastName;

    return *this;
}


//Setters-------------------------------------------------------------------------------------------------------------
void TextInput::setLabels(const std::string &firstName, const std::string &lastName){
    labelFirstName.setString(firstName);
    labelLastName.setString(lastName);
}

void TextInput::setPosition(const sf::Vector2f &position) {
    // Set the position of the labels
    labelFirstName.setPosition(position);
    labelLastName.setPosition(position.x, position.y + labelFirstName.getLocalBounds().height * 3.0f);

    // Calculate the position for TextBoxes and Cursors
    sf::Vector2f textBoxPosition(position.x + labelFirstName.getLocalBounds().width, position.y);

    // Set the position of the TextBoxes
    textBoxFirstName.setPosition(textBoxPosition);
    textBoxLastName.setPosition({textBoxPosition.x, labelLastName.getPosition().y});

    // Set the position of the MultiText objects
    multiTextFirstName.setPosition(textBoxFirstName.getPosition());
    multiTextLastName.setPosition(textBoxLastName.getPosition());

    // Set the position of the Cursors
    cursorFirstName.setPosition(multiTextFirstName.getCursorPosition());
    cursorLastName.setPosition(multiTextLastName.getCursorPosition());

    // put suggestion after wordbox 1
    suggestion.setPosition({multiTextFirstName.getPosition().x, multiTextFirstName.getPosition().y});
}


//Overriden
void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(labelFirstName);
    window.draw(labelLastName);
    window.draw(textBoxFirstName);
    window.draw(textBoxLastName);
    window.draw(cursorFirstName);
    window.draw(cursorLastName);
    window.draw(multiTextFirstName);
    window.draw(multiTextLastName);

    window.draw(suggestion);
}
void TextInput::update()
{
    //am i suppose to update every sf::Drawable ?
    textBoxFirstName.update();
    textBoxLastName.update();
    cursorFirstName.update();
    cursorLastName.update();
    multiTextFirstName.update();
    multiTextLastName.update();

}

Snapshot &TextInput::getSnapshot()
{
//    // Record the current state of TextInput after handling events
//    Snapshot* snapshot = new Snapshot(multiTextFirstName.getSnapshot());
//    History::pushHistory({snapshot,o});
//
//
    _snapshot = new TextInput(*this);
    return _snapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot)
{
    GUIComponent* prev = snapshot;
    TextInput* prevState = static_cast<TextInput*>(prev);
    if (prevState) {
        *this = *prevState;
        delete prevState;
    }
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    // Record the current state of TextInput after handling events
    Snapshot* snapshot;

    // Check if the mouse is hovering over the TextBoxes
    if (MouseEvents<TextBox>::mouseClicked(textBoxFirstName, window,event))
    {
        std::cout << "Clicked First Name TextBox\n";
        cursorFirstName.setHighlighted(true);
        cursorLastName.setHighlighted(false);

        snapshot = new Snapshot(getSnapshot());
        History::pushHistory({snapshot,this});
    }
    else if(MouseEvents<TextBox>::mouseClicked(textBoxLastName, window,event))
    {
        std::cout << "Clicked Last Name TextBox\n";
        cursorFirstName.setHighlighted(false);
        cursorLastName.setHighlighted(true);

        snapshot = new Snapshot(getSnapshot());
        History::pushHistory({snapshot,this});
    }
    else if(MouseEvents<TextBox>::mouseClicked(window,event))
    {
        std::cout << "Clicked outside of TextBoxes\n";
        cursorFirstName.setHighlighted(false);
        cursorLastName.setHighlighted(false);

        snapshot = new Snapshot(getSnapshot());
        History::pushHistory({snapshot,this});
    }

    if(cursorFirstName.isHighlighted())
    {
        // Handle the events for the first name TextBox
        multiTextFirstName.addEventHandler(window,event);
        cursorFirstName.setPosition(multiTextFirstName.getCursorPosition()); //might move to update
        //Test out the auto correct
        if(event.type == sf::Event::TextEntered){
            std::cout << "button pressed\n";
            suggestion.prioritize(multiTextFirstName.getString());

        }
    }
    else if(cursorLastName.isHighlighted())
    {
        // Handle the events for the last name TextBox
        multiTextLastName.addEventHandler(window,event);
        cursorLastName.setPosition(multiTextLastName.getCursorPosition());
    }



}