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
    int length = 0;
    do {
        length++;
        currentCage->light = true;
        currentCage = currentCage->next;
    } while (currentCage != first);

    currentCage = first;
    while (currentCage->light) {
        int cagesInLoop = 0;
        currentCage = currentCage->next;

        while (!currentCage->light) {
            currentCage = currentCage->next;
            cagesInLoop++;
        }

        currentCage->light = false;
        countOp += 2 * cagesInLoop;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
