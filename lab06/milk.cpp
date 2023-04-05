/*
LANG: C++
*/

#include <iostream>

using namespace std;

int n,q;
int par[100001],ranks[100001];

int finds(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = finds(par[x]);
}

void unions(int px, int py)
{
    if (px == py)
        return;
    if (ranks[px] < ranks[py])
        swap(px,py);
    par[py] = px;
    ranks[px] += ranks[py];
}

int main()
{
    char c;
    int x,y,px,py;
    cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        par[i] = i;
        ranks[i] = 1;
    }
    for (int i=0;i<q;i++)
    {
        cin >> c >> x >> y;
        px = finds(x);
        py = finds(y);
        if (c == 'c')
            unions(px,py);
        else
        {
            if (px == py)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}