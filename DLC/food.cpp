/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,k,ans;
    cin >> n >> k;
    int m[n];
    for (int i=0;i<n;i++)
        cin >> m[i];
    ans = n;
    for (int i=0;i<n;i++)
    {
        int skip=-1,supply=0,tmp=0;
        for (int j=i;j<n;j++)
        {
            if (m[j] > k)
            {
                skip = j;
                break;
            }
            if (m[j] + supply <= k)
                supply += m[j];
            else
            {
                tmp += k - supply;
                supply = k - m[j];
            }
        }
        if (supply < k)
            tmp += k - supply;
        if (tmp < ans)
            ans = tmp;
        if (skip != -1)
            i = skip;
    }
    cout << ans << endl;
}