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

    hearistic(word);
    for(int i = 0; i < words.size(); ++i){
        if(words[i].getPriority() > 0){
            heapTree.push(words[i]);
        }
    }
    organizePosition();
}

void Suggestion::organizePosition() {
    float y = initialPos.y;
    HeapTree<Word> temp = heapTree;
    heapTree.clear();
    //while(!temp.empty()){
    int count = 0;
    // i want the condition to only iterate 5 times if the heapTree is not empty
    while(count < 5 && !temp.empty()){
        temp.top().setPosition({initialPos.x, y});
        heapTree.push(temp.top());
        y += temp.top().getGlobalBounds().height;
        temp.pop();
        count++;
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
    std::string userWord = lowerWord(word);
    std::cout << userWord << std::endl;
    // checking how many letters are contained in words (in file) 2 points if a is in right place, 1 is just is if letter is just there
    for(int i = 0; i < words.size(); ++i ){
        int points = 0;
        std::string wordInFile = lowerWord(words[i].getString());
        for(int j = 0; j < userWord.size(); j++){
            // if the user word is bigger than the word in the file, then skip
            if(userWord.size() > words[i].getString().getSize()){
                continue;
            }
            char fileChar = wordInFile[j];
            char userChar = userWord[j];
            if(fileChar == userChar){
                points += 2;
            }
            else if(wordInFile.find(userChar) != std::string::npos){
                // check if the letter fileWordLetCount has the letter
                    points += 1;
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

    //float y = initialPos.y;
    HeapTree<Word> temp = heapTree;
    while (!temp.empty()) {
        //heapTree.top().setPosition({initialPos.x, y});
        target.draw(temp.top(), states);
        temp.pop();
    }
}

void Suggestion::clear(){
    heapTree.clear();
}