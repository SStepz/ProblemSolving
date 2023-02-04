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
    int m,x,i,j;
    list<int> arr[100001];
    list<int>::iterator it;
    cin >> m;
    for (int k=0;k<m;k++)
    {
        cin >> c;
        if (c == 'N')
        {
            cin >> x >> i;
            arr[i].push_back(x);
        }
        else if (c == 'M')
        {
            cin >> i >> j;
            arr[j].splice(arr[j].end(),arr[i]);
        }
    }
    for (int k=0;k<100001;k++)
    {
        for (it = arr[k].begin();it != arr[k].end();it++)
            cout << *it << endl;
    }
}