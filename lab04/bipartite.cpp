/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void addedge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

bool checkbi(vector<int> arr[], int n)
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

int main()
{
    int k,n,m,x,y;
    cin >> k;
    for (int i=0;i<k;i++)
    {
        cin >> n >> m;
        vector<int> arr[n+1];
        for (int j=0;j<m;j++)
        {
            cin >> x >> y;
            addedge(arr,x,y);
        }
        if (checkbi(arr,n))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}