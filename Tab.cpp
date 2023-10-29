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

class Tab {
public:
    NodePage* head;
    NodePage* tail;
    NodePage* currentPage;

    Tab() {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(string address) {
        NodePage* newNode = new NodePage(address);
        currentPage = newNode;
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }


    void deleteHead() {
        if (head != nullptr) {
            NodePage* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                // If head becomes nullptr, update tail as well
                tail = nullptr;
            }

            currentPage = head;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteTail() {
        if (tail != nullptr) {
            NodePage* temp = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                // If tail becomes nullptr, update head as well
                head = nullptr;
            }
            currentPage = tail;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void display() {
        NodePage* current = head;
        while (current != nullptr) {
            cout << current->url << " " << endl;
            current = current->next;
        }
        cout << endl;
    }
};

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

class Window {
public:
    NodeTab* head;
    NodeTab* tail;
    NodeTab* currentTab;

    Window() {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(Tab tab) {
        NodeTab* newNode = new NodeTab(tab);
        currentTab = newNode;
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }


    void deleteHead() {
        if (head != nullptr) {
            NodeTab* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                // If head becomes nullptr, update tail as well
                tail = nullptr;
            }

            currentTab = head;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteTail() {
        if (tail != nullptr) {
            NodeTab* temp = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                // If tail becomes nullptr, update head as well
                head = nullptr;
            }
            currentTab = tail;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void display() {
        NodeTab* current = head;
        while (current != nullptr) {
            current->tab.display();
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Tab tab1;
    tab1.addTail("www.google.com");
    cout << tab1.currentPage << endl;
    tab1.addTail("www.youtube.com");
    cout << tab1.currentPage << endl;
    tab1.addTail("www.facebook.com");
    cout << tab1.currentPage << endl;
    tab1.display();

    Tab tab2;
    tab2.addTail("www.google.com");
    cout << tab2.currentPage << endl;
    tab2.addTail("www.youtube.com");
    cout << tab2.currentPage << endl;
    tab2.addTail("www.facebook.com");
    cout << tab2.currentPage << endl;
    tab2.display();

    Window w1;
    w1.addTail(tab1);
    w1.addTail(tab2);
    w1.display();

    return 0;
}