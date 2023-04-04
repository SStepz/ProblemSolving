/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,a,b,r,x,y,ans=0;
    cin >> n >> a >> b >> r;
    for (int i=0;i<n;i++)
    {
        int dx,dy;
        cin >> x >> y;
        dx = abs(a-x);
        dy = abs(b-y);
        if (dx*dx + dy*dy <= r*r)
            ans += 1;
    }
    cout << ans << endl;
}