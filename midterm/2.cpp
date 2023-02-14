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
    for (int i=0;i<=n;i++)
    {
        if (color[i] == -1 && arr[i].size() != 0)
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
                    if (color[u] == -1)
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
    int n,m,k,x,y;
    cin >> n >> m >> k;
    vector<int> arr[n+1];
    int popcheck[n+1] = {0};
    int mem1[n],mem2[n];
    for (int i=0;i<m;i++)
    {
        cin >> x >> y;
        popcheck[x] += 1;
        popcheck[y] += 1;
        mem1[i] = x;
        mem2[i] = y;
    }
    for (int i=0;i<m;i++)
    {
        if (popcheck[mem1[i]] < k && popcheck[mem2[i]] < k)
            addedge(arr,mem1[i],mem2[i]);
    }
    if (checkbi(arr,n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}