//
// Created by joseg on 3/18/2023.
//

#include "History.h"
#include <iostream>
std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot)
{
stack.push(snapshot);
}

HistoryNode &History::topHistory()
{
    return stack.top();
}

void History::popHistory()
{
    if(!empty()){
//        delete stack.top().snapshot;
//        stack.top().snapshot = nullptr;
//        delete stack.top().component;
//        stack.top().component = nullptr;
        stack.pop();
    }
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(KeyShortcuts::isUndo()){
        std::cout << "Undo" << std::endl;
        popHistory();
        applySnapshot();
    }
    else if(KeyShortcuts::isRedo()){
        // do later
    }
}

bool History::empty()
{
    return stack.empty();
}

void History::applySnapshot()
{
    if (!empty()) {
        HistoryNode topNode = topHistory();
        Snapshot* snapshot = topNode.snapshot;
        GUIComponent* component = topNode.component;
        component->applySnapshot(*snapshot);
//        if (component && snapshot) {
//
//        }
    }
}
