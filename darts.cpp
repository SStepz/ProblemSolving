/*
LANG: C++
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,x,y;
    float r;
    int ans=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> x >> y;
        r = sqrt(x*x + y*y);
        if (r <= 2)
            ans += 5;
        else if (r <= 4)
            ans += 4;
        else if (r <= 6)
            ans += 3;
        else if (r <= 8)
            ans += 2;
        else if (r <= 10)
            ans += 1;
    }
    cout << ans << endl;
}