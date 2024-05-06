// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() : countOp(0), first(nullptr) {}

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
    int length = 1;
    Cage* current = first->next;
    countOp += 2; // Добавляем 2 шага для входа и выхода из первого вагона
    while (current != first) {
        length++;
        current = current->next;
        countOp += 2; // Добавляем 2 шага для перехода из вагона в вагон и обратно
    }
    countOp += 2; // Добавляем 2 шага для возвращения в исходный вагон
    return length;
}

int Train::getOpCount() {
    return countOp;
}
