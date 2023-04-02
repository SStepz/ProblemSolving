/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m,sum,count,num;
    double t,ans=-1;
    cin >> n >> m;
    int arr[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin >> arr[i][j];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            sum = 0;
            count = 0;
            for (int k=0;k<n;k++)
            {
                for (int p=0;p<m;p++)
                {
                    if (k == i and p == j)
                        continue;
                    else if (k == i or p == j)
                    {
                        count += 1;
                        sum += abs(arr[i][j] - arr[k][p]);
                    }
                }
            }
            t = (float)sum/count;
            if (t < ans or ans == -1)
            {
                ans = t;
                num = arr[i][j];
            }
        }
    }
    cout << num << endl;
}