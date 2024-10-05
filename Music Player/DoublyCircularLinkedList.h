#ifndef DOUBLYCIRCULARLINKEDLIST_H_INCLUDED
#define DOUBLYCIRCULARLINKEDLIST_H_INCLUDED

using namespace std;

#include "Song.h"

class DoublyCircularLinkedList{
    public:
        class Node{
            private:
                Song song;
                Node* next;
                Node* prev;

                friend class DoublyCircularLinkedList;

            public:
                Node(): next(nullptr), prev(nullptr){}
                Node(Song newSong): song(newSong), next(nullptr), prev(nullptr){}
        };

    private:
        int size;
        Node* head;
        Node* tail;
        Node* cursor;

    public:
        DoublyCircularLinkedList();
        ~DoublyCircularLinkedList();
        bool empty();
        int getSize();
        void addFront(string songTitle, string singerName);
        void addBack(string songTitle, string singerName);
        void addIndex(int index, string songTitle, string singerName);
        void removeFront();
        void removeBack();
        void removeIndex(int index);
        Song getFront();
        Song getBack();
        Song getIndex(int index);
        void printList();
        void printListReverse();
};

#endif // DOUBLYCIRCULARLINKEDLIST_H_INCLUDED
