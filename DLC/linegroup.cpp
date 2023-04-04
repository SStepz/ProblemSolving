/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int n,ans=100000;
int a[100001];

int diff(int l, int r)
{
    int min,max;
    min = a[l];
    max = a[l];
    for (int i=l+1;i<=r;i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    return max - min;
}

void dfs(int pos, int num, vector<int> &sizes)
{
    if (pos == n + 1)
    {
        if (num >= 2 and num <= 10)
        {
            int sum=0,l=1,r;
            for (int i=0;i<num;i++)
            {
                r = l + sizes[i] - 1;
                sum += diff(l,r);
                l = r + 1;
            }
            if (sum < ans)
                ans = sum;
        }
        return;
    }
    if (num >= 10)
        return;
    for (int i=2;i<=10;i++)
    {
        if (pos + i - 1 <= n)
        {
            sizes.push_back(i);
            dfs(pos+i,num+1,sizes);
            sizes.pop_back();
        }
    }
}

int main()
{
    vector<int> sizes;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    dfs(1,0,sizes);
    cout << ans << endl;
}