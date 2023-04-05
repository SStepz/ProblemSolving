/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,tmp,ans;
    while (scanf("%d", &n) != EOF)
    {
        ans = 0;
        int arr[n+1],dp1[n+1],dp2[n+1];
        for (int i=1;i<=n;i++)
            scanf("%d", &arr[i]);
        for (int i=1;i<=n;i++)
        {
            dp1[i] = 1;
            for (int j=1;j<i;j++)
            {
                if (arr[j] < arr[i])
                {
                    tmp = dp1[j] + 1;
                    if (tmp > dp1[i])
                        dp1[i] = tmp;
                }
            }
        }
        for (int i=n;i>=1;i--)
        {
            dp2[i] = 1;
            for (int j=n;j>i;j--)
            {
                if (arr[j] < arr[i])
                {
                    tmp = dp2[j] + 1;
                    if (tmp > dp2[i])
                        dp2[i] = tmp;
                }
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (dp1[i] < dp2[i])
                tmp = dp1[i];
            else
                tmp = dp2[i];
            tmp = (tmp*2)-1;
            if (tmp > ans)
                ans = tmp;
        }
        printf("%d\n", ans);
    }
}