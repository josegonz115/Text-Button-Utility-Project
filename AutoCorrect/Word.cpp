//
// Created by joseg on 3/23/2023.
//

#include "Word.h"

//constructor
Word::Word()
{
    priority = 0;
    setCharacterSize(20);
    setFillColor(sf::Color::Red);
}

//overloading all comparision operators
bool operator<(const Word &lhs, const Word &rhs)
{
    return lhs.priority < rhs.priority;
}

bool operator>(const Word &lhs, const Word &rhs)
{
    return lhs.priority > rhs.priority;
}

bool operator<=(const Word &lhs, const Word &rhs)
{
    return lhs.priority <= rhs.priority;
}

bool operator>=(const Word &lhs, const Word &rhs)
{
    return lhs.priority >= rhs.priority;
}

bool operator==(const Word &lhs, const Word &rhs)
{
    return lhs.priority == rhs.priority;
}

bool operator!=(const Word &lhs, const Word &rhs)
{
    return lhs.priority != rhs.priority;
}

std::istream & operator>>(std::istream &in, Word& word)
{
    // get string input and store it in word
    std::string text;
    in >> text;
    word.setString(text);
    return in;

}


// getters and setters for priority
int Word::getPriority() const
{
    return priority;
}

void Word::setPriority(int priority)
{
    this->priority = priority;
}