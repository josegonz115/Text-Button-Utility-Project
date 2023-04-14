//
// Created by joseg on 3/16/2023.
//
#include "Application.h"

Application::Application(): Application({1280, 720, 32}, "Application"){}

Application::Application(sf::VideoMode videoMode, const std::string& title): window(videoMode, title){}

void Application::runLoop(){
    // add object - polymorphism
    // ADD ANY OBJECTS HERE

    //  TEXT INPUT TEST ----------------------------------------------------------------------------------------
//    TextInput textInput(window);
//    addGUIComponent(textInput);

    //  DROPDOWN MENU TEST -------------------------------------------------------------------------------------
//    DropdownMenu menu({0,0},{100,40}, "menu"); //parameters -> (position, size, text)
//    //DropdownMenu menu({100,100},{200,60}, "menu"); //parameters -> (position, size, text)
//    menu.addItem("ice cream");
//    menu.addItem("pizza");
//    menu.addItem("chicken");
//    menu.addItem("steak");
//    addGUIComponent(menu);






    // MENUBAR TEST -----------------------------------------------------------------------------------------------------
//    MenuBar menuBar({0,0},{100,40}, "Menu 1");
//    menuBar.addMenu("Menu 2");
//    menuBar.addMenu("Menu 3");
//
//    menuBar.addItem("Menu 1", "Item 1");
//    menuBar.addItem("Menu 1", "Item 2");
//    menuBar.addItem("Menu 1", "Item 3");
//    menuBar.addItem("Menu 1", "Item 4");
//
//    menuBar.addItem("Menu 2", "Item 1");
//    menuBar.addItem("Menu 2", "Item 2");
//    menuBar.addItem("Menu 2", "Item 3");
//    menuBar.addItem("Menu 2", "Item 4");
//
//    menuBar.addItem("Menu 3", "Item 1");
//    menuBar.addItem("Menu 3", "Item 2");
//    menuBar.addItem("Menu 3", "Item 3");
//    menuBar.addItem("Menu 3", "Item 4");
//    addGUIComponent(menuBar);

    // FILETREE TEST---------------------------------------------------------------------------------------
//    FileItem fileItem1(Image::_FOLDER, "Folder 1", {100, 20}, {10,10});
//    //fileItem1.setFillColor(sf::Color::Red);
//    addGUIComponent(fileItem1);

    //Image icon, std::string text, sf::Vector2f size, sf::Vector2f position
//    FileNode folder1(Image::_FOLDER, "folder 1");
//    FileItem file1(Image::_FILE, "file 1");
//    FileItem folder2(Image::_FOLDER, "folder 2");
//    FileItem file2(Image::_FILE, "file 2");
//    folder1.addChild(file1);
//    folder1.addChild(folder2);
//    folder1.addChild(file2);
//
//    FileItem file3(_FILE, "file 3");
//
//    std::map<std::string, FileNode*> children = folder1.getChildren();
//    children["folder 2"]->addChild(file3);
//    addGUIComponent(folder1);
    //HEY LOOK HERE NOW IT IS TIME TO TEST THE FILETREEEEE
//    FileTree fileTree;
//    fileTree.push("FILES");
//    fileTree.push("FILES", "folder 1", _FOLDER);
//    fileTree.push("FILES", "recipes.txt");
//    fileTree.push("folder 1", "numbers.txt");
//
//    addGUIComponent(fileTree);
    // END OF FILE TREE TEST -------------------------------------------------------------------------------------


    while(window.isOpen()){
        eventListener();
        window.clear();
        // GUIComponents are children of drawable objects
        for(GUIComponent* o: objects){
            window.draw(*o);
            o->update();
        }
        window.display();
    }
}

void Application::eventListener()
{
    sf::Event event;
    while(window.pollEvent(event)){
        if(sf::Event::Closed == event.type){
            window.close();
        }
        for(GUIComponent* o: objects){
            o->addEventHandler(window,event);
        }
        History::addEventHandler(window,event);
    }
}

void Application::run()
{
    runLoop();
}

void Application::addGUIComponent(GUIComponent &object)
{
    objects.push_back(&object);
}
