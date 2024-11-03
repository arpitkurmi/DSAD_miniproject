// main.cpp
#include "Playlist.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n--- Music Playlist Manager ---\n";
    cout << "1. Add a song\n";
    cout << "2. Remove a song by title\n";
    cout << "3. Display playlist\n";
    cout << "4. Show total duration\n";
    cout << "5. Reorder song\n";
    cout << "6. Reverse playlist\n";
    cout << "7. Search song by title or artist\n";
    cout << "8. Save playlist to file\n";
    cout << "9. Load playlist from file\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

// Main function with interactive menu
int main() {
    Playlist myPlaylist;
    int choice, position, newPosition;
    string title, artist, filename;
    float duration;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                cout << "Enter position (-1 for end): ";
                cin >> position;
                myPlaylist.addSong(title, artist, duration, position);
                break;
            case 2:
                cout << "Enter the title of the song to remove: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.removeSong(title);
                break;
            case 3:
                myPlaylist.displayPlaylist();
                break;
            case 4:
                cout << "Total duration: " << myPlaylist.getTotalDuration() << " mins" << endl;
                break;
            case 5:
                cout << "Enter current position: ";
                cin >> position;
                cout << "Enter new position: ";
                cin >> newPosition;
                myPlaylist.reorderSong(position, newPosition);
                break;
            case 6:
                myPlaylist.reversePlaylist();
                cout << "Playlist reversed." << endl;
                break;
            case 7:
                cout << "Enter title or artist to search: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.searchSong(title);
                break;
            case 8:
                cout << "Enter filename to save: ";
                cin >> filename;
                myPlaylist.saveToFile(filename);
                break;
            case 9:
                cout << "Enter filename to load: ";
                cin >> filename;
                myPlaylist.loadFromFile(filename);
                break;
            case 10:
                cout << "Exiting. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
