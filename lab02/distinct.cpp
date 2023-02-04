/*
LANG: C++
*/

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n],total;
    set<int> s;
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i=0;i<n;i++)
    {
        total = arr[i];
        s.insert(arr[i]);
        for (int j=i+1;j<n;j++)
        {
            total += arr[j];
            s.insert(total);
        }
    }
    cout << s.size() << endl;
}