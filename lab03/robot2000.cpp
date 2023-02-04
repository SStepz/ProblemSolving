/*
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,j=0;
    char way[4]={'N','E','S','W'},face='N';
    string fir,sec;
    getline(cin,fir);
    n = fir.length();
    for (int i=0;i<n;i++)
    {
        if (fir[i] == 'Z')
        {
            sec += 'Z';
            face = 'N';
            j = 0;
        }
        else if (fir[i] == face)
            sec += 'F';
        else
        {
            while (fir[i] != face)
            {
                sec += 'R';
                j += 1;
                j = j%4;
                face = way[j];
            }
            sec += 'F';
        }
    }
    cout << sec << endl;
}