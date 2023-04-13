//
// Created by joseg on 4/9/2023.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item, Image image)
{
    if(!root)
    {
        root = new FileNode(_FOLDER, parent, {HEIGHT, WIDTH}, initPosition);
    }
    else if(root->getData().getText() == parent)
    {
        root->getChildren().insert({item, new FileNode(image, item, {HEIGHT, WIDTH}, initPosition)});
        root->getChildren()[item]->disableState(VISIBLE);
    }
    else
    {
        for(auto &child : root->getChildren())
        {
            push(child.second, parent, item, image);
        }
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event)
{
    for(auto &child : root->getChildren())
    {
        child.second->addEventHandler(window, event);
        traverse(child.second, window, event);
    }
}
// Constructors --------------------------------------------------------------------------------------------------------
FileTree::FileTree(){}

void FileTree::push(std::string parent, std::string item, Image image)
{
    push(root, parent, item, image);
}

// Overriden functions----------------------------------------------------------------------------------------------
void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(*root);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    root->addEventHandler(window, event);
    //traverse(root, window, event);
}

void FileTree::update(){
    root->update();
}
void FileTree::applySnapshot(const Snapshot* snapshot){}
Snapshot* FileTree::getSnapshot(){}
sf::FloatRect FileTree::getGlobalBounds(){}
