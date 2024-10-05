#include "DoublyCircularLinkedList.h"
#include <iostream>

using namespace std;

DoublyCircularLinkedList::DoublyCircularLinkedList(): size(0), head(nullptr), tail(nullptr){}
DoublyCircularLinkedList::~DoublyCircularLinkedList(){
    while(!empty())
        removeFront();
}
bool DoublyCircularLinkedList::empty(){
    if(size == 0)
        return true;
    else
        return false;
}
int DoublyCircularLinkedList::getSize(){
    return size;
}
void DoublyCircularLinkedList::addFront(string songTitle, string singerName){
    Song newSong(songTitle, singerName);
    Node* newNode = new Node(newSong);

    if(empty()){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;
    } else{
        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }

    size++;
}
void DoublyCircularLinkedList::addBack(string songTitle, string singerName){
    if(empty()){
        addFront(songTitle, singerName);
    } else{
        Song newSong(songTitle, singerName);
        Node* newNode = new Node(newSong);

        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        tail = newNode;
        size++;
    }
}
void DoublyCircularLinkedList::addIndex(int index, string songTitle, string singerName){
    if (empty()) {
        addFront(songTitle, singerName);
    } else if (index > 0 && index < size) {
        Song newSong(songTitle, singerName);
        Node* newNode = new Node(newSong);

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        current->next->prev = newNode;
        current->next = newNode;

        size++;
    } else {
        cout << "Index Size is either too large or too small" << endl;
    }
}
void DoublyCircularLinkedList::removeFront(){
    if(!empty()){
        Node* dummy = head;

        if(size == 1){
            head = nullptr;
            tail = nullptr;
        } else{
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete dummy;
        size--;
    } else {
        cout << "List is empty" << endl;
    }
}
void DoublyCircularLinkedList::removeBack(){
    if(!empty()){
        Node* dummy = tail;

        if(size == 1){
            head = nullptr;
            tail = nullptr;
        } else{
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }

        delete dummy;
        size--;
    } else{
        cout << "List is empty" << endl;
    }
}
void DoublyCircularLinkedList::removeIndex(int index){
    if (empty()) {
        cout << "List is empty" << endl;
        return;
    }

    if (index < 0 || index >= size) {
        cout << "Index is either too big or too small" << endl;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    Node* toDelete = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;

    if (index == 0) {
        head = current->next;
    } else if (index == size - 1) {
        tail = current->prev;
    }

    delete toDelete;
    size--;
}
Song DoublyCircularLinkedList::getFront(){
    if(!empty()){
        return head->song.getSong();
    } else {
        cout << "List is empty." << endl;
        return Song();
    }
}
Song DoublyCircularLinkedList::getBack(){
    if(!empty()){
        return tail->song.getSong();
    } else {
        cout << "List is empty." << endl;
        return Song();
    }
}
Song DoublyCircularLinkedList::getIndex(int index){
    if (empty()) {
        cout << "List is empty." << endl;
        return Song();
    }

    if (index < 0 || index >= size) {
        cout << "Index is out of range." << endl;
        return Song();
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->song.getSong();
}
void DoublyCircularLinkedList::printList(){
    if (empty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    for (int i = 0; i < size; ++i) {
        current->song.print();
        cout << "------------------------------------------------------" << endl;
        current = current->next;
    }
}
void DoublyCircularLinkedList::printListReverse(){
    if (empty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail;
    for(int i = size-1; i >= 0; i--){
        current->song.print();
        cout << "------------------------------------------------------" << endl;
        current = current->prev;
    }
}
