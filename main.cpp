#include <iostream>
using namespace std;
#include "ListWindow.cpp"
#include "ListHistory.cpp"

int main()
{
    ListWindow listWindow;
    ListHistory listHistory;
    Window w1;
    listWindow.addTail(w1);
    listHistory.addTail("Ban da tao mot Window moi.");

    char choose;
    do
    {
        cout << "=======================   WINDOW " << listWindow.getCurrentIndex() << " ==========================" << endl;
        cout << "||       ============   MENU TABLE  ============            ||" << endl;
        cout << "||          Press W: New Window.                            ||" << endl;
        cout << "||          Press T: New Tab                                ||" << endl;
        cout << "||          Press H: Xem lich su.                           ||" << endl;
        cout << "||          Press I: Xem thong tin window hien tai.         ||" << endl;
        cout << "||          Press B: Back window                            ||" << endl;
        cout << "||          Press N: Next window.                           ||" << endl;
        cout << "||          Press D: Huy window hien tai.                   ||" << endl;
        cout << "||          Press X. Thoat chuong trinh.                    ||" << endl;
        cout << "==============================================================" << endl;
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
            break;
        }

        case 'T':
        {
            system("CLS");
            Tab newTab;
            listWindow.currentWindow->window.addTail(newTab);
            listHistory.addTail("Ban da tao mot Tab vao Window hien tai.");

            char feature;
            do
            {
                string name;
                if (listWindow.currentWindow->window.currentTab->tab.isEmpty())
                    name = "NULL";
                else
                    name = listWindow.currentWindow->window.currentTab->tab.currentPage->url;

                cout << "......................... TAB " << listWindow.currentWindow->window.getCurrentIndex() << " .............................." << endl;
                cout << ".  PAGE: " << name << endl;
                cout << ".        ============   MENU TABLE  ============             ." << endl;
                cout << ".           Press T: New Tab.                                ." << endl;
                cout << ".           Press P: New Page.                               ." << endl;
                cout << ".           Press A: Next Page.                              ." << endl;
                cout << ".           Press C: Back Page.                              ." << endl;
                cout << ".           Press R: Xoa Page hien tai.                      ." << endl;
                cout << ".           Press I: Xem thong tin Tab hien tai.             ." << endl;
                cout << ".           Press B: Back tab.                               ." << endl;
                cout << ".           Press N: Next tab.                               ." << endl;
                cout << ".           Press D: Xoa Tab hien tai.                       ." << endl;
                cout << ".           Press X. Quay ve Window hien tai.                ." << endl;
                cout << ".............................................................." << endl;
                cout << "Moi nhap lua chon: ";
                cin >> feature;

                switch (feature)
                {
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
                case 'A':
                {
                    // listHistory.addTail("Ban da tao mot Page moi.");
                    listWindow.currentWindow->window.currentTab->tab.moveNext();
                    system("CLS");
                    break;
                }
                case 'C':
                {
                    // listHistory.addTail("Ban da tao mot Page moi.");
                    listWindow.currentWindow->window.currentTab->tab.moveBack();
                    system("CLS");
                    break;
                }
                case 'R':
                {
                    listHistory.addTail("Ban da xoa mot Page.");
                    listWindow.currentWindow->window.currentTab->tab.deleteCurrent();
                    system("CLS");
                    break;
                }
                case 'I':
                {
                    system("CLS");
                    listWindow.currentWindow->window.currentTab->tab.display();
                    break;
                }
                case 'B':
                {
                    system("CLS");
                    listWindow.currentWindow->window.moveBack();
                    break;
                }
                case 'N':
                {
                    system("CLS");
                    listWindow.currentWindow->window.moveNext();
                    break;
                }
                case 'D':
                {
                    system("CLS");
                    listHistory.addTail("Ban da xoa mot Tab.");
                    listWindow.currentWindow->window.deleteCurrent();
                    if (listWindow.currentWindow->window.isEmpty())
                        feature = 'X';
                    break;
                }
                default:
                {
                    if (feature != 'X')
                    {
                        system("CLS");
                        cout << "Ban chua nhap dung lenh !!!" << endl
                             << endl;
                    }
                    break;
                }
                }
            } while (feature != 'X');

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

        case 'B':
        {
            system("CLS");
            listWindow.moveBack();
            break;
        }

        case 'N':
        {
            system("CLS");
            listWindow.moveNext();
            break;
        }

        case 'D':
        {
            system("CLS");
            listWindow.moveNext();
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