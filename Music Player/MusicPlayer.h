#ifndef MUSICPLAYER_H_INCLUDED
#define MUSICPLAYER_H_INCLUDED

#include "DoublyCircularLinkedList.h"

using namespace std;

class MusicPlayer{
    private:
        string playlistName;
        DoublyCircularLinkedList playerList;
        int cursor;

    public:
        MusicPlayer();
        MusicPlayer(string playlistName);
        void play();
        void next();
        void prev();
        void add(Song& song);
        void add(string songTitle, string singerName);
        void removeSong();
        int getCursor();
        DoublyCircularLinkedList& getPlayerList();
        void print(bool t);
};

#endif
