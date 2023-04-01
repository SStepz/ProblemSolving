/*
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k,tmp;
    int step[4]={0};
    string way;
    getline(cin,way);
    cin >> k;
    n = way.length();
    if (k < n)
    {
        for (int i=0;i<n;i++)
        {
            if (way[i] == 'N')
                step[0] += 1;
            else if (way[i] == 'S')
                step[1] += 1;
            else if (way[i] == 'E')
                step[2] += 1;
            else if (way[i] == 'W')
                step[3] += 1;
        }
        if (step[1] > step[0])
        {
            tmp = step[0];
            step[0] = step[1];
            step[1] = tmp;
        }
        if (step[3] > step[2])
        {
            tmp = step[2];
            step[2] = step[3];
            step[3] = tmp;
        }
        while (k != 0)
        {
            if (step[1] != 0)
            {
                step[1] -= 1;
                k -= 1;
            }
            else if (step[3] != 0)
            {
                step[3] -= 1;
                k -= 1;
            }
            else if (step[0] != 0)
            {
                step[0] -= 1;
                k -= 1;
            }
            else if (step[2] != 0)
            {
                step[2] -= 1;
                k -= 1;
            }
        }
        cout << 2*(step[0] + step[2] - step[1] - step[3]) << endl;
    }
    else
        cout << 0 << endl;
}