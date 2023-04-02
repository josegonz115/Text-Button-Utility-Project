//
// Created by joseg on 3/18/2023.
//

#include "Cursor.h"

Cursor::Cursor() :GUIComponent(), _visible(true), _blinkPeriod(0.5f) {
    enableState(DISABLED);
    cursorShape.setSize(sf::Vector2f(1, 20));
    cursorShape.setFillColor(sf::Color::Black);

}

Cursor::Cursor(const Cursor &other):GUIComponent(other),cursorShape(other.cursorShape),_visible(other._visible),
_blinkPeriod(other._blinkPeriod){}




void Cursor::setPosition(const sf::Vector2f &position) {
    cursorShape.setPosition(position);
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const{
//    if (checkState(HIGHLIGHTED)) {
//        target.draw(cursorShape, states);
//    }
    if (_visible) {
        target.draw(cursorShape, states);
    }
}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Cursor::update()
{
    if (checkState(HIGHLIGHTED)) {
        float elapsed = _clock.getElapsedTime().asSeconds();
        if (elapsed >= _blinkPeriod) {
            _visible = !_visible;
            _clock.restart();
        }
    } else {
        _visible = false;
    }
}

void Cursor::setHighlighted(bool highlighted){
    if(highlighted){
        enableState(HIGHLIGHTED);
        disableState(DISABLED);
    }else{
        enableState(DISABLED);
        disableState(HIGHLIGHTED);
    }
}

bool Cursor::isHighlighted() const
{
    return checkState(HIGHLIGHTED);
}

Snapshot* Cursor::getSnapshot()
{
//    TextBoxSnapshot* p = new TextBox;
//    p->setData(boxShape.getText());
}

void Cursor::applySnapshot(const Snapshot* snapshot)
{
//    cursorShape.applySnapshot(snapshot);
//    _visible = snapshot.getBool();
//    _clock = snapshot.getClock();
//    _blinkPeriod = snapshot.getFloat();
}