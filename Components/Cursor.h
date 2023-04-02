//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_CURSOR_H
#define TEXTBOXPROJECT_CURSOR_H
#include <SFML/Graphics.hpp>
#include "../GUIComponent/GUIComponent.h"
#include "../States/States.h"

class Cursor : public GUIComponent {
private:
    sf::RectangleShape cursorShape;
    bool _visible;
    sf::Clock _clock;
    float _blinkPeriod;



    //override
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Cursor();
    Cursor(const Cursor& other);
    Cursor(const sf::RectangleShape &cursorShape, const Snapshot &snapshot);

    //setters
    void setPosition(const sf::Vector2f& position);
    void setHighlighted(bool highlighted);

    //getters
    void getPosition() const;
    bool isHighlighted() const;

    //override
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(const Snapshot* snapshot) override;
};



#endif //TEXTBOXPROJECT_CURSOR_H
