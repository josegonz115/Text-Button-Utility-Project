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
    // clear heapTree
    heapTree.clear();

    std::string temp = lowerWord(word);
    hearistic(temp);
    float y = initialPos.y;
    for(int i = 0; i < words.size(); ++i){
        if(words[i].getPriority() > 0){
            words[i].setPosition({initialPos.x, y});
            heapTree.push(words[i]);
            y += words[i].getGlobalBounds().height; // why does it not work with y += 20
        }
    }
}

std::map<char, int> Suggestion::getCharCount(const std::string& text){
    std::map<char, int> charCount;
    for (char c : text) {
        if(charCount.find(c) == charCount.end()){
            charCount[c] = 1;
        }
        else{
            charCount[c]++;
        }
    }
    return charCount;
}

std::map<char, int> Suggestion::getCharCount(const sf::String& text){
    std::string temp = text;
    return getCharCount(temp);
}


void Suggestion::hearistic(const std::string& word)
{
    // checking how many letters are contained in words (in file) 2 points if a is in right place, 1 is just is if letter is just there
    for(int i = 0; i < words.size(); ++i ){
        std::map<char, int> fileWordLetCount = getCharCount(words[i].getString());
        int points = 0;

        for(int j = 0; j < word.size(); j++){
            // if the word is smaller than the word in the file, then skip
            if(j >= words[i].getString().getSize()){
                continue;
            }

            std::string temp = words[i].getString().substring(j, words[i].getString().getSize() - j);
            std::map<char,int> userLetCount = getCharCount(temp);
            char wordsChar = tolower(words[i].getString()[j]);
            if(word[j] == wordsChar){
                points += 2;
                if(fileWordLetCount.find(word[j]) != fileWordLetCount.end()){
                    fileWordLetCount[word[j]] -= 1;
                    if(fileWordLetCount[word[j]] == 0){
                        fileWordLetCount.erase(word[j]);
                    }
                }
            }
            else if(temp.find(word[j]) != std::string::npos){
                // check if the letter fileWordLetCount has the letter
                if(fileWordLetCount.find(word[j]) != fileWordLetCount.end()){
                    fileWordLetCount[word[j]] -= 1;
                    if(fileWordLetCount[word[j]] == 0){
                        fileWordLetCount.erase(word[j]);
                    }
                    points += 1;
                }
                //points += 1;
            }
        }
        words[i].setPriority(points);
    }
}




std::string Suggestion::lowerWord(const std::string& word){
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

void Suggestion::clear(){
    heapTree.clear();
}