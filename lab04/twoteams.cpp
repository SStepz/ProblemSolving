/*
LANG: C++
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m;

int main()
{
    int a,b;
    vector<pair<int,int>> arr;
    cin >> n >> m;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        arr.push_back({a,b});
    }
    cout << m-1 << endl;
}