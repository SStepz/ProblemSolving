/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stack>

using namespace std;

int n,m,ccheck=0;
set<int> ogset;
set<int> funcset;
stack<int> st;

void checkcycle(vector<int> arr[], int u)
{
    ogset.erase(u);
    funcset.insert(u);
    for (int i=0;i<arr[u].size();i++)
    {
        if (ogset.find(arr[u][i]) != ogset.end())
            checkcycle(arr,arr[u][i]);
        if (funcset.find(arr[u][i]) != funcset.end())
            ccheck = 1;
    }
    funcset.erase(u);
}

void topotool(vector<int> arr[], int visited[], int u)
{
    visited[u] = 1;
    list<int>::iterator it;
    for (auto it = arr[u].begin();it != arr[u].end();it++)
    {
        if (visited[*it] == 0)
            topotool(arr,visited,*it);
    }
    st.push(u);
}

void topo(vector<int> arr[], int visited[])
{
    for (int i=1;i<=n;i++)
        visited[i] = 0;
    for (int i=1;i<=n;i++)
    {
        if (visited[i] == 0)
            topotool(arr,visited,i);
    }
    while (st.empty() == 0)
    {
        int x;
        x = st.top();
        cout << x << endl;
        st.pop();
    }
}

int main()
{
    int u,v;
    cin >> n >> m;
    vector<int> arr[n+1];
    int visited[n+1];
    for (int j=0;j<m;j++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
    }
    for (int i=1;i<=n;i++)
        ogset.insert(i);
    checkcycle(arr,1);
    if (ccheck)
        cout << "no" << endl;
    else
        topo(arr,visited);
}