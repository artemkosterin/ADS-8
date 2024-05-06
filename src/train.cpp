// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

Train::~Train() {
    if (first != nullptr) {
        Cage* current = first->next;
        while (current != first) {
            Cage* next = current->next;
            delete current;
            current = next;
        }
        delete first;
    }
}

void Train::addCage(bool cond) {
    if (!first) {
        Cage* newCage = new Cage;
        newCage->light = cond;
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    } else {
        Cage* lastCage = first->prev;
        Cage* newCage = new Cage;
        newCage->light = cond;
        newCage->next = first;
        newCage->prev = lastCage;
        lastCage->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (!first) {
        return 0;
    }

    Cage* currentCage = first;
    currentCage->light = true;
    int length = 1;
    int steps = 1;

    while (currentCage->light) {
        int cagesInLoop = 1;
        currentCage = currentCage->next;

        while (!currentCage->light) {
            currentCage = currentCage->next;
            cagesInLoop++;
        }

        currentCage->light = false;
        countOp += 2 * cagesInLoop;
        length = cagesInLoop;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
