/*
LANG: C++
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int n,k;
unordered_map<int,int> mem;

int score(int h[], int s[], int ind, int prevh)
{
    int maxscore,tmp,key;
    key = (ind*1000) + prevh;
    if (mem.count(key))
        return mem[key];
    maxscore = s[ind];
    for (int i=ind+1;i<n;i++)
    {
        if (h[i] > prevh)
            continue;
        if (prevh - h[i] <= k)
        {
            tmp = s[ind] + score(h,s,i,h[i]);
            if (tmp > maxscore)
                maxscore = tmp;
        }
    }
    mem[key] = maxscore;
    return maxscore;
}

int main()
{
    int t,ans=0;
    cin >> n >> k;
    int h[n],s[n];
    for (int i=0;i<n;i++)
        cin >> h[i] >> s[i];
    for (int i=0;i<n;i++)
    {
        t = score(h,s,i,h[i]);
        if (t > ans)
            ans = t;
    }
    cout << ans << endl;
}