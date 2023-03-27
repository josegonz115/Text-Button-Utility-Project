//
// Created by joseg on 3/26/2023.
//

#ifndef TEXTBOXPROJECT_INPUTBOX_H
#define TEXTBOXPROJECT_INPUTBOX_H
#include "Item.h"

class InputBox : public Item
{
public:
    //Constructor
    InputBox();
    InputBox(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text = "Dropdown menu");
    //Mutators
    void setInputText(const std::string& text);
    //Accessors
    bool isOpened() const;
    //Overriden methods
    //void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
//    void update() override;
//    Snapshot &getSnapshot() override;
//    void applySnapshot(const Snapshot &snapshot) override;
};


#endif //TEXTBOXPROJECT_INPUTBOX_H
