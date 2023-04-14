//
// Created by joseg on 4/9/2023.
//

#include "FileNode.h"
#include <iostream>
// private functions----------------------------------------------------------------------------------------------------
void FileNode::toggleChlidren()
{
    toggleState(CHILDREN_VISIBLE);
}

void FileNode::reposition(int depth) const
{
    sf::Vector2f pos = data.getPosition();
    pos.x += 25;
    pos.y = data.getGlobalBounds().height + data.getGlobalBounds().top;

    auto iter = children.begin();
    for(auto &child : children)
    {
        child.second->getData().setPosition(pos);
        pos.y += child.second->getData().getGlobalBounds().height;

    }



//    float left = data.getPosition().x * depth + 50 ;
//    float top = data.getPosition().y;
////    if(depth > 0){
////        top += data.getSize().y * depth;
////    }
//    //int i = 1;
//    for (auto &child : children)
//    {
//
//        float height = child.second->getData().getSize().y;
//        top += height;
//        child.second->getData().setPosition({left, top});
//        if(child.second->getData().getImage() == Image::_FOLDER){
//            child.second->reposition(depth + 1);
//        }
//     //   i++;
//    }
}

// Constructors --------------------------------------------------------------------------------------------------------
FileNode::FileNode(){
    disableState(CHILDREN_VISIBLE);
    enableState(VISIBLE);
}

FileNode::FileNode(Image icon, std::string text, sf::Vector2f size, sf::Vector2f position):
data(icon, text, size, position)
{
    disableState(CHILDREN_VISIBLE);
    enableState(VISIBLE);
}

// Accessors------------------------------------------------------------------------------------------------------------

bool FileNode::isLeaf() const
{
    return children.empty();
}

FileItem& FileNode::getData(){
    return data;
}

std::map<std::string, FileNode *> &FileNode::getChildren()
{
    return children;
}

bool FileNode::isFolder() const
{
    return data.getImage() == Image::_FOLDER;
}

// Mutators-------------------------------------------------------------------------------------------------------------
void FileNode::setData(const FileItem &_data)
{
    data = _data;
}

void FileNode::addChild(const FileItem& _data){
    FileItem copy = _data;
    children[_data.getText()] = new FileNode(
            copy.getImage(), copy.getText(), copy.getSize(), copy.getPosition());

children[_data.getText()]->disableState(VISIBLE);
}

FileNode::iterator FileNode::begin()
{
    return children.begin();
}

FileNode::iterator FileNode::end()
{
    return children.end();
}



// Overriden functions--------------------------------------------------------------------------------------------------

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    reposition();
    if(checkState(VISIBLE)){
        window.draw(data);
    }
    if (checkState(CHILDREN_VISIBLE))
    {
        for (auto &child : children)
        {
            window.draw(*child.second);
        }
    }
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(checkState(VISIBLE)){
        data.addEventHandler(window, event);
    }
    if(!isLeaf() && MouseEvents<FileItem>::mouseClicked(data, window, event))
    {
        if(!checkState(CHILDREN_VISIBLE)){
            toggleChlidren();
            reposition();
            for (auto &child : children)
            {
                //reposition(); //right???
                child.second->enableState(VISIBLE);
            }
        }
        else{
            toggleChlidren();
            for (auto &child : children)
            {
                child.second->disableState(VISIBLE);
            }
        }
    }
    if(checkState(CHILDREN_VISIBLE)){
        for (auto &child : children){
            std::cout << "EVENT handling for children\n";
            child.second->addEventHandler(window, event);
            if(child.second->isFolder() && MouseEvents<FileItem>::mouseClicked(child.second->getData(), window, event)){
                std::cout << "EVENT handling for children\n";
                //set the POSITION FOR THE NEXT OBJECT!!!!
                ;
            }
        }
    }
}

void FileNode::applySnapshot(const Snapshot *snapshot){}
void FileNode::update(){

}
Snapshot *FileNode::getSnapshot(){}
sf::FloatRect FileNode::getGlobalBounds(){
    sf::FloatRect b = data.getGlobalBounds();
    b.width = b.width + 25;
    if(checkState(CHILDREN_VISIBLE)){
        for (auto &child : children){
            b.height += child.second->getGlobalBounds().height;
        }
    }
}

