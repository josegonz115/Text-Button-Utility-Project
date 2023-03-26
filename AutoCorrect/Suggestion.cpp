//
// Created by joseg on 3/23/2023.
//

#include "Suggestion.h"
#include <iostream> //DELETE

Suggestion::Suggestion(){}

Suggestion::Suggestion(const std::string& fileName)
{
    FileReader<Word> fileReader(fileName);
    words = fileReader.getData();
}

void Suggestion::prioritize(const std::string& word)
{
    std::string temp = tolower(word);
    hearistic(temp);
    float y = initialPos.y;
    for(int i = 0; i < words.size(); ++i){
        if(words[i].getPriority() > 0){
            words[i].setPosition({initialPos.x, y});
            heapTree.push(words[i]);
            y += words[i].getGlobalBounds().height; // why does it not work with y += 20
        }
    }


//
//    // Use heap to prioritize words
//    heapTree.pop();
//    //set position of Word
//    words.push_back(heapTree.top());
}

void Suggestion::hearistic(const std::string& word)
{
    // checking how many letters are contained in words (in file) 2 points if a is in right place, 1 is just is if letter is just there
    for(int i = 0; i < words.size(); ++i ){
        int points = 0;
        for(int j = 0; j < word.size(); j++){
            if(word[j] == words[i].getString()[j]){
                points += 2;
            }
            else if(words[i].getString().find(word[j]) != std::string::npos){
                points += 1;
            }
        }
        words[i].setPriority(points);
    }
}

std::string Suggestion::tolower(const std::string& word){
    std::string temp = word;
    for(int i = 0; i < word.size(); ++i){
        if(temp[i] >= 'A' && temp[i] <= 'Z'){
            temp[i] += 32;
        }
    }
    return temp;
}

// setter and getter for position
void Suggestion::setPosition(sf::Vector2f pos)
{
    initialPos = pos;
}

sf::Vector2f Suggestion::getPosition(){ return initialPos; }

void Suggestion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    HeapTree<Word> temp = heapTree;
    while (!temp.empty()) {
        target.draw(temp.top(), states);
        temp.pop();
    }
}