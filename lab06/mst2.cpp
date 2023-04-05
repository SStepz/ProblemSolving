/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int,pair<int,int>> weight[200001];
int mem[100001];
int n,m;

int find_parent(int x)
{
    while (mem[x] != x)
    {
        mem[x] = mem[mem[x]];
        x = mem[x];
    }
    return x;
}

void mem_union(int x, int y)
{
    int u,v;
    u = find_parent(x);
    v = find_parent(y);
    mem[u] = mem[v];
}

int mst_kruskal()
{
    int ans=0,a,b,w;
    for (int i=0;i<m;i++)
    {
        w = weight[i].first;
        a = weight[i].second.first;
        b = weight[i].second.second;
        if (find_parent(a) != find_parent(b))
        {
            ans += w;
            mem_union(a,b);
        }
    }
    return ans;
}

int main()
{
    int a,b,w,ans;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        mem[i] = i;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> w;
        weight[i] = make_pair(w,make_pair(a,b));
    }
    sort(weight,weight+m);
    ans = mst_kruskal();
    cout << ans << endl;
}