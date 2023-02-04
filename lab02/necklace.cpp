/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,x,y,tmp,ins,pos;
    cin >> n;
    int arr[n+1],check[n+1];
    for (int i=0;i<=n;i++)
    {
        arr[i] = 0;
        check[i] = 0;
    }
    for (int i=1;i<n;i++)
    {
        cin >> x >> y;
        if (arr[y] == 0)
            arr[y] = x;
        else
        {
            tmp = arr[y];
            ins = x;
            arr[y] = x;
            while (arr[ins] != 0)
                ins = arr[ins];
            arr[ins] = tmp;
        }
        check[x] = 1;
    }
    for (int i=1;i<n;i++)
    {
        if (check[i] == 0)
        {
            pos = i;
            break;
        }
    }
    cout << pos;
    while (arr[pos] != 0)
    {
        cout << ' ' << arr[pos];
        pos = arr[pos];
    }
    cout << endl;
}