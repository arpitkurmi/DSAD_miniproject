// BrowserHistory.cpp
#include "BrowserHistory.h"
#include <iostream>
using namespace std;

BrowserHistory::BrowserHistory() {
    current = nullptr;
}

BrowserHistory::~BrowserHistory() {
    clearHistory();
}

void BrowserHistory::visitPage(string url) {
    Page* newPage = new Page(url);

    if (current != nullptr) {
        current->next = newPage;
        newPage->prev = current;
    }
    current = newPage;

    cout << "Visited: " << url << endl;
}

void BrowserHistory::goBack() {
    if (current == nullptr || current->prev == nullptr) {
        cout << "No previous page." << endl;
        return;
    }
    current = current->prev;
    cout << "Went back to: " << current->url << endl;
}

void BrowserHistory::goForward() {
    if (current == nullptr || current->next == nullptr) {
        cout << "No forward page." << endl;
        return;
    }
    current = current->next;
    cout << "Moved forward to: " << current->url << endl;
}

void BrowserHistory::viewHistory() {
    if (current == nullptr) {
        cout << "History is empty." << endl;
        return;
    }

    Page* temp = current;
    while (temp->prev != nullptr) {
        temp = temp->prev;
    }

    cout << "Browsing History:" << endl;
    while (temp != nullptr) {
        cout << temp->url << (temp == current ? " <- Current" : "") << endl;
        temp = temp->next;
    }
}

void BrowserHistory::clearHistory() {
    while (current != nullptr && current->prev != nullptr) {
        current = current->prev;
    }
    Page* temp = current;
    while (temp != nullptr) {
        Page* nextPage = temp->next;
        delete temp;
        temp = nextPage;
    }
    current = nullptr;
    cout << "History cleared." << endl;
}
