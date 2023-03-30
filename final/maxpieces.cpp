/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,q,x,y,count,total;
    cin >> n >> q;
    int p[n];
    for (int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n);
    for (int i=0;i<q;i++)
    {
        cin >> x >> y;
        count = 0;
        total = 0;
        for (int j=0;j<n;j++)
        {
            if (p[j] >= y)
            {
                if (total + p[j] <= x)
                {
                    total += p[j];
                    count += 1;
                }
                else
                    break;
            }
        }
        cout << count << endl;
    }
}