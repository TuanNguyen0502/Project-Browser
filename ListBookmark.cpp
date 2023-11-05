#include <iostream>
using namespace std;

struct NodeBookmark
{
    string url;
    NodeBookmark *next;
    NodeBookmark *prev;

    NodeBookmark(string val)
    {
        url = val;
        next = nullptr;
        prev = nullptr;
    }
};

class ListBookmark
{
public:
    NodeBookmark *head;
    NodeBookmark *tail;
    NodeBookmark *currentPage;
    int size = 0;

    ListBookmark()
    {
        head = nullptr;
        tail = nullptr;
        currentPage = new NodeBookmark("NULL");
    }

    void addTail(string address)
    {
        if (address == "NULL")
            return;
        
        NodeBookmark *newNode = new NodeBookmark(address);
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
            NodeBookmark *temp = head;
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
            cout << "This ListBookmark is empty." << endl;
        }
    }

    void deleteTail()
    {
        if (tail != nullptr)
        {
            NodeBookmark *temp = tail;
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
            cout << "This ListBookmark is empty." << endl;
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
            NodeBookmark *temp = currentPage;
            currentPage = currentPage->prev;
            currentPage->next = temp->next;
            temp->next->prev = currentPage;
            delete temp;
            size--;
        }
    }

    void display()
    {
        NodeBookmark *current = head;
        int i = 1;
        cout << "Bookmark contains: " << endl;
        while (current != nullptr)
        {
            cout << "Page " << i << " : " << current->url << "\t";
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
        for (NodeBookmark *p = head; p != nullptr; p = p->next)
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