#ifndef SCORES_H_INCLUDED
#define SCORES_H_INCLUDED
#include "GENode.h"

class Scores {
    private:
        int capacity;
        int size;
        GENode* head;
        GENode* tail;

    public:
        Scores(int capacity);
        ~Scores();
        bool empty();
        void sort(GameEntry& elem);
        void add(GameEntry& elem);
        GameEntry remove(int index);
        int getSize();
        void printAll();
};

#endif // SCORES_H_INCLUDED
