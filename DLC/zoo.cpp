/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int r,c,b,t,bucket,count,changerow=0;
    cin >> r >> c >> b >> t;
    int arr[r][c];
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
            cin >> arr[i][j];
    }
    bucket = b;
    count = 1;
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            for (int k=0;k<arr[i][j];k++)
            {
                if (changerow)
                {
                    bucket = b;
                    count += 1;
                    changerow = 0;
                }
                if (bucket < t)
                {
                    bucket = b;
                    count += 1;
                }
                bucket -= t;
            }
        }
        changerow = 1;
    }
    cout << count << endl;
}