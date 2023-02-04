/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addedge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

int pointbybfs(vector<int> arr[], int st,int n)
{
    queue<int> q;
    int pos,visited[n+2] = {0}, point[n+2] = {0};
    q.push(st);
    visited[st] = 1;
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
                point[u] = point[pos] + 1;
            }
        }
    }
    if (point[n+1] == 0)
        return -1;
    else
        return point[n+1];
}

int main()
{
    int n,r,x,y,dist,ans;
    cin >> n >> r;
    int powr = r*r;
    vector<int> xarr;
    vector<int> yarr;
    vector<int> arr[n+2];
    xarr.push_back(0);
    yarr.push_back(0);
    for (int i=0;i<n;i++)
    {
        cin >> x >> y;
        xarr.push_back(x);
        yarr.push_back(y);
    }
    xarr.push_back(100);
    yarr.push_back(100);
    for (int i=0;i<n+2;i++)
    {
        for (int j=i;j<n+2;j++)
        {
            if (i == j)
                continue;
            dist = ((xarr.at(i)-xarr.at(j))*(xarr.at(i)-xarr.at(j))) + ((yarr.at(i)-yarr.at(j))*(yarr.at(i)-yarr.at(j)));
            if (dist <= powr)
                addedge(arr,i,j);
        }
    }
    ans = pointbybfs(arr,0,n);
    cout << ans << endl;
}