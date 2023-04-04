//
// Created by joseg on 3/16/2023.
//
#include "Application.h"

Application::Application(): Application({1280, 720, 32}, "Application"){}

Application::Application(sf::VideoMode videoMode, const std::string& title): window(videoMode, title){}

void Application::runLoop(){
    // add object - polymorphism
    // ADD ANY OBJECTS HERE

    TextInput textInput(window);
    addGUIComponent(textInput);


//    DropdownMenu menu({0,0},{100,40}, "menu"); //parameters -> (position, size, text)
//    //DropdownMenu menu({100,100},{200,60}, "menu"); //parameters -> (position, size, text)
//    menu.addItem("ice cream");
//    menu.addItem("pizza");
//    menu.addItem("chicken");
//    menu.addItem("steak");
//    addGUIComponent(menu);





// Testing the MenuBar class

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
