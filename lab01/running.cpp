/*
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,num,k;
    cin >> n >> k;
    double arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    num = n;
    for (int j=1;j<num;j++)
    {
        if (k*arr[0] <= (k-1)*arr[j])
        {
            num = j;
            break;
        }
    }
    cout << num << endl;
}