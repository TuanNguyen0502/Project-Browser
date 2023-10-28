#include <iostream>
using namespace std;

struct NodePage
{
    string url;
    NodePage *next;
    NodePage *prev;
};
struct ListPage
{
    NodePage *head;
    NodePage *tail;
};
struct NodeTab
{
    ListPage listPage
    NodeTab *next;
    NodeTab *prev;
};
