/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[1001];

int depth[1001],parent[1001][20];

void dfs(int node, int prev)
{
    parent[node][0] = prev;
    depth[node] = depth[prev] + 1;
    for (int i=1;i<20;i++)
    {
        if (parent[node][i-1] != -1)
            parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for (int i=0;i<tree[node].size();i++)
    {
        int child = tree[node][i];
        if (child != prev)
            dfs(child,node);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u,v);
    for (int i=19;i>=0;i--)
    {
        if (depth[parent[u][i]] >= depth[v])
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i=19;i>=0;i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    int n,m,c,a,b,ans;
    cin >> n >> m;
    for (int i=2;i<=n;i++)
    {
        cin >> c;
        tree[c].push_back(i);
        tree[i].push_back(c);
    }
    dfs(1,0);
    for (int i=0;i<m;i++)
    {   
        cin >> a >> b;
        ans = lca(a,b);
        if (ans != a and ans != b)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}