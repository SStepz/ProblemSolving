/*
LANG: C++
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> temp;

void findlength(vector<int> &arr, vector<int> &length)
{
    int num,pos;
    for (int i=0;i<n;i++)
    {
        num = arr[i];
        pos = lower_bound(temp.begin(),temp.end(),num) - temp.begin();
        if (pos == temp.size())
            temp.push_back(num);
        else
            temp[pos] = num;
        length[i] = pos+1;
    }
    temp.clear();
}

int main()
{
    int tmp;
    while (cin >> n)
    {
        int ans=0;
        vector<int> arr(n),up(n),down(n);
        for (int i=0;i<n;i++)
            cin >> arr[i];
        findlength(arr,up);
        reverse(arr.begin(),arr.end());
        findlength(arr,down);
        for (int i=0;i<n;i++)
        {
            if (down[n-i-1] < up[i])
                tmp = down[n-i-1];
            else
                tmp = up[i];
            tmp = (tmp*2)-1;
            if (tmp > ans)
                ans = tmp;
        }
        cout << ans << "\n";
    }
}