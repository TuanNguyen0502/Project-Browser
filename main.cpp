#include <iostream>
#include <windows.h>
using namespace std;
#include "ListWindow.cpp"
#include "ListHistory.cpp"
#include "ListBookmark.cpp"

void printMenu()
{
    // 68
    cout << endl;
    cout << "===============================          MENU TABLE           ===============================" << endl;
    cout << "||                                                                                         ||" << endl;
    cout << "|| Press W: New Window.            Press T: New Tab.           Press P: New Page.          ||" << endl;
    cout << "|| Press 1: Back Window.           Press 2: Next Window.       Press 3: Delete this Window.||" << endl;
    cout << "|| Press 4: Back Tab.              Press 5: Next Tab.          Press 6: Delete this Tab.   ||" << endl;
    cout << "|| Press 7: Back Page.             Press 8: Next Page.         Press 9: Delete this Page.  ||" << endl;
    cout << "|| Press I: See this Window Information.                       Press H: See History.       ||" << endl;
    cout << "|| Press B: Insert this Page to Bookmark.                      Press M: Bookmark Menu.     ||" << endl;
    cout << "||                                                                                         ||" << endl;
    cout << "||                                 Press X. Close Program.                                 ||" << endl;
    cout << "=============================================================================================" << endl;
    cout << endl;
}

void printChar(int num)
{
    cout << " ";
    int size = 31 - num;
    for (int i = 0; i < size; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void SET_COLOR(int color)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void printGG()
{
 	cout << " \t\t\t_______ _______ _______ _______ ___     _______ " << endl;
	cout << "\t\t\t|       |       |       |       |   |   |       |" << endl;
	cout << "\t\t\t|    ___|   _   |   _   |    ___|   |   |    ___|" << endl;
	cout << "\t\t\t|   | __|  | |  |  | |  |   | __|   |   |   |___ " << endl;
	cout << "\t\t\t|   ||  |  |_|  |  |_|  |   ||  |   |___|    ___|" << endl;
	cout << "\t\t\t|   |_| |       |       |   |_| |       |   |___ " << endl;
	cout << "\t\t\t|_______|_______|_______|_______|_______|_______| " << endl << endl;
}
int main()
{
    ListWindow listWindow;
    ListHistory listHistory;
    ListBookmark listBookmark;

    Window w1;
    listWindow.addTail(w1);
    listHistory.addTail("Ban da tao mot Window moi.");

    Tab t1;
    listWindow.currentWindow->window.addTail(t1);
    listHistory.addTail("Ban da tao mot Tab moi vao Window hien tai.");

    char choose;
    do
    {
    	SET_COLOR(5);
    	printGG();
    	
        SET_COLOR(3);
        printMenu();

        SET_COLOR(2);
        listBookmark.display();

        SET_COLOR(4);
        cout << "-------------------------------          WINDOW: " << listWindow.getCurrentIndex() << "            ";
        printChar(1);

        cout << "-------------------------------          TAB:    " << listWindow.currentWindow->window.getCurrentIndex() << "            ";
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
        cout << "-------------------------------          Page:   " << pageName << "            ";
        printChar(pageName.size());
        cout << endl;

        SET_COLOR(6);
        cout << "Moi nhap lua chon: ";
        cin >> choose;

        SET_COLOR(7);
        switch (choose)
        {
        // Tao window moi
        case 'W':
        {
            system("CLS");
            Window newWindow;
            listWindow.addTail(newWindow);
            listHistory.addTail("Ban da tao mot Window moi.");
            Tab newTab;
            listWindow.currentWindow->window.addTail(newTab);
            listHistory.addTail("Ban da tao mot Tab moi vao Window hien tai.");
            break;
        }

        // Tao tab moi
        case 'T':
        {
            system("CLS");
            Tab newTab;
            listWindow.currentWindow->window.addTail(newTab);
            listHistory.addTail("Ban da tao mot Tab vao Window hien tai.");
            break;
        }

        // Tao page moi
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

        // Back Window
        case '1':
        {
            system("CLS");
            bool check = listWindow.moveBack();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the first Window." << endl
            //          << endl;
            //     cout << "Cannot go back !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Next window
        case '2':
        {
            system("CLS");
            bool check = listWindow.moveNext();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the last Window." << endl
            //          << endl;
            //     cout << "Cannot go next !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Delete Window
        case '3':
        {
            system("CLS");
            bool check = listWindow.deleteCurrent();
            if (!check)
            {
                SET_COLOR(6);
                char c;
                cout << "Are you sure you want to delete this Window?" << endl;
                cout << "Y: Delete and Exit Program." << endl;
                cout << "Any: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y' || c == 'y')
                {
                    choose = 'X';
                }
                system("CLS");
            }
            else
                listHistory.addTail("Ban da xoa mot Window.");
            break;
        }

        // Back Tab
        case '4':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.moveBack();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the first Tab." << endl
            //          << endl;
            //     cout << "Cannot go back !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Next tab
        case '5':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.moveNext();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the last Tab." << endl
            //          << endl;
            //     cout << "Cannot go next !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Delete tab
        case '6':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.deleteCurrent();
            if (check == false && listWindow.size == 1)
            {
                SET_COLOR(6);
                char c;
                cout << "Are you sure you want to delete this Tab?" << endl;
                cout << "Y: Delete and Exit Program." << endl;
                cout << "Any: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y' || c == 'y')
                {
                    choose = 'X';
                }
                system("CLS");
            }
            else if (!check)
            {
                SET_COLOR(6);
                char c;
                cout << "Are you sure you want to delete this Tab?" << endl;
                cout << "Y: Delete this Tab and Delete this Window also." << endl;
                cout << "Any: Not Delete and Continue Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'Y' || c == 'y')
                {
                    listHistory.addTail("Ban da xoa mot Tab.");
                    listWindow.deleteCurrent();
                    listHistory.addTail("Ban da xoa mot Window.");
                }
                system("CLS");
            }
            else
                listHistory.addTail("Ban da xoa mot Tab.");
            break;
        }

        // Back page
        case '7':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.currentTab->tab.moveBack();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the first Page." << endl
            //          << endl;
            //     cout << "Cannot go back !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Next page
        case '8':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.currentTab->tab.moveNext();
            // if (!check)
            // {
            //     char c;
            //     cout << "You are at the last Page." << endl
            //          << endl;
            //     cout << "Cannot go next !!!" << endl
            //          << endl;
            //     cout << "Do you want to continue ?" << endl;
            //     cout << "Any: Continue Program." << endl;
            //     cout << "N: Exit Program." << endl;
            //     cout << "Enter you command: ";
            //     cin >> c;
            //     if (c == 'N' || c == 'n')
            //     {
            //         choose = 'X';
            //     }
            // }
            // system("CLS");
            break;
        }

        // Delete page
        case '9':
        {
            system("CLS");
            bool check = listWindow.currentWindow->window.currentTab->tab.deleteCurrent();
            if (!check)
            {
                SET_COLOR(6);
                char c;
                cout << "Do you want to continue ?" << endl;
                cout << "Any: Continue Program." << endl;
                cout << "N: Exit Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'N' || c == 'n')
                {
                    choose = 'X';
                }
            }
            system("CLS");
            break;
        }

        // History
        case 'H':
        {
            system("CLS");
            int option = 0;
            do
            {
                SET_COLOR(2);
                cout << "-----------HISTORY-------------" << endl;
                cout << "|                             |" << endl;
                cout << "|  Cac lua chon xem lich su:  |" << endl;
                cout << "|  1: Xem thao tac moi nhat.  |" << endl;
                cout << "|  2: Xem thao tac cu nhat.   |" << endl;
                cout << "|  3: Xem toan bo thao tac.   |" << endl;
                cout << "|  0: Thoat khoi xem lich su. |" << endl;
                cout << "|                             |" << endl;
                cout << "-------------------------------" << endl;
                cout << "Moi ban nhap option: ";
                cin >> option;

                switch (option)
                {
                case 1:
                {
                    system("CLS");
                    listHistory.displayLatest();
                    break;
                }
                case 2:
                {
                    system("CLS");
                    listHistory.displayOldest();
                    break;
                }
                case 3:
                {
                    system("CLS");
                    listHistory.display();
                    break;
                }
                default:
                    if (choose != '0')
                    {
                        system("CLS");
                        cout << "Your command is not correct !!!" << endl
                             << endl;
                    }
                    break;
                }
            } while (option != 0);
            system("CLS");
            break;
        }

        // Window information
        case 'I':
        {
            system("CLS");
            listWindow.currentWindow->window.display();
            break;
        }

        // Bookmark
        case 'B':
        {
            system("CLS");
            listBookmark.addTail(listWindow.currentWindow->window.currentTab->tab.currentPage->url);
            break;
        }

        // Bookmark menu
        case 'M':
        {
            system("CLS");
            bool isempty = listBookmark.isEmpty();
            if (isempty)
            {
                SET_COLOR(6);
                char c;
                cout << "Bookmark is empty !!!" << endl
                     << endl;
                cout << "Do you want to continue ?" << endl;
                cout << "Any: Continue Program." << endl;
                cout << "N: Exit Program." << endl;
                cout << "Enter you command: ";
                cin >> c;
                if (c == 'N' || c == 'n')
                {
                    choose = 'X';
                }
                system("CLS");
            }
            else
            {
                int option = 0;
                do
                {
                    SET_COLOR(2);
                    listBookmark.display();
                    cout << "-----------BOOKMARK MENU-----------" << endl;
                    cout << "|                                 |" << endl;
                    cout << "|  1: Go to Page.                 |" << endl;
                    cout << "|  2: Delete Bookmark.            |" << endl;
                    cout << "|  0: Exit Menu Bookmark.         |" << endl;
                    cout << "|                                 |" << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "Moi ban nhap option: ";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                    {
                        system("CLS");
                        listBookmark.display();
                        int num;
                        cout << endl;
                        cout << "Choose your Bookmark number that you want to go to: ";
                        cin >> num;
                        string address = listBookmark.getDataAtIndex(num - 1);
                        while (address == "Error")
                        {
                            cout << "Your choice is not correct !!!" << endl;
                            cout << "Choose again: ";
                            cin >> num;
                            address = listBookmark.getDataAtIndex(num - 1);
                        }

                        listWindow.currentWindow->window.currentTab->tab.addTail(address);
                        option = 0;
                        system("CLS");
                        break;
                    }
                    case 2:
                    {
                        system("CLS");
                        listBookmark.display();
                        int num;
                        cout << endl;
                        cout << "Choose your Bookmark number that you want to delete: ";
                        cin >> num;
                        string address = listBookmark.getDataAtIndex(num - 1);
                        while (address == "Error")
                        {
                            cout << "Your choice is not correct !!!" << endl;
                            cout << "Choose again: ";
                            cin >> num;
                            address = listBookmark.getDataAtIndex(num - 1);
                        }

                        listBookmark.deleteNode(num - 1);
                        option = 0;
                        system("CLS");
                        break;
                    }
                    default:
                        if (choose != '0')
                        {
                            system("CLS");
                            cout << "Your command is not correct !!!" << endl
                                 << endl;
                        }
                        break;
                    }
                } while (option != 0);
            }
            system("CLS");
            break;
        }

        default:
            if (choose != 'X')
            {
                system("CLS");
                cout << "Your command is not correct !!!" << endl
                     << endl;
            }
            break;
        }
    } while (choose != 'X');

    return 0;
}