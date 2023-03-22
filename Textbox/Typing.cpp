//
// Created by joseg on 3/2/2023.
//

#include "Typing.h"

Typing::Typing(){
    this->text.setFont(Font::getFont());
    //test
    this->text.setPosition(10.f, 10.f);
    //this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(48);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type == sf::Event::TextEntered){
        unsigned int textSize = text.getSize();
        unsigned int unicode = event.text.unicode;
        //delete unicode
        if (unicode == 8){
            if(textSize > 0){
//                std::string shortened = text.getString().substr(0, text.getString().size() - 1);
//                text.setString(shortened);
                text.backspace();
            }
        }
        else if((unicode >= 32 && unicode <= 126) || (unicode >= 192 && unicode <= 255)){
            //text.setString(text.getString() + static_cast<char>(unicode));
            text.append(static_cast<char>(unicode));
        }
    }
}

void Typing::update()
{
    std::string phrase = text.getString();
    //Random text update action
    if (phrase.find("i'm jose") != std::string::npos)
    {
        text.setString(" hey jose");
    }
    else if(phrase.find("where is my hometown?") != std::string::npos){
        text.setString("Whittier of CA");
    }
    else if(phrase.find("what school do you go to?") != std::string::npos){
        text.setString("PCC , best school ever");
    }
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}
