// Song.cpp
#include "Song.h"

Song::Song(string t, string a, float d) {
    title = t;
    artist = a;
    duration = d;
    next = nullptr; // Initialize next pointer to nullptr
}
