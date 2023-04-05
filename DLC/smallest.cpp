/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,q,t,j,k,ans;
    cin >> n >> q;
    int h[n],premin[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    premin[0] = h[0];
    for (int i=1;i<n;i++)
        premin[i] = min(premin[i-1], h[i]);
    for (int i=0;i<q;i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> j;
            ans = premin[j-1];
        }
        else
        {
            cin >> k;
            if (k > h[0])
                ans = 0;
            else
            {
                for (int pos=0;pos<n;pos++)
                {
                    if (h[pos] < k)
                        break;
                    ans = pos;
                }
                ans += 1;
            }
        }
        cout << ans << endl;
    }
}