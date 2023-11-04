#include <iostream>
using namespace std;
#include "Window.cpp"

struct NodeWindow
{
    Window window;
    NodeWindow *next;
    NodeWindow *prev;

    NodeWindow(Window val)
    {
        window = val;
        next = nullptr;
        prev = nullptr;
    }
};

class ListWindow
{
public:
    NodeWindow *head;
    NodeWindow *tail;
    NodeWindow *currentWindow;
    int size = 0;

    ListWindow()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(Window window)
    {
        NodeWindow *newNode = new NodeWindow(window);
        currentWindow = newNode;
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
            NodeWindow *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

            currentWindow = head;
            delete temp;
            size--;
        }
        else
        {
            cout << "This ListWindow is empty." << endl;
        }
    }

    void deleteTail()
    {
        if (tail != nullptr)
        {
            NodeWindow *temp = tail;
            tail = tail->prev;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            currentWindow = tail;
            delete temp;
            size--;
        }
        else
        {
            cout << "This ListWindow is empty." << endl;
        }
    }

    bool deleteCurrent()
    {
        if (head->next == nullptr)
        {
            cout << "You cannot delete the only existed Window !!!" << endl << endl;
            return false;
        }
        if (currentWindow == head)
        {
            currentWindow = currentWindow->next;
            deleteHead();
        }
        else if (currentWindow == tail)
        {
            currentWindow = currentWindow->prev;
            deleteTail();
        }
        else
        {
            NodeWindow *temp = currentWindow;
            currentWindow = currentWindow->prev;
            currentWindow->next = temp->next;
            temp->next->prev = currentWindow;
            delete temp;
            size--;
        }
        return true;
    }

    void display()
    {
        NodeWindow *current = head;
        while (current != nullptr)
        {
            current->window.display();
            cout << endl;
            current = current->next;
        }
        cout << endl;
    }

    void moveNext()
    {
        if (currentWindow->next == nullptr)
        {
            cout << "You are at the last Window." << endl;
        }
        else
            currentWindow = currentWindow->next;
    }
    void moveBack()
    {
        if (currentWindow->prev == nullptr)
        {
            cout << "You are at the first Window." << endl;
        }
        else
            currentWindow = currentWindow->prev;
    }

    int getCurrentIndex()
    {
        int i = 1;
        for (NodeWindow* p = head; p != nullptr; p = p->next)
        {
            if (p == currentWindow)
            {
                return i;
            }
            i++;
        }
    }
};