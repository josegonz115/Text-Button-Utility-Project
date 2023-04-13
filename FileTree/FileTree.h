//
// Created by joseg on 4/9/2023.
//

#ifndef TEXTBOXPROJECT_FILETREE_H
#define TEXTBOXPROJECT_FILETREE_H
#include "../GUIComponent/GUIComponent.h"
#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    const float HEIGHT = 100.f, WIDTH = 20.f;
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, Image image);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};

    //std::vector<std::string>split(std::string path);

//    void print(FileTreeNode* node);

//    FileTreeNode* search(std::string data, FileTreeNode* node);
//    FileTreeNode* createNode(std::string data);
public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL", Image image = _FILE);



    // Overriden functions----------------------------------------------------------------------------------------------
    //draws the root node of the tree
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    //calls the traverse function to add the event handlers to each node
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;



    //does nothing now
    void update() override;
    //does nothing now
    void applySnapshot(const Snapshot* snapshot) override;
    //does nothing now
    Snapshot* getSnapshot() override;
    //does nothing now
    sf::FloatRect getGlobalBounds();
};


#endif //TEXTBOXPROJECT_FILETREE_H
