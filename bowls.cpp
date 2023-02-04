/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,count=1,ans=0;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for (int i=0;i<n-1;i++)
    {
        if (arr[i] == arr[i+1])
            count += 1;
        else
            count = 1;
        if (count > ans)
            ans = count;
    }
    cout << ans << endl;
}