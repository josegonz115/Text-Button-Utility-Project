//
// Created by joseg on 3/16/2023.
//

#ifndef TEXTBOXPROJECT_APPLICATION_H
#define TEXTBOXPROJECT_APPLICATION_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "GUIComponent/GUIComponent.h"
#include "TextInput/TextInput.h"
#include "Snapshot/History.h"
#include "KeyShortcuts/KeyShortcuts.h"
#include "Dropdown/DropdownMenu.h"
#include "MenuBar/MenuBar.h"
#include "FileTree/FileTree.h"


#include "FileTree/FileNode.h"




class Application
{
private:
    sf::RenderWindow window;
    std::vector<GUIComponent*> objects;

    void runLoop();
    void eventListener();

public:
    Application();
    Application(sf::VideoMode videoMode, const std::string& title);

    void run();

    void addGUIComponent(GUIComponent &object);
};


#endif //TEXTBOXPROJECT_APPLICATION_H
