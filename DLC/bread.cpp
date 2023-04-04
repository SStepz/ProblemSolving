/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct shop
{
    int x,c,l;
};

bool costsort(shop x, shop y)
{
    return (x.c < y.c);
}

int main()
{
    int n,q,y,xi,ci,li,pos=0;
    cin >> n >> q;
    shop arr[n];
    int x[n],c[n],l[n];
    for (int i=0;i<n;i++)
    {
        cin >> xi >> ci >> li;
        arr[i] = {xi,ci,li};
    }
    sort(arr,arr+n,costsort);
    for (int j=0;j<n;j++)
    {
        x[j] = arr[j].x;
        c[j] = arr[j].c;
        l[j] = arr[j].l;
    }
    for (int i=0;i<q;i++)
    {
        int cost=1000000,found=0,num;
        cin >> y;
        for (int j=0;j<n;j++)
        {
            if (c[j] < cost and abs(x[j]-y) <= 5 and l[j] != 0)
            {
                found = 1;
                cost = c[j];
                num = x[j];
            }
        }
        if (found == 1)
        {
            for (int j=0;j<n;j++)
            {
                if (x[j] == num)
                {
                    l[j] -= 1;
                    break;
                }
            }
        }
        else
            cost = 0;
        cout << cost << "\n";
    }
}