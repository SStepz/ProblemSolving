/*
LANG: C++
*/

#include <iostream>

using namespace std;

int n,h;

int goleft(int x[], int pos)
{
    int hp,count=0;
    hp = h;
    for (int i=0;i<n;i++)
    {
        if (pos - i < 0)
        {
            if (hp - x[n+pos-i] > 0)
            {
                hp -= x[n+pos-i];
                count += 1;
            }
        }
        else
        {
            if (hp - x[pos-i] > 0)
            {
                hp -= x[pos-i];
                count += 1;
            }
        }
    }
    return count;
}

int goright(int x[], int pos)
{
    int hp,count=0;
    hp = h;
    for (int i=0;i<n;i++)
    {
        if (hp - x[(pos+i)%n] > 0)
        {
            hp -= x[(pos+i)%n];
            count += 1;
        }
    }
    return count;
}

int main()
{
    int l,r,m,ans=-1;
    cin >> n >> h;
    int x[n];
    for (int i=0;i<n;i++)
        cin >> x[i];
    for (int i=0;i<n;i++)
    {
        l = goleft(x,i);
        r = goright(x,i);
        if (l > r)
            m = l;
        else
            m = r;
        if (m > ans)
            ans = m;
    }
    cout << ans << endl;
}