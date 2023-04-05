/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t,n,g,maxw,tmp,ans;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        ans = 0;
        cin >> n;
        vector<int> p(n),w(n);
        for (int i=0;i<n;i++)
            cin >> p[i] >> w[i];
        cin >> g;
        for (int i=0;i<g;i++)
        {
            cin >> maxw;
            vector<int> dp(maxw+1);
            for (int j=0;j<n;j++)
            {
                for (int k=maxw;k>=w[j];k--)
                {
                    tmp = dp[k-w[j]] + p[j];
                    if (tmp > dp[k])
                        dp[k] = tmp;
                }
            }
            ans += dp[maxw];
        }
        cout << ans << "\n";
    }
}