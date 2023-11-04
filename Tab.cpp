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

class Tab
{
public:
    NodePage *head;
    NodePage *tail;
    NodePage *currentPage;
    int size = 0;

    Tab()
    {
        head = nullptr;
        tail = nullptr;
        currentPage = new NodePage("NULL");
    }

    void addTail(string address)
    {
        NodePage *newNode = new NodePage(address);
        currentPage = newNode;
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
            NodePage *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

            delete temp;
            size--;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteTail()
    {
        if (tail != nullptr)
        {
            NodePage *temp = tail;
            tail = tail->prev;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete temp;
            size--;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteCurrent()
    {
        if (head == nullptr)
        {
            cout << "Khong co Page nao de xoa." << endl << endl;
            return;
        }
        if (currentPage == head)
        {
            currentPage = currentPage->next;
            deleteHead();
        }
        else if (currentPage == tail)
        {
            currentPage = currentPage->prev;
            deleteTail();
        }
        else
        {
            NodePage *temp = currentPage;
            currentPage = currentPage->prev;
            currentPage->next = temp->next;
            temp->next->prev = currentPage;
            delete temp;
            size--;
        }
    }

    void display()
    {
        NodePage *current = head;
        int i = 1;
        cout << "This Tab contains: " << endl;
        while (current != nullptr)
        {
            cout << "Page " << i << " : " << current->url << endl;
            i++;
            current = current->next;
        }
        cout << endl;
    }

    void moveNext()
    {
        if (currentPage->next == nullptr)
        {
            cout << "You are at the last Page." << endl;
        }
        else
            currentPage = currentPage->next;
    }
    void moveBack()
    {
        if (currentPage->prev == nullptr)
        {
            cout << "You are at the first Page." << endl;
        }
        else
            currentPage = currentPage->prev;
    }

    int getCurrentIndex()
    {
        int i = 1;
        for (NodePage *p = head; p != nullptr; p = p->next)
        {
            if (p == currentPage)
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