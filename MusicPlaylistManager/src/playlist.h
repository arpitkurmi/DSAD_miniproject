// Playlist.h
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <string>

class Playlist {
    Song* head;

public:
    Playlist();
    ~Playlist();

    // Core Operations
    void addSong(string title, string artist, float duration, int position = -1);
    void removeSong(std::string title);
    void displayPlaylist();
    float getTotalDuration();
    void reorderSong(int currentPos, int newPos);
    void reversePlaylist();
    void searchSong(string query);
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

#endif
