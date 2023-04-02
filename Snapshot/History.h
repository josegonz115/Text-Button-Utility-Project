//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_HISTORY_H
#define TEXTBOXPROJECT_HISTORY_H

#include "SnapshotInterface.h"
#include "../GUIComponent/GUIComponent.h"
#include "../KeyShortcuts/KeyShortcuts.h"
#include <stack>

struct HistoryNode
{
    Snapshot* snapshot;
    GUIComponent* component;

    //HistoryNode* next;
    //HistoryNode* previous;
};

class History  {
private:
    static std::stack<HistoryNode> stack;
    History() = default; //disallow creating instances = static

    //static std::map<std::string, GUIComponent*> components;// added
public:
    static HistoryNode& topHistory();
    static void pushHistory(const HistoryNode& snapshot);
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);


    static bool empty();
    static int size();

};


#endif //TEXTBOXPROJECT_HISTORY_H
