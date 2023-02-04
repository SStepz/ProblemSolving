/*
LANG: C++
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n,t,tmp;
    cin >> n >> t;
    int arr[n],tarr[n],ans[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    tmp = n;
    if (t == 1)
    {
        for (int i=0;i<n;i++)
        {
            if (arr[i] < tmp)
            {
                ans[i] = 0;
                tmp = arr[i];
            }
            else
            {
                ans[i] = 1;
                tmp = arr[i];
            }
        }
    }
    else if (t == 2)
    {
        tarr[0] = arr[0];
        for (int i=1;i<n;i++)
        {
            if ((tarr[i-1]+1) + 2*tarr[i-1] == arr[i])
                tarr[i] = arr[i] - 2*tarr[i-1];
            else
                tarr[i] = arr[i] - tarr[i-1];
        }
        for (int i=0;i<n;i++)
        {
            if (tarr[i] < tmp)
            {
                ans[i] = 0;
                tmp = tarr[i];
            }
            else
            {
                ans[i] = 1;
                tmp = tarr[i];
            }
        }
    }
    for (int i=0;i<n;i++)
        cout << ans[i] << endl;
}