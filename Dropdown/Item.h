//
// Created by joseg on 3/26/2023.
//

#ifndef TEXTBOXPROJECT_ITEM_H
#define TEXTBOXPROJECT_ITEM_H
#include <SFML/Graphics.hpp>
#include "../Components/TextBox.h"
#include "../GUIComponent/GUIComponent.h"
#include "../Textbox/Font.h"
#include "../MouseEvents/MouseEvents.h"

//This is a simple item in the list, it should consist of a simple box with the item name centered.
class Item : public GUIComponent
{
private:
    sf::RectangleShape box;
protected:
    sf::Text text;

public:
    Item();
    Item(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text);

    //mutators
    void setPosition(const sf::Vector2f &position);
    void setHightlight(bool highlight);
    void setSize(const sf::Vector2f &size);
    void setText(const std::string &text);

    void setOutlineColor(const sf::Color& color);
    void setFillColor(const sf::Color& color);
    void setTextColor(const sf::Color& color);

    //accessors
    sf::FloatRect getGlobalBounds() const;
    std::string getText() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;

    //overriden methods
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(const Snapshot* snapshot) override;
};


#endif //TEXTBOXPROJECT_ITEM_H
