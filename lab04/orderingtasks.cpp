/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    while (true)
    {
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        vector<int> arr[n+1];
        vector<int> ans;
        queue<int> q;
        int rank[n+1];
        for (int i=1;i<=n;i++)
            rank[i] = 0;
        for (int i=0;i<m;i++)
        {
            int a,b;
            cin >> a >> b;
            arr[a].push_back(b);
            rank[b] += 1;
        }
        for (int i=1;i<=n;i++)
        {
            if (rank[i] == 0)
                q.push(i);
        }
        while (q.empty() == 0)
        {
            int pos;
            pos = q.front();
            q.pop();
            ans.push_back(pos);
            for (int i=0;i<arr[pos].size();i++)
            {
                rank[arr[pos][i]] -= 1;
                if (rank[arr[pos][i]] == 0)
                    q.push(arr[pos][i]);
            }
        }
        cout << ans[0];
        for (int i=1;i<n;i++)
            cout << " " << ans[i];
        cout << endl;
        ans.clear();
    }
}