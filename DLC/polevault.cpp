/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,q,x;
    cin >> n >> q;
    int l[n];
    for (int i=0;i<n;i++)
        cin >> l[i];
    for (int i=0;i<q;i++)
    {
        int sum,fin=0;
        cin >> x;
        for (int j=0;j<n;j++)
        {
            if (fin == 1)
                break;
            sum = l[j];
            if (sum > x)
                continue;
            if (sum == x)
            {
                cout << "Y";
                fin = 1;
                break;
            }
            for (int k=j+1;k<n;k++)
            {
                sum += l[k];
                if (sum > x)
                    break;
                if (sum == x)
                {
                    cout << "Y";
                    fin = 1;
                    break;
                }
            }
        }
        if (fin == 0)
            cout << "N";
    }
    cout << endl;
}