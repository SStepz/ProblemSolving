/*
LANG: C++
*/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    char c;
    int m,x;
    list<int> arr;
    list<int>::iterator it;
    list<int>::iterator it1;
    cin >> m;
    for (int i=0;i<m;i++)
    {
        cin >> c >> x;
        if (c == 'I')
            arr.push_front(x);
        else if (c == 'A')
            arr.push_back(x);
        else if (c == 'D' && x <= arr.size())
        {
            it = arr.begin();
            advance(it,x-1);
            arr.erase(it);
        }
    }
    for (it1 = arr.begin();it1 != arr.end();it1++)
        cout << *it1 << endl;
}