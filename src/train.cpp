// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    Cage* current = first;
    while (current != nullptr) {
        Cage* next = current->next;
        delete current;
        current = next;
        if (current == first) {
            break;
        }
    }
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage{light, nullptr, nullptr};
    if (first == nullptr) {
        first = newCage;
        newCage->next = newCage;
        newCage->prev = newCage;
    } else {
        Cage* last = first->prev;
        newCage->next = first;
        newCage->prev = last;
        first->prev = newCage;
        last->next = newCage;
    }
}

int Train::getLength() {
    return countCages();
}

int Train::getOpCount() {
    return countOp;
}

int Train::countCages() {
    if (first == nullptr) {
        return 0;
    }
    int length = 1;
    Cage* current = first->next;
    while (current != first) {
        length++;
        current = current->next;
    }
    return length;
}
