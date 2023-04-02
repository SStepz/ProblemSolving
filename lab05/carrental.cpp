/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k,n,t,count,skip=0,ans=-1;
    vector<int> tmp;
    cin >> k >> n;
    int c[k],p[k],w[k],a[n];
    for (int i=0;i<k;i++)
        cin >> c[i] >> p[i] >> w[i];
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<k;i++)
    {
        t = c[i];
        count = 0;
        for (int j=0;j<n;j++)
        {
            int sum=0;
            if (a[j] > w[i])
            {   
                skip = 1;
                break;
            }
            for (auto m : tmp)
                sum += m;
            if (sum + a[j] > w[i])
            {
                count += 1;
                tmp.clear();
            }
            tmp.push_back(a[j]);
        }
        tmp.clear();
        if (skip == 1)
        {
            skip = 0;
            continue;
        }
        count += 1;
        t += count*p[i];
        if (t < ans or ans == -1)
            ans = t;
    }
    cout << ans << endl;
}