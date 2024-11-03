// Playlist.cpp
#include "Playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist() {
    head = nullptr; // Initialize the head of the list
}

Playlist::~Playlist() {
    Song* current = head;
    while (current != nullptr) {
        Song* next = current->next;
        delete current;
        current = next;
    }
}

// Add a song to the specific position in the playlist
void Playlist::addSong(string title, string artist, float duration, int position) {
    Song* newSong = new Song(title, artist, duration);

    if (position == 0 || head == nullptr) { // Insert at head
        newSong->next = head;
        head = newSong;
        return;
    }

    Song* temp = head;
    int currentPos = 0;
    while (temp->next != nullptr && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    newSong->next = temp->next;
    temp->next = newSong;
}


// Remove a song by title
#include "Playlist.h"
#include <iostream>
using namespace std;

void Playlist::removeSong(string title) {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Song* temp = head;
    Song* prev = nullptr;

    // If the song to be deleted is the head node
    if (temp != nullptr && temp->title == title) {
        head = temp->next;
        delete temp;
        return;
    }

    // Search for the song to delete
    while (temp != nullptr && temp->title != title) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Song not found!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}




// Display the playlist
void Playlist::displayPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Song* temp = head;
    while (temp != nullptr) {
        cout << temp->title << " by " << temp->artist << " (" << temp->duration << " mins)" << endl;
        temp = temp->next;
    }
}
//display total duration
float Playlist::getTotalDuration() {
    float totalDuration = 0;
    Song* temp = head;
    while (temp != nullptr) {
        totalDuration += temp->duration;
        temp = temp->next;
    }
    return totalDuration;
}
// Recording songs
void Playlist::reorderSong(int currentPos, int newPos) {
    if (head == nullptr || currentPos == newPos) return;

    Song* prevCurrent = nullptr;
    Song* current = head;
    int pos = 0;

    // Find the song at currentPos
    while (current != nullptr && pos < currentPos) {
        prevCurrent = current;
        current = current->next;
        pos++;
    }
    if (current == nullptr) return;

    // Remove the song from its current position
    if (prevCurrent) prevCurrent->next = current->next;
    else head = current->next;

    // Insert the song at the new position
    if (newPos == 0) {
        current->next = head;
        head = current;
        return;
    }

    Song* temp = head;
    int newPosCount = 0;
    while (temp != nullptr && newPosCount < newPos - 1) {
        temp = temp->next;
        newPosCount++;
    }

    current->next = temp->next;
    temp->next = current;
}
//Reverse playlist
void Playlist::reversePlaylist() {
    Song* prev = nullptr;
    Song* current = head;
    Song* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
//Search for he song by titile and artist 
void Playlist::searchSong(string query) {
    Song* temp = head;
    int position = 0;
    bool found = false;

    while (temp != nullptr) {
        if (temp->title == query || temp->artist == query) {
            cout << "Found at position " << position << ": " << temp->title 
                 << " by " << temp->artist << " (" << temp->duration << " mins)" << endl;
            found = true;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Song not found." << endl;
    }
}
//Save and load playlist
#include <fstream>

void Playlist::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Unable to open file for saving." << endl;
        return;
    }

    Song* temp = head;
    while (temp != nullptr) {
        file << temp->title << "," << temp->artist << "," << temp->duration << endl;
        temp = temp->next;
    }
    file.close();
    cout << "Playlist saved to " << filename << endl;
}

void Playlist::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file for loading." << endl;
        return;
    }

    string title, artist, durationStr;
    float duration;
    while (getline(file, title, ',') && getline(file, artist, ',') && getline(file, durationStr)) {
        duration = stof(durationStr);
        addSong(title, artist, duration);
    }
    file.close();
    cout << "Playlist loaded from " << filename << endl;
}

