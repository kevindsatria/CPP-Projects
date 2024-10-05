#include "Song.h"
#include <iostream>

Song::Song() : songTitle(""), singerName("") {}

Song::Song(std::string songTitle, std::string singerName) : songTitle(songTitle), singerName(singerName) {}

std::string Song::getSongTitle() {
    return songTitle;
}

std::string Song::getSingerName() {
    return singerName;
}

Song Song::getSong() {
    return *this;
}

void Song::setSongTitle(std::string songTitle) {
    this->songTitle = songTitle;
}

void Song::setSingerName(std::string singerName) {
    this->singerName = singerName;
}

void Song::print() {
    std::cout << "Song:\t" << this->songTitle << std::endl;
    std::cout << "Singer:\t" << this->singerName << std::endl;
}

void Song::operator<<(Song& song){
    std::cout << "Song:\t" << this->songTitle << std::endl;
    std::cout << "Singer:\t" << this->singerName << std::endl;
}
