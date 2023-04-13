//
// Created by joseg on 4/4/2023.
//

#include "FileItem.h"

// Constructor ---------------------------------------------------------------------------------------------------------
FileItem::FileItem()
{
    enableState(VISIBLE);
}

FileItem::FileItem(Image icon, std::string text, sf::Vector2f size, sf::Vector2f position) : Item(position,size,text)
{
    enableState(VISIBLE);
    setIcon(icon);
    setText(text);
    setSize(size);
    setPosition(position); // might not work
}

// Accessors -----------------------------------------------------------------------------------------------------------

sf::FloatRect FileItem::getGlobalBounds() const
{
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const
{
    return Item::getSize();
}

sf::Vector2f FileItem::getPosition() const
{
    return Item::getPosition();
}

Image FileItem::getImage() const
{
    return image;
}


// Mutators ------------------------------------------------------------------------------------------------------------
void FileItem::setPosition(sf::Vector2f pos)
{
    Item::setPosition(pos);
    text.setPosition({text.getPosition().x + 5.f, text.getPosition().y});
    icon.setPosition(pos.x, pos.y);
}

void FileItem::setIcon(Image icon)
{
    // Declare and load a texture
    if(icon == Image::_FOLDER)
        iconTexture.loadFromFile("./FileTree/folder1.png");
    else if(icon == Image::_FILE)
        iconTexture.loadFromFile("./FileTree/file1.png");

    image = icon;

    // Create a sprite
    this->icon.setTexture(iconTexture);//sf::Sprite sprite;
    //this->icon.setTextureRect(sf::IntRect(10, 10, 50, 30));
    this->icon.setScale(0.5, 0.5);


    //this->icon.setColor(sf::Color(255, 255, 255, 200));
    //this->icon.setPosition(100, 25);
}

// Overriden methods ---------------------------------------------------------------------------------------------------
void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //Item::addEventHandler(window, event);

    if(MouseEvents<Item>::hovered(*this, window)){
        setHightlight(true);
    }
    else{
        setHightlight(false);
    }
}