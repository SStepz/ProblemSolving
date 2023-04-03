/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m,count,prev,mx=-1,num;
    cin >> n >> m;
    int carr[n+1]={0},arr[m];
    for (int i=0;i<m;i++)
        cin >> arr[i];
    for (int i=0;i<m;i++)
    {
        count = 1;
        prev = i;
        for (int j=i+1;j<m;j++)
        {
            if (j - prev > 6)
                break;
            if (arr[j] == arr[i])
            {
                count += 1;
                prev = j;
            }
        }
        if (count > carr[arr[i]])
            carr[arr[i]] = count;
    }
    for (int i=1;i<=n;i++)
    {
        if (carr[i] > mx)
        {
            mx = carr[i];
            num = i;
        }
    }
    cout << num << " " << mx << endl;
}