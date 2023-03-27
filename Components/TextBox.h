//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_TEXTBOX_H
#define TEXTBOXPROJECT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "../GUIComponent/GUIComponent.h"
#include "Cursor.h"

class TextBox : public GUIComponent {
private:
    sf::RectangleShape boxShape;
    Snapshot _snapshot;

public:
    TextBox();
    TextBox(const TextBox& copy);
    // Mutators
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);

    // Accessors
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    //override
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};



#endif //TEXTBOXPROJECT_TEXTBOX_H
