#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    std::string songTitle;
    std::string singerName;

public:
    Song();
    Song(std::string songTitle, std::string singerName);
    std::string getSongTitle();
    std::string getSingerName();
    Song getSong();
    void setSongTitle(std::string songTitle);
    void setSingerName(std::string singerName);
    void print();
    void operator<<(Song&);
};

#endif



#endif // SONG_H_INCLUDED
