//
// Created by joseg on 3/23/2023.
//

#ifndef TEXTBOXPROJECT_SUGGESTION_H
#define TEXTBOXPROJECT_SUGGESTION_H
#include "FileReader.h"
#include "Word.h"
#include "HeapTree.h"
#include <vector>
#include <cctype>
#include <SFML/Graphics.hpp>

// uses FileReader to import data, then uses the data to compare with what the user type. I has a heuristic function to determine a priority for each Word

// This is the item that is drawn by the window to show all the words in a heap-sorted order
class Suggestion : public sf::Drawable
{
private:
    std::vector<Word> words;
    HeapTree<Word> heapTree;

    sf::Vector2f initialPos;


    //heuristic // checking how many letters are contained in words (in file) 2 points if a is in right place, 1 is just is if letter is just there
    void hearistic(const std::string& word);
    std::string lowerWord(const std::string& word);
    void organizePosition();
    // std::string tolower(Word& word);
    //int getCharCount(const std::string&, const std::string& text);
    std::map<char, int> getCharCount(const std::string& text);
    std::map<char, int> getCharCount(const sf::String& text);

    //void wordFilter(int pos, char letter);
public:
    //constructors
    Suggestion();
    Suggestion(const std::string& fileName);

    //prioritize function
    void prioritize(const std::string& word);

    // position getter and setter
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();

    // draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void clear();


};


#endif //TEXTBOXPROJECT_SUGGESTION_H
