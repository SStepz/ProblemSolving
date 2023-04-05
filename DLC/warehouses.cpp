/*
LANG: C++
*/

#include <iostream>
#include <bitset>
#include <set>

using namespace std;

set<int> arr[100001];
bitset<100001> visited;

void dfs(int u)
{
    visited[u] = true;
    for (auto v : arr[u])
    {
        if (visited[v] == 0)
            dfs(v);
    }
}

int main()
{
    int n,m,k,u,v,s,t;
    cin >> n >> m >> k;
    for (int i=0;i<m;i++)
    {
        cin >> u >> v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    for (int i=0;i<k;i++)
    {
        cin >> s >> t;
        visited.reset();
        dfs(s);
        cout << visited[t] << "\n";
    }
}