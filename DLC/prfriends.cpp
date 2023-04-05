/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findprime(int l, int r)
{
    vector<int> prime,primecheck(r-l+1,1);
    for (int i=2;i<=sqrt(r);i++)
    {
        int j = max(i*i,(l+i-1)/i*i);
        while (j <= r)
        {
            primecheck[j-l] = 0;
            j += i;
        }
    }
    for (int i=max(l,2);i<=r;i++)
    {
        if (primecheck[i-l] == 1)
            prime.push_back(i);
    }
    return prime;
}

int main()
{
    int l,r,ans=0;
    vector<int> p;
    cin >> l >> r;
    p = findprime(l,r);
    for (int i=0;i<p.size()-1;i++)
    {
        if (p[i+1] - p[i] == 2)
            ans += 1;
    }
    cout << ans << endl;
}