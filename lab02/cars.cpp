/*
LANG: C++
*/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    int n,p,v,check=0,ans=0;
    list<int> parr;
    list<int> varr;
    list<int>::iterator it;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> p >> v;
        parr.push_front(p);
        varr.push_front(v);
    }
    for (it = varr.begin();it != varr.end();it++)
    {
        if (*it > check)
        {
            check = *it;
            ans += 1;
        }
    }
    cout << n-ans << endl;
}