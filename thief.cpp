/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,k,t,count=0,ans=1;
    cin >> n >> k >> t;
    int arr[n];
    for (int i=0;i<n;i++)
        arr[i] = i+1;
    while (true)
    {
        count += k;
        count = count % n;
        if (arr[count] == 1)
            break;
        else if (arr[count] == t)
        {
            ans += 1;
            break;
        }
        ans += 1;
    }
    cout << ans << endl;
}