/*
LANG: C++
*/

#include <iostream>
#include <iterator>
#include <string>
#include <list>

using namespace std;

int main()
{
    string ogc;
    list<char> carr;
    list<char>::iterator it = carr.begin();
    while (getline(cin,ogc))
    {
        for (int i=0;i<ogc.size();i++)
            if (ogc[i] == '[')
                it = carr.begin();
            else if (ogc[i] == ']')
                it = carr.end();
            else
                carr.insert(it,ogc[i]);
        for (it = carr.begin();it != carr.end();it++)
            cout << *it;
        cout << endl;
        carr.clear();
    }
}