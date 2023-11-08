#include <iostream>
using namespace std;

struct NodeHistory
{
    string his;
    NodeHistory* next;
    NodeHistory* prev;

    NodeHistory(string s)
    {
        his = s;
        next = nullptr;
        prev = nullptr;
    }
};

class ListHistory
{
public:
    NodeHistory *head;
    NodeHistory *tail;
    NodeHistory *currentHistory;
    int size = 0;

    ListHistory()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(string his)
    {
        NodeHistory *newNode = new NodeHistory(his);
        currentHistory = newNode;
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
            NodeHistory *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

            currentHistory = head;
            delete temp;
            size--;
        }
        else
        {
            cout << "This List History is empty." << endl;
        }
    }

    void deleteTail()
    {
        if (tail != nullptr)
        {
            NodeHistory *temp = tail;
            tail = tail->prev;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            currentHistory = tail;
            delete temp;
            size--;
        }
        else
        {
            cout << "This List History is empty." << endl;
        }
    }

    void display()
    {
        NodeHistory *current = head;
        while (current != nullptr)
        {
            cout << current->his << endl;
            current = current->next;
        }
        cout << endl;
    }

    void displayLatest()
    {
        cout << tail->his << endl << endl;
    }
    
    void displayOldest()
    {
        cout << head->his << endl << endl;
    }

    void moveNext()
    {
        if (currentHistory->next == nullptr)
        {
            cout << "You are at the last string." << endl;
        }
        else
            currentHistory = currentHistory->next;
    }
    
    void moveBack()
    {
        if (currentHistory->prev == nullptr)
        {
            cout << "You are at the first string." << endl;
        }
        else
            currentHistory = currentHistory->prev;
    }
};