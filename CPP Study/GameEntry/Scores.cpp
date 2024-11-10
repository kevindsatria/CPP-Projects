#include <iostream>
#include "Scores.h"

using namespace std;

Scores::Scores(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

Scores::~Scores() {
    while (head != nullptr) {
        GENode* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
    }
    tail = nullptr;
}

bool Scores::empty() { return size == 0; }

void Scores::sort(GameEntry& elem) {
    GENode* node = new GENode(elem);

    if (empty()) {
        head = node;
        tail = node;
    } else if (elem.getScore() > head->elem.getScore()) {
        node->next = head;
        head = node;
    } else {
        GENode* prev = nullptr;
        GENode* current = head;

        while (current != nullptr && elem.getScore() <= current->elem.getScore()) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            prev->next = node;
            tail = node;
        } else {
            node->next = current;
            prev->next = node;
        }
    }

    size++;

    if (size > capacity) {
        remove(size - 1);
    }
}

void Scores::add(GameEntry& elem) {
    if (empty()) {
        sort(elem);
    } else if (elem.getScore() > tail->elem.getScore() || size < capacity) {
        sort(elem);
    } else {
        cout << "Max Capacity Reached[" << elem.getName() << ", "<< elem.getScore() << "]: must have higher than the lowest score" << endl;
    }
}

GameEntry Scores::remove(int index) {
    GENode* toDelete = nullptr;
    if (empty())
        cout << "List is already empty, nothing to remove" << endl;
    else {
        GENode* iterator = head;
        for (int i = 0; i < index - 1; i++)
            iterator = iterator->next;

        toDelete = iterator->next;
        iterator->next = toDelete->next;

        if (index == size - 1)
            tail = iterator;

        size--;
    }
    return toDelete->elem;
}

int Scores::getSize() { return size; }

void Scores::printAll() {
    if (empty())
        cout << "List is empty" << endl;
    else {
        GENode* iterator = head;

        for (int i = 0; i < size; i++) {
            cout << "Index[" << i << "]: " << iterator->elem.getName() << ", " << iterator->elem.getScore() << endl;
            iterator = iterator->next;
        }
    }
}
