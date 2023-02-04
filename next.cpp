/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,check,count=0;
    cin >> n;
    int ins[n],arr[n],tmp[n],carr[n];
    for (int i=0;i<n;i++)
    {
        carr[i] = 0;
        arr[i] = i+1;
        cin >> ins[i];
    }
    while (true)
    {
        check = 1;
        for (int i=0;i<n;i++)
            tmp[i] = arr[i];
        for (int i=0;i<n;i++)
        {
            arr[ins[i]-1] = tmp[i];
            if (arr[ins[i]-1] == ins[i])
                carr[i] = 1;
        }
        count += 1;
        for (int i=0;i<n;i++)
        {
            if (carr[i] == 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
            break;
    }
    cout << count << endl;
}