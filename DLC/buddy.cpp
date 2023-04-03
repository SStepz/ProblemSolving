/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
bool visited[100001],current[100001];
int count = 0;

void dfs(int u)
{
    visited[u] = true;
    current[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v);
        else if (current[v])
            count += 1;
    }
    current[u] = false;
}

int main()
{
    int n,u,same=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> u;
        if (u - 1 == i)
            same += 1;
        adj[i].push_back(u - 1);
    }
    for (int i=1;i<=100000;i++) 
    {
        if (!visited[i])
            dfs(i);
    }
    if (same != 0)
        cout << count + same - 1 << endl;
    else
        cout << count << endl;
    return 0;
}