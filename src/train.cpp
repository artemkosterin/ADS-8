// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage{light, nullptr, nullptr};
    if (!first) {
        first = newCage;
        first->next = first;
        first->prev = first;
        countOp++;
    } else {
        Cage* lastCage = first->prev;
        lastCage->next = newCage;
        newCage->prev = lastCage;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (!first) return 0;
    int length = 0;
    Cage* currentCage = first;
    do {
        length++;
        currentCage = currentCage->next;
    } while (currentCage != first);
    return length;
}

int Train::getOpCount() {
    return countOp;
}
