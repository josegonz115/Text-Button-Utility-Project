//
// Created by joseg on 3/3/2023.
//

#ifndef MULTITEXT_MULTITEXT_H
#define MULTITEXT_MULTITEXT_H
#include <list>
#include <iterator>
#include "Letter.h"
#include "../GUIComponent/GUIComponent.h"
#include "../History/History.h"

class MultiText : public GUIComponent
{
private:
    std::list<Letter> _letters;

    sf::Font _font;
    sf::Vector2f _position;
    sf::Color _color;
    unsigned int _charSize;
    Snapshot _snapshot;

    sf::Vector2f _startPos;

    typedef std::list<Letter>::iterator iterator;
    typedef std::list<Letter>::const_iterator const_iterator;
    //Accessors
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    //helper
    sf::Color getLetterColor(char letter);

public:


    MultiText();
    MultiText(const MultiText& other);
    //Mutators
    void setFont(const sf::Font& font = Font::getFont());
    void setPosition(float x = 10.f, float y = 10.f);
    void setPosition(sf::Vector2f position);
    void setFillColor(const sf::Color& color = sf::Color::White);
    void setCharacterSize(unsigned int charSize = 48);
    void setString(const std::string& letters);

    void append(char letter);
    void backspace();



    //Accessors
    std::string getString();
    unsigned int getSize();
    sf::Vector2f getCursorPosition() const;
    sf::Vector2f getPosition() const;

    //overrided
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};


#endif //MULTITEXT_MULTITEXT_H
