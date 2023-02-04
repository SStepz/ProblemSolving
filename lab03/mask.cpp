/*
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int n,fir,sec,a,b,nfir,nsec,na,nb,mx=-1,deg=0;
    cin >> n;
    int arr[4*n],sel[4];
    for (int i=0;i<4*n;i++)
        cin >> arr[i];
    for (int i=0;i<4*n;i++)
    {
        if (i%n == n-1)
        {
            if (arr[i] > mx)
                mx = arr[i];
            sel[deg] = mx;
            deg += 1;
            mx = -1;
        }
        else if (arr[i] > mx)
            mx = arr[i];
    }
    if (sel[0] > sel[1])
    {
        a = sel[1];
        if (sel[2] > sel[3])
        {
            b = sel[3];
            if (sel[0] > sel[2])
            {
                fir = sel[0];
                sec = sel[2];
            }
            else
            {
                fir = sel[2];
                sec = sel[0];
            }
        }
        else
        {
            b = sel[2];
            if (sel[0] > sel[3])
            {
                fir = sel[0];
                sec = sel[3];
            }
            else
            {
                fir = sel[3];
                sec = sel[0];
            }
        }
    }
    else
    {
        a = sel[0];
        if (sel[2] > sel[3])
        {
            b = sel[3];
            if (sel[1] > sel[2])
            {
                fir = sel[1];
                sec = sel[2];
            }
            else
            {
                fir = sel[2];
                sec = sel[1];
            }
        }
        else
        {
            b = sel[2];
            if (sel[1] > sel[3])
            {
                fir = sel[1];
                sec = sel[3];
            }
            else
            {
                fir = sel[3];
                sec = sel[1];
            }
        }
    }
    for (int i=0;i<4*n;i++)
    {
        if (arr[i] == fir)
            nfir = i;
        else if (arr[i] == sec)
            nsec = i;
        else if (arr[i] == a)
            na = i;
        else if (arr[i] == b)
            nb = i;
    }
    cout << nfir+1 << ' ' << nsec+1 << ' ' << na+1 << ' ' << nb+1 << endl;
}