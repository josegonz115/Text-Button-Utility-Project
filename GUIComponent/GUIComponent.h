//
// Created by joseg on 3/16/2023.
//

#ifndef TEXTBOXPROJECT_GUICOMPONENT_H
#define TEXTBOXPROJECT_GUICOMPONENT_H
#include "../EventHandler.h"
#include "../States/States.h"
#include "../Snapshot/SnapshotInterface.h"
#include <SFML/Graphics.hpp>


//EventHandler, States, SnapshotInterface, sf::Drawable, and sf::Transformable (optional)
class GUIComponent : public EventHandler, public States, public SnapshotInterface, public sf::Drawable, public sf::Transformable
{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot* getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot* snapshot) = 0;
};


#endif //TEXTBOXPROJECT_GUICOMPONENT_H
