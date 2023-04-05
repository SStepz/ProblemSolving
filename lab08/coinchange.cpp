/*
LANG: C++
*/

#include <iostream>
#include <cstring>

using namespace std;

int coin[5] = {50,25,10,5,1},dp[7490] = {0};

void coin_init()
{
    dp[0] = 1;
    for(int j=0;j<5;j++)
    {
        for (int i=1;i<7490;i++)
        {
            if (i >= coin[j])
                dp[i] += dp[i - coin[j]];
        }
    }
}

int main()
{
    int x;
    coin_init();
    while (cin >> x)
        cout << dp[x] << "\n";
}