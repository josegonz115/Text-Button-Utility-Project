//
// Created by joseg on 4/4/2023.
//

#ifndef TEXTBOXPROJECT_FILEITEM_H
#define TEXTBOXPROJECT_FILEITEM_H
#include <SFML/Graphics.hpp>
#include "../Dropdown/Item.h"
#include "Image.h"



class FileItem : public Item
{
public:
    //Constructors
    FileItem();
    FileItem(Image icon, std::string text, sf::Vector2f size = {100,25}, sf::Vector2f position = {10,10});

    //Accessors
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    Image getImage() const;

    //Mutators
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(Image icon);


    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

private:
    //this is the folder or file icon
    sf::Sprite icon;
    sf::Texture iconTexture;
    float padding = 5.f;
    Image image;
};


#endif //TEXTBOXPROJECT_FILEITEM_H
