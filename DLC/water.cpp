/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,diff,prev=0,ans=0;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i=0;i<n;i++)
    {
        diff = prev - arr[i];
        if (diff > 10)
        {
            if (diff*10 > 700)
                ans += 700;
            else
                ans += diff*10;
        }
        prev = arr[i];
    }
    cout << ans << endl;
}