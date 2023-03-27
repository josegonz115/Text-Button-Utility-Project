//
// Created by joseg on 3/16/2023.
//

#ifndef TEXTBOXPROJECT_STATES_H
#define TEXTBOXPROJECT_STATES_H
#include <SFML/Graphics.hpp>

enum ObjectState{
    VISIBLE,
    ACTION,
    HIGHLIGHTED,
    DISABLED,

    LAST_STATE
};

class States
{
private:
    std::map<ObjectState, bool> states;
public:
    States();
    void enableState(ObjectState state);
    void disableState(ObjectState state);
    bool checkState(ObjectState state) const;
    void toggleState(ObjectState state);
};


#endif //TEXTBOXPROJECT_STATES_H
