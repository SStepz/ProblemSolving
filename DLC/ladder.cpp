/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m,d,pos=0;
    cin >> n >> m;
    int x[n+1];
    for (int i=1;i<=n;i++)
        cin >> x[i];
    for (int i=0;i<m;i++)
    {
        int tmp;
        cin >> d;
        if (pos + d >= n)
        {
            pos = n;
            break;
        }
        pos += d;
        if (x[pos] != 0)
        {
            tmp = pos + x[pos];
            if (tmp >= n)
            {
                pos = n;
                break;
            }
            else if (tmp < 0)
                pos = 0;
            pos += x[pos];
        }
    }
    cout << pos << endl;
}