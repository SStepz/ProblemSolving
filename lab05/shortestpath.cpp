/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,a,b,w;
    cin >> n >> m;
    vector<vector<pair<int,int>>> arr(n);
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> w;
        arr[a-1].push_back({b-1,w});
        arr[b-1].push_back({a-1,w});
    }
    vector<int> dist(n, 1000);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (pq.empty() == 0)
    {
        int u = pq.top().second;
        pq.pop();
        for (auto edge : arr[u])
        {
            int fir,sec;
            fir = edge.first;
            sec = edge.second;
            if (dist[fir] > dist[u] + sec)
            {
                dist[fir] = dist[u] + sec;
                pq.push({dist[fir],fir});
            }
        }
    }
    cout << dist[n-1] << "\n";
}