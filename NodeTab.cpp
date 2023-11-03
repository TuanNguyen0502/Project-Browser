#include <iostream>
using namespace std;
#include "Tab.cpp"

struct NodeTab
{
    Tab tab;
    NodeTab *next;
    NodeTab *prev;

    NodeTab(Tab val)
    {
        tab = val;
        next = nullptr;
        prev = nullptr;
    }
};