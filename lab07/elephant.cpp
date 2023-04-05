/*
LANG: C++
*/

#include <iostream>

using namespace std;

int n;
int dp[100000];

int score(int ind, int arr[])
{
    int j1,j3;
    if (ind + 2 < n)
    {
        if (dp[ind] == -1)
        {
            j1 = score(ind+1,arr);
            j3 = score(ind+3,arr);
            if (j1 > j3 + arr[ind+2])
                dp[ind] = j1;
            else
                dp[ind] = j3 + arr[ind+2];
        }
        return dp[ind];
    }
    else
        return 0;
}

int main()
{
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        dp[i] = -1;
        cin >> arr[i];
    }
    cout << score(0,arr) << endl;
}