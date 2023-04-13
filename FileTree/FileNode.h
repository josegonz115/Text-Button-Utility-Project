//
// Created by joseg on 4/9/2023.
//

#ifndef TEXTBOXPROJECT_FILENODE_H
#define TEXTBOXPROJECT_FILENODE_H
#include "../GUIComponent/GUIComponent.h"
#include "FileItem.h"
#include "Image.h"
#include "../MouseEvents/MouseEvents.h"

// FileNode - This is the Node for your File Tree.
// It will contain a FileItem as the data, and Node* vector to hold the nodes children
// (you can also use a map or linked list if you choose).

class FileNode : public GUIComponent
{
private:
    const float WIDTH_NODE = 100, HEIGHT_NODE = 25;
    //This is the data represented in the tree
    FileItem data;

    //this is all the child nodes in the tree, a vector would also work just fine
    std::map<std::string, FileNode*> children;

    //this tells the draw function whether to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition(int depth = 1) const;
public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    FileNode();
    FileNode(Image icon, std::string text, sf::Vector2f size = {100.f, 20.f}, sf::Vector2f position = {10.f, 10.f});

    // Accessors--------------------------------------------------------------------------------------------------------
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    std::map<std::string, FileNode*>& getChildren();

    bool isFolder() const;

    // Mutators---------------------------------------------------------------------------------------------------------

    void setData(const FileItem &_data);
    // this will add a child to the node.
    void addChild(const FileItem& _data);


    //iterators
    iterator begin();
    iterator end();

    //overridden functions---------------------------------------------------------------------------------------------
    // this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;


    //This is not currently used
    void applySnapshot(const Snapshot* snapshot) override;
    //does nothing now
    void update() override;
    //does nothing now
    Snapshot* getSnapshot() override;
    //does nothing now
    sf::FloatRect getGlobalBounds();
};


#endif //TEXTBOXPROJECT_FILENODE_H
