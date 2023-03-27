//
// Created by joseg on 3/16/2023.
//
#include "Application.h"

Application::Application(): Application({720, 420, 32}, "Application"){}

Application::Application(sf::VideoMode videoMode, const std::string& title): window(videoMode, title){}

void Application::runLoop(){
    // add object - polymorphism
    // ADD ANY OBJECTS HERE
    DropdownMenu menu({40,40},{300,60}, "menu"); //parameters -> (position, size, text)
    menu.addItem("ice cream");
    menu.addItem("pizza");
    menu.addItem("chicken");
    menu.addItem("steak");
    addGUIComponent(menu);

    //TextInput textInput(window);
    //addGUIComponent(textInput);

    while(window.isOpen()){
        eventListener();
        window.clear();
        // GUIComponents are children of drawable objects
        for(GUIComponent* o: objects){
            window.draw(*o);
            o->update();
        }
        window.display();
        // Record the current state of TextInput after handling events
//        Snapshot* snapshot = new Snapshot(textInput.getSnapshot());
//        History::pushHistory({snapshot,&textInput});
    }
}

void Application::eventListener()
{
    Snapshot* snapshot;

    sf::Event event;
    while(window.pollEvent(event)){
        if(sf::Event::Closed == event.type){
            window.close();
        }
        for(GUIComponent* o: objects){
            o->addEventHandler(window,event);
//            // Record the current state of TextInput after handling events
//            snapshot = new Snapshot(o->getSnapshot());
//            History::pushHistory({snapshot,o});
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
