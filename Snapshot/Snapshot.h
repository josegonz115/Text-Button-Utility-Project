//
// Created by joseg on 3/19/2023.
//

#ifndef TEXTBOXPROJECT_SNAPSHOT_H
#define TEXTBOXPROJECT_SNAPSHOT_H

class GUIComponent;

class Snapshot {
private:
    GUIComponent* _object;

public:
    Snapshot() : _object(nullptr) {}

    //setter
    Snapshot& operator=(GUIComponent* object) {
        _object = object;
        return *this;
    }

    //getter
    operator GUIComponent*() const {
        return _object;
    }
};
#endif //TEXTBOXPROJECT_SNAPSHOT_H
