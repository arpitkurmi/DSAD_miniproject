// Song.h
#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
    string title;
    string artist;
    float duration;
    Song* next;

    // Constructor
    Song(string t, string a, float d);
};

#endif
