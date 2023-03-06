/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n,d,c,current,time=0,ans=0;
    vector<pair<int,int>> arr;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> d >> c;
        arr.push_back({d,c});
    }
    sort(arr.begin(),arr.end());
    for (auto it = arr.begin();it != arr.end();it++)
    {
        time += (*it).second;
        if (time - 10 > (*it).first)
        {
            current = (time - (*it).first - 10)*1000;
            if (current > ans)
                ans = current;
        }
    }
    cout << ans << endl;
}