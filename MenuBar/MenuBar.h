//
// Created by joseg on 4/2/2023.
//

#ifndef TEXTBOXPROJECT_MENUBAR_H
#define TEXTBOXPROJECT_MENUBAR_H
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <map>


//This class will hold a number of Item lists and align them horizontally.
class MenuBar : public GUIComponent
{
private:
    std::map<std::string, Menu> menus;


    sf::Vector2f lastPosition;
    sf::Vector2f size;

public:
    MenuBar();
    MenuBar(const sf::Vector2f& position = {0,0}, const sf::Vector2f& size = {100,40}, const std::string& text = "Menu");
    void addMenu(const std::string& name);

    void addItem(const std::string& menuName, const std::string& itemName);


    //Overriden methods
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(const Snapshot* snapshot) override;

};


#endif //TEXTBOXPROJECT_MENUBAR_H
