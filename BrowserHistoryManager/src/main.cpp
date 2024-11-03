// main.cpp
#include "BrowserHistory.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n--- Browser History Manager ---\n";
    cout << "1. Visit a new page\n";
    cout << "2. Go back\n";
    cout << "3. Go forward\n";
    cout << "4. View history\n";
    cout << "5. Clear history\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BrowserHistory browserHistory;
    int choice;
    string url;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL to visit: ";
                cin >> url;
                browserHistory.visitPage(url);
                break;
            case 2:
                browserHistory.goBack();
                break;
            case 3:
                browserHistory.goForward();
                break;
            case 4:
                browserHistory.viewHistory();
                break;
            case 5:
                browserHistory.clearHistory();
                break;
            case 6:
                cout << "Exiting. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
