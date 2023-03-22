//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_TEXTINPUT_H
#define TEXTBOXPROJECT_TEXTINPUT_H
#include "../GUIComponent/GUIComponent.h"
#include "../Textbox/MultiText.h"
#include <SFML/Graphics.hpp>
#include "../Components/TextBox.h"
#include "../Components/Cursor.h"
#include "../Textbox/Font.h"
#include "../MouseEvents/MouseEvents.h"
#include "../History/History.h"

class TextInput : public GUIComponent {
private:
    sf::Text labelFirstName;
    sf::Text labelLastName;
    TextBox textBoxFirstName;
    TextBox textBoxLastName;
    Cursor cursorFirstName;
    Cursor cursorLastName;
    MultiText multiTextFirstName;
    MultiText multiTextLastName;

    Snapshot _snapshot;

    //overriden
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void update() override;

public:
    TextInput();
    TextInput(const sf::RenderWindow& window);
    TextInput& operator=(const TextInput& other);
    TextInput(const TextInput& copy);

    // Mutators
    void setLabels(const std::string &firstName, const std::string &lastName);
    void setPosition(const sf::Vector2f &position);


    void update(float time);
    //Overriden
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};



#endif //TEXTBOXPROJECT_TEXTINPUT_H
