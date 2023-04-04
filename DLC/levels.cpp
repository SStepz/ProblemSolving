/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m,x,y,z,cx=0,cy=0,cz=0,pos=0,lvl=1;
    cin >> n >> m;
    int a[n-1],b[n-1],c[n-1];
    for (int i=0;i<n-1;i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i=0;i<m;i++)
    {
        cin >> x >> y >> z;
        if (x >= a[pos])
            cx = 1;
        if (y >= b[pos])
            cy = 1;
        if (z >= c[pos])
            cz = 1;
        if (cx == 1 and cy == 1 and cz == 1)
        {
            pos += 1;
            lvl += 1;
            cx = 0;
            cy = 0;
            cz = 0;
            if (lvl == n)
                break;
        }
    }
    cout << lvl << endl;
}