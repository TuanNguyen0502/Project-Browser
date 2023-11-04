#include <iostream>
using namespace std;
#include "ListWindow.cpp"
#include "ListHistory.cpp"

void printMenu()
{
    // 68
    cout << "==========================   MENU TABLE   ==========================" << endl;
    cout << "|| Press W: New Window.    Press T: New Tab.   Press P: New Page. ||" << endl;
    cout << "|| Press 1: Back Window.   Press 2: Next Window.                  ||" << endl;
    cout << "|| Press 3: Back Tab.      Press 4: Next Tab.                     ||" << endl;
    cout << "|| Press 5: Back Page.     Press 6: Next Page.                    ||" << endl;
    cout << "|| Press 7: Delete this Window.                                   ||" << endl;
    cout << "|| Press 8: Delete this Tab.                                      ||" << endl;
    cout << "|| Press 9: Delete this Page.                                     ||" << endl;
    cout << "|| Press H: See History.   Press I: See this Window Information.  ||" << endl;
    cout << "|| Press X. Close Program.                                        ||" << endl;
    cout << "====================================================================" << endl;
    cout << endl;
}

void printChar(int num)
{
    cout << " ";
    int size = 31 - num - 1;
    for (int i = 0; i < size; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main()
{
    ListWindow listWindow;
    ListHistory listHistory;
    Window w1;
    listWindow.addTail(w1);
    listHistory.addTail("Ban da tao mot Window moi.");
    Tab t1;
    listWindow.currentWindow->window.addTail(t1);
    listHistory.addTail("Ban da tao mot Tab moi.");

    char choose;
    do
    {
        printMenu();
        cout << "  ************************   WINDOW: " << listWindow.getCurrentIndex();
        printChar(1);

        cout << "  ************************    TAB:   " << listWindow.currentWindow->window.getCurrentIndex();
        printChar(1);

        string pageName;
        if (listWindow.currentWindow->window.isEmpty())
        {
            pageName = "NULL";
        }
        else
        {
            pageName = listWindow.currentWindow->window.currentTab->tab.currentPage->url;
        }
        cout << "  ************************     Page: " << pageName;
        printChar(pageName.size());

        cout << "Moi nhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 'W':
        {
            system("CLS");
            Window newWindow;
            listWindow.addTail(newWindow);
            listHistory.addTail("Ban da tao mot Window moi.");
            Tab newTab;
            listWindow.currentWindow->window.addTail(newTab);
            listHistory.addTail("Ban da tao mot Tab moi.");
            break;
        }

        case 'T':
        {
            system("CLS");
            Tab newTab;
            listWindow.currentWindow->window.addTail(newTab);
            listHistory.addTail("Ban da tao mot Tab vao Window hien tai.");
            break;
        }

        case 'P':
        {
            listHistory.addTail("Ban da tao mot Page moi.");
            string url;
            cout << "Moi nhap URL: ";
            cin >> url;
            listWindow.currentWindow->window.currentTab->tab.addTail(url);
            system("CLS");
            break;
        }

        case '1':
        {
            system("CLS");
            listWindow.moveBack();
            break;
        }

        case '2':
        {
            system("CLS");
            listWindow.moveNext();
            break;
        }

        case '3':
        {
            system("CLS");
            listWindow.currentWindow->window.moveBack();
            break;
        }
        case '4':
        {
            system("CLS");
            listWindow.currentWindow->window.moveNext();
            break;
        }

        case '5':
        {
            system("CLS");
            listWindow.currentWindow->window.currentTab->tab.moveBack();
            break;
        }
        case '6':
        {
            system("CLS");
            listWindow.currentWindow->window.currentTab->tab.moveNext();
            break;
        }

        case '7':
        {
            bool check = listWindow.deleteCurrent();
            if (!check)
            {
                char c;
                cout << "Are you sure you want to delete this Window?" << endl;
                cout << "Y: Delete and Exit Program." << endl;
                cout << "N: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y')
                {
                    choose = 'X';
                }
            }
            else
                listHistory.addTail("Ban da xoa mot Window.");
            break;
        }
        case '8':
        {
            bool check = listWindow.currentWindow->window.deleteCurrent();
            if (check == false && listWindow.size == 1)
            {
                char c;
                cout << "Are you sure you want to delete this Tab?" << endl;
                cout << "Y: Delete and Exit Program." << endl;
                cout << "N: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y')
                {
                    choose = 'X';
                }
            }
            else if (!check)
            {
                char c;
                cout << "Are you sure you want to delete this Tab?" << endl;
                cout << "Y: Delete this Tab and Delete this Window also." << endl;
                cout << "N: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y')
                {
                    listHistory.addTail("Ban da xoa mot Tab.");
                    listWindow.deleteCurrent();
                    listHistory.addTail("Ban da xoa mot Window.");
                }
            }
            else
                listHistory.addTail("Ban da xoa mot Tab.");
            break;
        }
        case '9':
        {
            listWindow.currentWindow->window.currentTab->tab.deleteCurrent();
            listHistory.addTail("Ban da xoa mot Page.");
            break;
        }

        case 'H':
        {
            int option = 0;
            do
            {
                cout << "-----------HISTORY-------------" << endl;
                cout << "|  Cac lua chon xem lich su:  |" << endl;
                cout << "|  1: Xem thao tac moi nhat.  |" << endl;
                cout << "|  2: Xem thao tac cu nhat.   |" << endl;
                cout << "|  3: Xem toan bo thao tac.   |" << endl;
                cout << "|  0: Thoat khoi xem lich su. |" << endl;
                cout << "-------------------------------" << endl;
                cout << "Moi ban nhap option: ";
                cin >> option;

                switch (option)
                {
                case 1:
                {
                    listHistory.displayLatest();
                    break;
                }
                case 2:
                {
                    listHistory.displayOldest();
                    break;
                }
                case 3:
                {
                    listHistory.display();
                    break;
                }
                default:
                    break;
                }
            } while (option != 0);
            break;
        }

        case 'I':
        {
            system("CLS");
            listWindow.currentWindow->window.display();
            break;
        }

        default:
            if (choose != 'X')
            {
                system("CLS");
                cout << "Ban chua nhap dung lenh !!!" << endl
                     << endl;
            }
            break;
        }
    } while (choose != 'X');

    return 0;
}