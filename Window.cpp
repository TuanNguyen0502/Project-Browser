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

class Window
{
public:
    NodeTab *head;
    NodeTab *tail;
    NodeTab *currentTab;
    int size = 0;

    Window()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(Tab tab)
    {
        NodeTab *newNode = new NodeTab(tab);
        currentTab = newNode;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteHead()
    {
        if (head != nullptr)
        {
            NodeTab *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

            currentTab = head;
            delete temp;
            size--;
        }
        else
        {
            cout << "This Window is empty." << endl;
        }
    }

    void deleteTail()
    {
        if (tail != nullptr)
        {
            NodeTab *temp = tail;
            tail = tail->prev;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            currentTab = tail;
            delete temp;
            size--;
        }
        else
        {
            cout << "This Window is empty." << endl;
        }
    }

    bool deleteCurrent()
    {
        if (head->next == nullptr)
        {
            cout << "You cannot delete the only existed Tab !!!" << endl << endl;
            return false;
        }
        if (currentTab == head)
        {
            currentTab = currentTab->next;
            deleteHead();
        }
        else if (currentTab == tail)
        {
            currentTab = currentTab->prev;
            deleteTail();
        }
        else
        {
            NodeTab *temp = currentTab;
            currentTab = currentTab->prev;
            currentTab->next = temp->next;
            temp->next->prev = currentTab;
            delete temp;
            size--;
        }
        return true;
    }

    void display()
    {
        NodeTab *current = head;
        int i = 1;
        cout << "This Window contains: " << endl;
        while (current != nullptr)
        {
            cout << "Tab " << i << " : ";
            i++;
            current->tab.display();
            current = current->next;
        }
        cout << endl;
    }

    void moveNext()
    {
        if (currentTab->next == nullptr)
        {
            cout << "You are at the last Tab." << endl;
        }
        else
            currentTab = currentTab->next;
    }
    void moveBack()
    {
        if (currentTab->prev == nullptr)
            cout << "You are at the first Tab." << endl;
        else
            currentTab = currentTab->prev;
    }

    int getCurrentIndex()
    {
        int i = 1;
        for (NodeTab* p = head; p != nullptr; p = p->next)
        {
            if (p == currentTab)
            {
                return i;
            }
            i++;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};