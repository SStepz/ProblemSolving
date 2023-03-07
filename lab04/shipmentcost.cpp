/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void addedge(vector<int> arr[], int a, int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}

int main()
{
    int n,m,s,t,a,b;
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
}