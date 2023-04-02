//
// Created by joseg on 3/30/2023.
//

#include "TextInputSnapshot.h"

void TextInputSnapshot::setData(const std::string &textInput)
{
    this->data = textInput;

}

std::string TextInputSnapshot::getData() const
{
    return data;
}






//void TextInputSnapshot::setLabelFirstName(const sf::Text &labelFirstName)
//{
//    this->labelFirstName = labelFirstName;
//}
//
//void TextInputSnapshot::setLabelLastName(const sf::Text &labelLastName)
//{
//    this->labelLastName = labelLastName;
//}
//
//void TextInputSnapshot::setTextBoxFirstName(const TextBox &textBoxFirstName)
//{
//    this->textBoxFirstName = textBoxFirstName;
//}
//
//void TextInputSnapshot::setTextBoxLastName(const TextBox &textBoxLastName)
//{
//    this->textBoxLastName = textBoxLastName;
//}
//
//void TextInputSnapshot::setCursorFirstName(const Cursor &cursorFirstName)
//{
//    this->cursorFirstName = cursorFirstName;
//}
//
//void TextInputSnapshot::setCursorLastName(const Cursor &cursorLastName)
//{
//    this->cursorLastName = cursorLastName;
//}
//
//void TextInputSnapshot::setMultiTextFirstName(const MultiText &multiTextFirstName)
//{
//    this->multiTextFirstName = multiTextFirstName;
//}
//
//void TextInputSnapshot::setMultiTextLastName(const MultiText &multiTextLastName)
//{
//    this->multiTextLastName = multiTextLastName;
//}
//
//void TextInputSnapshot::setSuggestion(const Suggestion &suggestion)
//{
//    this->suggestion = suggestion;
//}
//
//sf::Text TextInputSnapshot::getLabelFirstName() const
//{
//    return labelFirstName;
//}
//
//sf::Text TextInputSnapshot::getLabelLastName() const
//{
//    return labelLastName;
//}
//
//TextBox TextInputSnapshot::getTextBoxFirstName() const
//{
//    return textBoxFirstName;
//}
//
//TextBox TextInputSnapshot::getTextBoxLastName() const
//{
//    return textBoxLastName;
//}
//
//Cursor TextInputSnapshot::getCursorFirstName() const
//{
//    return cursorFirstName;
//}
//
//Cursor TextInputSnapshot::getCursorLastName() const
//{
//    return cursorLastName;
//}
//
//MultiText TextInputSnapshot::getMultiTextFirstName() const
//{
//    return multiTextFirstName;
//}
//
//MultiText TextInputSnapshot::getMultiTextLastName() const
//{
//    return multiTextLastName;
//}
//
//Suggestion TextInputSnapshot::getSuggestion() const
//{
//    return suggestion;
//}
//
