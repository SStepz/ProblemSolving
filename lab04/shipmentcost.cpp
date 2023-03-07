/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,s,t;

void addedge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

void bfs(vector<int> arr[], int storage[], int factory[])
{
    queue<int> q;
    int pos;
    int visited[n+1] = {0},cost[n+1] = {0};
    for (int i=0;i<s;i++)
    {
        q.push(storage[i]);
        visited[storage[i]] = 1;
    }
    while (q.empty() == 0)
    {
        pos = q.front();
        q.pop();
        visited[pos] = 1;
        for (auto u : arr[pos])
        {
            if (visited[u] == 0)
            {
                visited[u] = 1;
                q.push(u);
                cost[u] = cost[pos] + 1;
            }
        }
    }
    for (int i=0;i<t;i++)
        cout << cost[factory[i]] << endl;
}

int main()
{
    int a,b;
    cin >> n >> m >> s >> t;
    int storage[s],factory[t];
    vector<int> arr[n+1];
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        addedge(arr,a,b);
    }
    for (int i=0;i<s;i++)
        cin >> storage[i];
    for (int i=0;i<t;i++)
        cin >> factory[i];
    bfs(arr,storage,factory);
}