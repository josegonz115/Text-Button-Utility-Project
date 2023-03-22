//
// Created by joseg on 3/18/2023.
//

#ifndef TEXTBOXPROJECT_KEYSHORTCUTS_H
#define TEXTBOXPROJECT_KEYSHORTCUTS_H
#include <SFML/Graphics.hpp>

class KeyShortcuts
{
private:
    KeyShortcuts(); //disallow creating instances = static

public:
    static bool isUndo();

    //create more like redo - would have to create another stack in history for this
    static bool isRedo();
};


#endif //TEXTBOXPROJECT_KEYSHORTCUTS_H
