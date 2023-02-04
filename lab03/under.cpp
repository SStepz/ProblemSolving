/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    int L,n,a,b,c,ans=-1;
    double pos;
    cin >> L >> n;
    vector<pair<int,int>> bridge;
    set<int> sel;
    for (int i=0;i<n;i++)
    {
        cin >> a >> b;
        bridge.push_back(make_pair(a,b));
        sel.insert(a);
        sel.insert(b);
    }
    int use[sel.size()],k=0;
    for (auto it = sel.begin();it != sel.end();it++)
    {
        use[k] = *it;
        k += 1;
    }
    for (int i=0;i<sel.size()-1;i++)
    {
        pos = (use[i] + use[i+1])/2.0;
        c = 0;
        for (auto it = bridge.begin();it != bridge.end();it++)
        {
            if (pos >= it->first && pos <= it->second)
                c += 1;
        }
        if (c > ans)
            ans = c;
    }
    cout << ans << endl;
}