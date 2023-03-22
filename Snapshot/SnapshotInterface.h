//
// Created by joseg on 3/16/2023.
//
#ifndef TEXTBOXPROJECT_SNAPSHOTINTERFACE_H
#define TEXTBOXPROJECT_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface
{
    // this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;


    // Virtual destructor to allow proper cleanup of derived classes
    //virtual ~SnapshotInterface() {}
};


#endif //TEXTBOXPROJECT_SNAPSHOTINTERFACE_H
