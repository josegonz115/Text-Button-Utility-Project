//
// Created by joseg on 3/23/2023.
//

#ifndef TEXTBOXPROJECT_WORD_H
#define TEXTBOXPROJECT_WORD_H
#include <SFML/Graphics.hpp>

class Word : public sf::Text
{
private:
    int priority;

public:
    // constructors
    Word();
    //overloading all comparision operators
    //overload insertion
    friend bool operator<(const Word&lhs, const Word &rhs);
    friend bool operator>(const Word& lhs, const Word &rhs);
    friend bool operator<=(const Word& lhs, const Word &rhs);
    friend bool operator>=(const Word&lhs, const Word &rhs);
    friend bool operator ==(const Word&lhs, const Word &rhs);
    friend bool operator !=(const Word& lhs, const Word& rhs);

    friend std::istream& operator >>(std::istream& in, Word& word);

    // getters and setters for priority
    int getPriority() const;
    void setPriority(int priority);
};


#endif //TEXTBOXPROJECT_WORD_H
