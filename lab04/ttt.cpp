/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n,m;

void addedge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

bool checkbi(vector<int> arr[])
{
    vector<int> color(n+1,-1);
    queue<pair<int,int>> q;
    for (int i=1;i<=n;i++)
    {
        if (color[i] == -1)
        {
            q.push({i,0});
            color[i] = 0;
            while (q.empty() == 0)
            {
                pair<int,int> p = q.front();
                q.pop();
                int f = p.first;
                int s = p.second;
                for (int u : arr[f])
                {
                    if (color[u] == s)
                        return 0;
                    else if (color[u] == -1)
                    {
                        if (s == 0)
                            color[u] = 1;
                        else
                            color[u] = 0;
                        q.push({u,color[u]});
                    }
                }
            }
        }
    }
    return 1;
}

pair<int,int> culprit(vector<pair<int,int>> parr, vector<int> arr[])
{
    vector<pair<int,int>>::iterator avoid = parr.begin();
    vector<int> temp[n+1];
    for (int i=0;i<m;i++)
    {
        for (auto it = parr.begin();it != parr.end();it++)
        {
            if (it == avoid)
                continue;
            addedge(temp,(*it).first,(*it).second);
        }
        if (checkbi(temp))
            return *avoid;
        avoid++;
        for (int j=0;j<n;j++)
            temp[j].clear();
    }
    return parr.front();
}

int main()
{
    int a,b;
    vector<pair<int,int>> parr;
    pair<int,int> ans;
    cin >> n >> m;
    vector<int> arr[n+1];
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        addedge(arr,a,b);
        parr.push_back({a,b});
    }
    ans = culprit(parr,arr);
    cout << ans.first << ' ' << ans.second << endl;
}