/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#define maxn 100000

vector<int> adjl[maxn];
bool visited[maxn];

void dfs(int s)
{
    visited[s] = true;
    for (auto it = adjl[s].begin();it != adjl[s].end();it++)
    {
        if (visited[*it] == false)
            dfs(*it);
    }
}

int main()
{
    int n,m,a,b,v,ans=0;
    cin >> n >> m;
    for (int i=0;i<n;i++)
        visited[i] = false;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        a -= 1;
        b -= 1;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    for (int i=0;i<n;i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            ans += 1;
        }
    }
    cout << ans << endl;
}