#include <iostream>
using namespace std;

struct NodePage
{
    string url;
    NodePage *next;
    NodePage *prev;
    
    NodePage(string val)
    {
        url = val;
        next = nullptr;
        prev = nullptr;
    }
};