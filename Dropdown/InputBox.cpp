//
// Created by joseg on 3/26/2023.
//

#include "InputBox.h"
#include <iostream>
//Constructor-----------------------------------------------------------------------------------------------------------
InputBox::InputBox() : Item() {}
InputBox::InputBox(const sf::Vector2f &position, const sf::Vector2f &size, const std::string& text):
Item(position, size, "")
{
    disableState(DISABLED);
    enableState(HIGHLIGHTED);
    setText(text);
}
//Mutators--------------------------------------------------------------------------------------------------------------
void InputBox::setInputText(const std::string& text){
    setText(text);
}
//Accessors--------------------------------------------------------------------------------------------------------------'
bool InputBox::isOpened() const{
    return checkState(ACTION);
}
//Overriden methods------------------------------------------------------------------------------------------------------
void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event){
    if(MouseEvents<InputBox>::mouseClicked(*this,window,event)){
        enableState(ACTION);
        std::cout << "Mouse clicked" << std::endl;
    }
//    if(!MouseEvents<InputBox>::hovered(*this, window)){
//        disableState(ACTION);
//    }
}
