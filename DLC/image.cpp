/*
LANG: C++
*/

#include <iostream>

using namespace std;

int L,H,r;
int arr[100][100];

int findavg(int x, int y)
{
    int sum=0,count=0;
    for (int a=0;a<H;a++)
    {
        for (int b=0;b<L;b++)
        {
            if (abs(a-x) + abs(b-y) <= r)
            {
                sum += arr[a][b];
                count += 1;
            }
        }
    }
    return sum/count;
}

int main()
{
    cin >> L >> H >> r;
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<L;j++)
            cin >> arr[i][j];
    }
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<L;j++)
            cout << findavg(i,j) << " ";
        cout << endl;
    }
}