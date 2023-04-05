/*
LANG: C++
*/

#include <iostream>
#include <cstring>

using namespace std;

int l,n;
int dp[52][52],c[52];

int mincut(int l, int r)
{
    int tmp,ans = 100000;
    if (l + 1 == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    for (int i=l+1;i<r;i++)
    {
        tmp = mincut(l,i) + mincut(i,r) - c[l] + c[r];
        if (tmp < ans)
            ans = tmp;
    }
    return dp[l][r] = ans;
}

int main()
{
    while (true)
    {
        int ans;
        cin >> l;
        if (l == 0)
            break;
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> c[i];
        c[0] = 0;
        c[n+1] = l;
        memset(dp,-1,sizeof(dp));
        ans = mincut(0,n+1);
        cout << "The minimum cutting is " << ans << ".\n";
    }
}