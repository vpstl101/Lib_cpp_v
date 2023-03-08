

#include <iostream>
#include "LibManager.h"
// g++ -c 123.cpp
// g++ -o "name" main.cpp 123.o
using namespace std;

int main()
{
    LibManager manager;
    int choice;
    while (1)
    {
        manager.PrintMenu();
        cout << "CHOICE : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                manager.Login();
                break;

            case 2:
                manager.MakeMemberShip();
                break;
            case 0:
                break;
            default:
                break;
        }
    }
    return 0;
}
