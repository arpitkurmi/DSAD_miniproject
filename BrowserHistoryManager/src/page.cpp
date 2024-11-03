// Page.cpp
#include "Page.h"

Page::Page(string url) {
    this->url = url;
    next = nullptr;
    prev = nullptr;
}
