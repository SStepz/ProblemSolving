/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,a,b,j,k;
    long long ans = 0;
    cin >> n >> a >> b;
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for (int i=0;i<n;i++)
    {
        j = lower_bound(arr + i + 1, arr + n, a - arr[i]) - arr;
        k = upper_bound(arr + i + 1, arr + n, b - arr[i]) - arr;
        ans += k - j;
    }
    cout << ans << endl;
}