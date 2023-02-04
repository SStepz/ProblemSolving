/*
LANG: C++
*/

#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    string c;
    int m,x;
    list<int> arr;
    list<int>::iterator it;
    cin >> m;
    for (int i=0;i<m;i++)
    {
        cin >> c;
        if (c[1] == 'r')
        {
            if (c[0] == 'l')
                arr.splice(arr.end(),arr,arr.begin());
            else if (c[0] == 'r')
                arr.splice(arr.begin(),arr,--arr.end());
        }
        else if (c[1] == 'i')
        {
            cin >> x;
            if (c[0] == 'l')
                arr.push_front(x);
            else if (c[0] == 'r')
                arr.push_back(x);
        }
    }
    for (it = arr.begin();it != arr.end();it++)
        cout << *it << endl;
}