//
// Created by joseg on 3/3/2023.
//
#include "MultiText.h"

#include <iostream>
MultiText::MultiText()
{
    setFont(Font::getFont());
    setFillColor(sf::Color::Black);
    setCharacterSize(20);
}

// Copy constructor for MultiText
MultiText::MultiText(const MultiText& other): GUIComponent(other),_snapshot(other._snapshot){
    _letters = other._letters;
    _font = other._font;
    _position = other._position;
    _startPos = _position;
    _color = other._color;
    _charSize = other._charSize;
}


// Mutators
void MultiText::setFont(const sf::Font& font){
    _font = font;
}
void MultiText::setPosition(float x, float y){
    _position = {x, y};
}
void MultiText::setPosition(sf::Vector2f position){
    _position = position;
}
void MultiText::setFillColor(const sf::Color& color){
    _color = color;
}
void MultiText::setCharacterSize(unsigned int charSize){
    _charSize = charSize;
}

void MultiText::setString(const std::string& letters) {
    _letters.clear();
    for (unsigned int i = 0; i < letters.size(); ++i) {
        Letter letterObj(letters[i], _font, _position, getLetterColor(letters[i]), _charSize);
        _letters.push_back(letterObj);
    }
}

void MultiText::append(char letter){
    Letter letterObj(letter, _font, _position, getLetterColor(letter), _charSize);
    //calculate correct position
    if (!_letters.empty()) {
        sf::Vector2f lastLetterPos = _letters.back().getPosition();
        float lastLetterWidth = _letters.back().getGlobalBounds().width;
        letterObj.setPosition(lastLetterPos.x + lastLetterWidth + 2.f, lastLetterPos.y);
    }
    _letters.push_back(letterObj);
}

void MultiText::backspace() {
    _letters.pop_back();
}

//Accessors and draw--------------------------------------------------------------------------------------------
sf::Vector2f MultiText::getCursorPosition() const {
    if (_letters.empty()) {
        return {0.f,0.f};
    } else {
        return _letters.back().findCharacterPos(1);
    }
}


std::string MultiText::getString(){
    std::string keys;
    for(iterator iter = begin(); iter != end(); ++iter){
        keys.append(iter->getString());
    }
    return keys;
}

unsigned int MultiText::getSize(){ return _letters.size(); }

MultiText::iterator MultiText::begin() { return _letters.begin(); }
MultiText::const_iterator MultiText::begin() const{ return _letters.cbegin(); }

MultiText::iterator MultiText::end(){ return _letters.end(); }
MultiText::const_iterator MultiText::end() const{ return _letters.cend(); }


void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(const_iterator iter = begin(); iter != end(); ++iter){
        window.draw(*iter);
    }
}




void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type == sf::Event::TextEntered){
        std::cout << "Text entered: " << event.text.unicode << std::endl;
        unsigned int textSize = getSize();
        unsigned int unicode = event.text.unicode;
        //delete unicode
        if (unicode == 8){
            if(textSize > 0){
                backspace();
            }
        }
        else if((unicode >= 32 && unicode <= 126) || (unicode >= 192 && unicode <= 255)){
            //text.setString(text.getString() + static_cast<char>(unicode));
            append(static_cast<char>(unicode));
        }

        // Create snapshot
        Snapshot* snapshot = new Snapshot(getSnapshot());
        History::pushHistory({snapshot,this});
    }
}

void MultiText::update()
{

    // Check for keywords and update their colors
    std::string keywords[] = {"int", "char", "double", "float"};
    for (const std::string& keyword : keywords) {
        unsigned int pos = 0;
        std::string text = getString();
        while ((pos = text.find(keyword, pos)) != std::string::npos) {
            iterator iter = _letters.begin();
            for (unsigned int i = 0; i < pos; ++i) {
                ++iter;
            }
            for (unsigned int i = 0; i < keyword.size(); ++i) {
                iter->setFillColor(sf::Color::Blue);
                ++iter;
            }
            pos += keyword.size();
        }
    }
}



Snapshot& MultiText::getSnapshot()
{
    MultiText* copy = new MultiText(*this);
    _snapshot = copy;
    return _snapshot;

}

void MultiText::applySnapshot(const Snapshot &snapshot)
{
    GUIComponent* prev = (snapshot);
    MultiText* prevState = static_cast<MultiText*>(prev);
    if(prevState){
        *this = *prevState;
        delete prevState;
    }

}


//helper for getting color
sf::Color MultiText::getLetterColor(char letter) {
    // Check for operators
    std::string operators = "+-*/%";
    if (operators.find(letter) != std::string::npos) {
        return sf::Color::Green;
    }

    // Check for numbers
    else if (std::isdigit(letter)) {
        return sf::Color::Red;
    }

    //checking for keywords will be done in update()

    // Default color (Black)
    return sf::Color::Black;
}

sf::Vector2f MultiText::getPosition() const{
    return _position;
}
