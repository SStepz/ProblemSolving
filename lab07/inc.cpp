/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,ans=1;
    cin >> n;
    vector<int> arr(n),dp(n,1),parr;
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (dp[i] > ans)
            ans = dp[i];
    }
    cout << ans << "\n";
    for (int i=n-1;i>=0;i--)
    {
        if (dp[i] == ans)
        {
            parr.push_back(arr[i]);
            ans -= 1;
        }
    }
    reverse(parr.begin(),parr.end());
    for (auto num : parr)
        cout << num << " ";
    cout << "\n";
}