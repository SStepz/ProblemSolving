/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,oldans=0,ans=0,mx=-1,mxn,diff;
    cin >> n;
    int arr[n],narr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i=0;i<n;i++)
        narr[i] = arr[i];
    for (int i=0;i<n-1;i++)
    {
        diff = abs(arr[i]-arr[i+1]);
        if (diff > mx)
        {
            mx = diff;
            mxn = i;
        }
        oldans += diff;
    }
    narr[mxn] = narr[0];    //temp
    /*if (narr[mxn] > narr[mxn+1])
    {
        
    }
    else
    {
        
    }
    */
    for (int i=0;i<n-1;i++)
    {
        diff = abs(narr[i]-narr[i+1]);
        ans += diff;
    }
    cout << ans << endl;
}