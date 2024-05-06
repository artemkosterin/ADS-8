// Copyright 2022 NNTU-CS
#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
    struct Cage {
        bool light;
        Cage* next;
        Cage* prev;
    };
    int countOp;
    Cage* first;
    bool isFirstCageAdded;

public:
    Train();
    void addCage(bool light);
    int getLength();
    int getOpCount();
};

#endif // TRAIN_H
