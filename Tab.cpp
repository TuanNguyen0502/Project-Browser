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
class Page
{
    public:
        ListPage listPage;

        Page()
        {
            this->listPage.head = this->listPage.tail = NULL;
        }

        void add(string address)
        {
            NodePage *temp = new NodePage();
            temp->url = address;
            temp->next == NULL;
            temp->prev == NULL;

            if (this->listPage.head == NULL)
            {
                this->listPage.head = this->listPage.tail = temp;
            }
            else
            {
                this->listPage.tail->next = temp;
                temp->prev = this->listPage.tail;
                this->listPage.tail = temp;
            }
        } 

        void deleteHead()
        {
            if (this->listPage.head == NULL)
            {
                cout << "There is no page to delete." << endl;
                return;
            }

            NodePage *temp = this->listPage.head;
            this->listPage.head->next->prev = NULL;
            this->listPage.head = this->listPage.head->next;
            delete temp;

            if (this->listPage.head == NULL)
            {
                this->listPage.tail = NULL;
            }
        }

        void deleteTail()
        {
            if (this->listPage.head == NULL)
            {
                cout << "There is no page to delete." << endl;
                return;
            }

            if (this->listPage.head->next == NULL)
            {
                deleteHead();
                return;
            }

            for (NodePage *p = this->listPage.head; p != NULL; p = p->next)
            {
                if (p->next == this->listPage.tail)
                {
                    this->listPage.tail->prev = NULL;
                    delete this->listPage.tail;
                    p->next = NULL;
                    this->listPage.tail = p;
                    return;
                }
            }
        }

        void print()
        {
            for (NodePage *p = this->listPage.head; p != NULL; p = p->next)
            {
                cout << p->url << endl;
            }
        }
};
struct NodeTab
{
    ListPage listPage;
    NodeTab *next;
    NodeTab *prev;
};
struct ListTab
{
    NodeTab *head;
    NodeTab *tail;
};

int main()
{
    Page page1;
    page1.add("www.google.com");
    page1.add("www.youtube.com");
    page1.add("www.facebook.com");

    page1.print();

    page1.deleteHead();
    page1.deleteTail();
    page1.print();

    return 0;
}