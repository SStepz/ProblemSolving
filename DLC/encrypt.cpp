/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,s,add=1;
    cin >> n >> s;
    int arr[20],spin[20];
    if (n != 20)
    {
        for (int i=0;i<20;i++)
        {
            if (i >= n)
            {
                arr[i] = add;
                add += 1;
            }
            else
                cin >> arr[i];
        }
    }
    else
    {
        for (int i=0;i<20;i++)
            cin >> arr[i];
    }
    for (int i=0;i<20;i++)
        spin[i] = arr[(i+20-s)%20];
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<4;j++)
            cout << spin[i+(j*5)] << " ";
    }
    cout << endl;
}