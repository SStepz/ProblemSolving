/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int year,cant,count=0;
    cin >> year;
    while (true)
    {
        cin >> cant;
        if (cant == 0)
            break;
        count += 1;
    }
    if (count % 2 == 0)
    {
        if (year % 2 == 0)
            cout << 'K' << "\n";
        else
            cout << 'C' << "\n";
    }
    else
    {
        if (year % 2 == 0)
            cout << 'C' << "\n";
        else
            cout << 'K' << "\n";
    }
}