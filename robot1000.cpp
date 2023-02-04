/*
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,x=0,y=0;
    string way;
    getline(cin,way);
    n = way.length();
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
    cout << x << ' ' << y << endl;
}