/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,num,maxpay=0;
    cin >> n;
    int s[n],t[n],w[n],mp[n];
    vector<int> ans;
    vector<int> current[n];
    for (int i=0;i<n;i++)
        cin >> s[i] >> t[i] >> w[i];
    for (int i=0;i<n;i++)
    {
        mp[i] = w[i];
        current[i].push_back(i);
        for (int j=0;j<i;j++)
        {
            if (s[i] >= t[j])
            {
                if (mp[j] + w[i] > mp[i])
                {
                    current[i] = current[j];
                    current[i].push_back(i);
                    mp[i] = mp[j] + w[i];
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (mp[i] > maxpay)
        {
            maxpay = mp[i];
            ans = current[i];
        }
    }
    num = ans.size();
    cout << maxpay << "\n";
    cout << num << "\n";
    for (auto i : ans)
        cout << i+1 << " ";
    cout << "\n";
}