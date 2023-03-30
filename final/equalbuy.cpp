/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,a,b,ans=0,changej=0,fin=0;
    cin >> n;
    int p[n];
    for (int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n,greater<int>());
    for (int i=0;i<n;i++)
    {
        if (fin)
            break;
        for (int j=i+1;j<n;j++)
        {
            if (fin)
                break;
            a = p[i] + p[j];
            for (int k=0;k<n;k++)
            {
                if (changej == 1 or fin == 1)
                {   
                    changej = 0;
                    break;
                }
                if (k == i or k == j)
                    continue;
                for (int l=k+1;l<n;l++)
                {
                    if (l == i or l == j)
                        continue;
                    b = p[k] + p[l];
                    if (a == b)
                    {
                        ans = a;
                        fin = 1;
                        break;
                    }
                    else if (a > b)
                    {
                        changej = 1;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}