#ifndef GAMEENTRY_H_INCLUDED
#define GAMEENTRY_H_INCLUDED

#include <iostream>

class GameEntry {
    private:
        std::string name;
        int score;

    public:
        GameEntry() : name(" "), score(0) {}
        GameEntry(std::string name, int score) : name(name), score(score) {}
        ~GameEntry() {}
        std::string getName() { return name; }
        int getScore() { return score; }
};

#endif // GAMEENTRY_H_INCLUDED
