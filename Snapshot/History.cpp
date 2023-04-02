//
// Created by joseg on 3/18/2023.
//

#include "History.h"
#include <iostream>

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot)
{
    std::cout << "Pushing to history\n";
    stack.push(snapshot);
}

HistoryNode &History::topHistory()
{
    return stack.top();
}

void History::popHistory()
{
    if(!stack.empty()){
        topHistory().component->applySnapshot(topHistory().snapshot); // apply snapshot to component
        stack.pop();
    }
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(KeyShortcuts::isUndo()){
        std::cout << "Undo" << std::endl;
        popHistory();
    }
    else if(KeyShortcuts::isRedo()){
        // do later
    }
}

bool History::empty()
{
    return stack.empty();
}

int History::size()
{
    return stack.size();
}
