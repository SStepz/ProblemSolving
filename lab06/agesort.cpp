/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int arr[n];
        for (int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        for (int i=0;i<n-1;i++)
            cout << arr[i] << " ";
        cout << arr[n-1] << "\n";
    }
}