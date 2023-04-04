/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m,a,s,ans=0;
    cin >> n >> m;
    int arr[n+1]={0},count[n+1]={0};
    for (int i=0;i<m;i++)
    {
        cin >> a >> s;
        if (count[a] == 5)
            arr[a] = 0;
        else
        {
            if (s > arr[a])
                arr[a] = s;
            count[a] += 1;
        }
    }
    for (int i=1;i<=n;i++)
        ans += arr[i];
    cout << ans << endl;
}