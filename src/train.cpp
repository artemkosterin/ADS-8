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
    if (first == nullptr) {
        return 0;
    }
    Cage* start = first;
    Cage* end = first->prev;
    return countCages(start, end);
}

int Train::getOpCount() {
    return countOp;
}

int Train::countCages(Cage* start, Cage* end) {
    int length = 1;
    Cage* current = start->next;
    countOp++;
    while (current != end) {
        length++;
        current = current->next;
        countOp++;
    }
    countOp++;
    return length;
}
