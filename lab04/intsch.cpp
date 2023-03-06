/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool secondsort(pair<int,int> x, pair<int,int> y)
{
    return (x.second < y.second);
}

int main()
{
    int n,s,t,ans=1;
    vector<pair<int,int>> arr;
    pair<int,int> pos;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> s >> t;
        arr.push_back({s,t});
    }
    sort(arr.begin(),arr.end(),secondsort);
    pos = arr.front();
    for (auto it = arr.begin();it != arr.end();it++)
    {
        if (it == arr.begin())
            continue;
        if (pos.second <= (*it).first)
        {
            pos = *it;
            ans += 1;
        }
    }
    cout << ans << endl;
}