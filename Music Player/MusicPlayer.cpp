#include "MusicPlayer.h"
#include <iostream>

using namespace std;

MusicPlayer::MusicPlayer(): playlistName("Default"), cursor(0){}
MusicPlayer::MusicPlayer(string playlistName): playlistName(playlistName), cursor(0){}
void MusicPlayer::play(){
    if(playerList.empty())
        cout << "Playlist is empty" << endl;
    else
        cout << "Playing Song: \"" << playerList.getIndex(cursor).getSongTitle() << "\", by " << playerList.getIndex(cursor).getSingerName() << endl;
}
void MusicPlayer::next(){
    if(!playerList.empty()){
        if(cursor < playerList.getSize()){
            cursor++;
        if(cursor == playerList.getSize())
            cursor = 0;
        play();
    } else
        cout << "Playlist is empty" << endl;
    }
}
void MusicPlayer::prev(){
    if(!playerList.empty()){
        if(cursor == 0)
            cursor = playerList.getSize()-1;
        else if(cursor > 0)
            cursor--;
        play();
    } else
        cout << "Playlist is empty" << endl;
}
void MusicPlayer::add(Song& song){
    if(playerList.empty())
        playerList.addFront(song.getSongTitle(), song.getSingerName());
    else{
        if(playerList.getSize() == 1)
            playerList.addBack(song.getSongTitle(), song.getSingerName());
        else if(playerList.getSize() > 1)
            playerList.addIndex(cursor + 1, song.getSongTitle(), song.getSingerName());
    }
}
void MusicPlayer::add(string songTitle, string singerName){
    if(playerList.empty())
        playerList.addFront(songTitle, singerName);
    else{
        if(playerList.getSize() == 1)
            playerList.addBack(songTitle, singerName);
        else if(playerList.getSize() > 1)
            playerList.addIndex(cursor + 1, songTitle, singerName);
    }
}
void MusicPlayer::removeSong(){
    if(playerList.empty())
        cout << "List is already empty" << endl;
    else if(playerList.getSize() == 1)
        playerList.removeFront();
    else if(playerList.getSize() > 1)
        playerList.removeIndex(cursor);
}
int MusicPlayer::getCursor(){
    return cursor;
}
DoublyCircularLinkedList& MusicPlayer::getPlayerList(){
    return playerList;
}
void MusicPlayer::print(bool t){
    if(!playerList.empty()){
        if(t == true)
            playerList.printList();
        else
            playerList.printListReverse();
    } else
        cout << "List is empty" << endl;
}
