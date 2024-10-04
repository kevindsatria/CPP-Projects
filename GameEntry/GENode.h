#ifndef GENODE_H_INCLUDED
#define GENODE_H_INCLUDED

#include "GameEntry.h"

class GENode {
    private:
        GameEntry elem;
        GENode* next;

        friend class GameEntry;
        friend class Scores;

    public:
        GENode() : next(nullptr) {}
        GENode(GameEntry& elem) : elem(elem), next(nullptr) {}
};

#endif // GENODE_H_INCLUDED
