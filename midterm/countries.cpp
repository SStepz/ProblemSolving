/*
LANG: C++
*/

#include <iostream>

using namespace std;

int arr[30][30];

int path(int a,int b,int x,int y)
{
    int tmp1,tmp2,ans1=0,ans2=0;
    tmp1 = arr[a][b];
    tmp2 = tmp1;
    if (a <= x)
    {
        for (int i=a;i<=x;i++)
        {
            if (arr[i][b] != tmp1)
            {
                tmp1 = arr[i][b];
                ans1 += 1;
            }
        }
        if (b <= y)
        {
            for (int j=b;j<=y;j++)
            {
                if (arr[a][j] != tmp2)
                {
                    tmp2 = arr[a][j];
                    ans2 += 1;
                }
            }
            for (int j=b;j<=y;j++)
            {
                if (arr[x][j] != tmp1)
                {
                    tmp1 = arr[x][j];
                    ans1 += 1;
                }
            }
            for (int i=a;i<=x;i++)
            {
                if (arr[i][y] != tmp2)
                {
                    tmp2 = arr[i][y];
                    ans2 += 1;
                }
            }
        }
        else
        {
            for (int j=b;j>=y;j--)
            {
                if (arr[a][j] != tmp2)
                {
                    tmp2 = arr[a][j];
                    ans2 += 1;
                }
            }
            for (int j=b;j>=y;j--)
            {
                if (arr[x][j] != tmp1)
                {
                    tmp1 = arr[x][j];
                    ans1 += 1;
                }
            }
            for (int i=a;i<=x;i++)
            {
                if (arr[i][y] != tmp2)
                {
                    tmp2 = arr[i][y];
                    ans2 += 1;
                }
            }
        }
    }
    else
    {
        for (int i=a;i>=x;i--)
        {
            if (arr[i][b] != tmp1)
            {
                tmp1 = arr[i][b];
                ans1 += 1;
            }
        }
        if (b <= y)
        {
            for (int j=b;j<=y;j++)
            {
                if (arr[a][j] != tmp2)
                {
                    tmp2 = arr[a][j];
                    ans2 += 1;
                }
            }
            for (int j=b;j<=y;j++)
            {
                if (arr[x][j] != tmp1)
                {
                    tmp1 = arr[x][j];
                    ans1 += 1;
                }
            }
            for (int i=a;i>=x;i--)
            {
                if (arr[i][y] != tmp2)
                {
                    tmp2 = arr[i][y];
                    ans2 += 1;
                }
            }
        }
        else
        {
            for (int j=b;j>=y;j--)
            {
                if (arr[a][j] != tmp2)
                {
                    tmp2 = arr[a][j];
                    ans2 += 1;
                }
            }
            for (int j=b;j>=y;j--)
            {
                if (arr[x][j] != tmp1)
                {
                    tmp1 = arr[x][j];
                    ans1 += 1;
                }
            }
            for (int i=a;i>=x;i--)
            {
                if (arr[i][y] != tmp2)
                {
                    tmp2 = arr[i][y];
                    ans2 += 1;
                }
            }
        }

    }
    if (ans1 < ans2)
        return ans1;
    else
        return ans2;
}

int main()
{
    int r,c,a,b,x,y,ans;
    cin >> r >> c >> a >> b >> x >> y;
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
            cin >> arr[i][j];
    }
    ans = path(a-1,b-1,x-1,y-1);
    cout << ans << endl;
}