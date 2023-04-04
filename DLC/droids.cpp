/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,use=-1,ans=0;
    cin >> n >> m;
    int bot[n],item[m];
    for (int i=0;i<n;i++)
        cin >> bot[i];
    for (int i=0;i<m;i++)
        cin >> item[i];
    sort(bot,bot+n);
    for (int i=0;i<m;i++)
    {
        int min=1000000,num,diff;
        for (int j=0;j<n;j++)
        {
            if (j == use)
                continue;
            diff = abs(bot[j]-item[i]);
            if (diff < min)
            {
                min = diff;
                num = j;
            }
        }
        use = num;
        ans += min;
    }
    cout << ans << endl;
}