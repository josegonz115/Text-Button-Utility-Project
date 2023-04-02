//
// Created by joseg on 3/30/2023.
//

#ifndef TEXTBOXPROJECT_TEXTINPUTSNAPSHOT_H
#define TEXTBOXPROJECT_TEXTINPUTSNAPSHOT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Snapshot.h"

#include "../Components/TextBox.h"
#include "../Components/Cursor.h"
#include "../Textbox//MultiText.h"
#include "../AutoCorrect/Suggestion.h"

class TextInputSnapshot : public Snapshot
{
private:
//    sf::Text labelFirstName;
//    sf::Text labelLastName;
//    TextBox textBoxFirstName;
//    TextBox textBoxLastName;
//    Cursor cursorFirstName;
//    Cursor cursorLastName;
//    MultiText multiTextFirstName;
//    MultiText multiTextLastName;

//      Suggestion suggestion;

    std::string data;
public:

    //setters
//    void setLabelFirstName(const sf::Text& labelFirstName);
//    void setLabelLastName(const sf::Text& labelLastName);
//    void setTextBoxFirstName(const TextBox& textBoxFirstName);
//    void setTextBoxLastName(const TextBox& textBoxLastName);
//    void setCursorFirstName(const Cursor& cursorFirstName);
//    void setCursorLastName(const Cursor& cursorLastName);
//    void setMultiTextFirstName(const MultiText& multiTextFirstName);
//    void setMultiTextLastName(const MultiText& multiTextLastName);
//    void setSuggestion(const Suggestion& suggestion);

    void setData(const std::string& textInput);

    // getters
//    sf::Text getLabelFirstName() const;
//    sf::Text getLabelLastName() const;
//    TextBox getTextBoxFirstName() const;
//    TextBox getTextBoxLastName() const;
//    Cursor getCursorFirstName() const;
//    Cursor getCursorLastName() const;
//    MultiText getMultiTextFirstName() const;
//    MultiText getMultiTextLastName() const;
//    Suggestion getSuggestion() const;


    std::string getData() const;
};


#endif //TEXTBOXPROJECT_TEXTINPUTSNAPSHOT_H
