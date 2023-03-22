//
// Created by joseg on 3/16/2023.
//

#include "States.h"

States::States(){
    for(int i = 0; i < LAST_STATE; i++){
        states[static_cast<ObjectState>(i)] = false;
    }
}


void States::enableState(ObjectState state)
{
    states[state] = true;
}

void States::disableState(ObjectState state)
{
    states[state] = false;
}

bool States::checkState(ObjectState state) const
{
    return states.at(state);
}

void States::toggleState(ObjectState state)
{
    states[state] = !states[state];
}
