//
// Created by joseg on 4/2/2023.
//

#include "Menu.h"

Menu::Menu(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text) : DropdownMenu(position, size, text)
{
    //enlarge the size of the list
    setListSize({size.x * 2, size.y});
    getInputBox().setOutlineColor(sf::Color::White);
    getInputBox().setFillColor(sf::Color::Black);
    getInputBox().setTextColor(sf::Color::White);
}



//Overriden methods
void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    InputBox& inputBox = getInputBox();
    ItemList& itemList = getItemList();

    inputBox.addEventHandler(window, event);
    if(inputBox.checkState(ACTION)){
        getInputBox().setFillColor(sf::Color::Blue);
        itemList.setVisible(true);
        for(Item& item : itemList){
            item.addEventHandler(window, event);
            if(MouseEvents<Item>::mouseClicked(item,window,event)){
                //getInputBox().setInputText(item.getText());
                itemList.setHightlight(false);
                inputBox.disableState(ACTION);
                itemList.setVisible(false);
                break;
            }
        }
        if(!(MouseEvents<InputBox>::hovered(inputBox,window) || MouseEvents<Item>::hovered(itemList,window))){
            itemList.setHightlight(false);
            inputBox.disableState(ACTION);
            itemList.setVisible(false);
        }
    }
    else{
        getInputBox().setFillColor(sf::Color::Black); // bad practice????
    }
}
