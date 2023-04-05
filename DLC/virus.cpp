/*
LANG: C++
*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n,m,t,x,pos=0;
    cin >> n >> m;
    deque<int> arr(n+m);
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i=0;i<m;i++)
    {
        cin >> t;
        if (t == 1)
            pos = 0;
        else if (t == 2)
            pos = (pos+1)%n;
        else if (t == 3)
        {
            cin >> x;
            arr.emplace(arr.begin()+pos,x);
            pos = (pos+1)%n;
            n += 1;
        }
        else if (t == 4)
        {
            cin >> x;
            arr.emplace(arr.begin()+pos+1,x);
            n += 1;
        }
    }
    for (int i=0;i<n;i++)
        cout << arr[i] << "\n";
}