/*
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k,x=0,y=0,e=0;
    string way;
    getline(cin,way);
    cin >> k;
    n = way.length();
    if (k < n)
    {
        for (int i=0;i<n;i++)
        {
            if (way[i] == 'N')
                y += 1;
            else if (way[i] == 'S')
                y -= 1;
            else if (way[i] == 'E')
                x += 1;
            else if (way[i] == 'W')
                x -= 1;
            else if (way[i] == 'Z')
            {
                x = 0;
                y = 0;
            }
        }
        while (k != 0)
        {
            if (x > 0)
            {
                e += 1;
                x -= 1;
            }
            else if (x < 0)
            {
                e += 1;
                x += 1;
            }
            else if (y > 0)
            {
                e += 1;
                y -= 1;
            }
            else if (y < 0)
            {
                e += 1;
                y += 1;
            }
            else if (x == 0 && y == 0)
            {
                e += 1;
                k -= 1;
            }
        }
        cout << 2*e << endl;
    }
    else
        cout << 0 << endl;
}