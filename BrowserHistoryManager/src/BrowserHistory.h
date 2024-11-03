// BrowserHistory.h
#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include "Page.h"

class BrowserHistory {
    Page* current;

public:
    BrowserHistory();
    ~BrowserHistory();

    void visitPage(string url);
    void goBack();
    void goForward();
    void viewHistory();
    void clearHistory();
};

#endif
