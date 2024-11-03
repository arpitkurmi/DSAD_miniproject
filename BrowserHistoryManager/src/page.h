// Page.h
#ifndef PAGE_H
#define PAGE_H

#include <string>
using namespace std;

class Page {
public:
    string url;
    Page* next;
    Page* prev;

    Page(string url);
};

#endif
