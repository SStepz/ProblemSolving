/*
LANG: C++
*/

#include <iostream>

using namespace std;

char arr[20][20];
bool mem[20][20];
int n,q;

bool travel(int x, int y, int a, int b, int key)
{
    mem[x][y] = 1;
    if (x == a && y == b)
        return true;
    if (mem[x+1][y] == 0 && arr[x+1][y] == '.' && x+1 < n)
    {
        if (travel(x+1,y,a,b,key))
            return true;
    }
    if (mem[x][y+1] == 0 && arr[x][y+1] == '.' && y+1 < n)
    {
        if (travel(x,y+1,a,b,key))
            return true;
    }
    if (mem[x-1][y] == 0 && arr[x-1][y] == '.' && x-1 > -1)
    {
        if (travel(x-1,y,a,b,key))
            return true;
    }
    if (mem[x][y-1] == 0 && arr[x][y-1] == '.' && y-1 > -1)
    {
        if (travel(x,y-1,a,b,key))
            return true;
    }
    if (mem[x+1][y] == 0 && arr[x+1][y] == 'O' && key == 1 && x+1 < n)
    {
        key = 0;
        if (travel(x+1,y,a,b,key))
            return true;
        else
            key = 1;
    }
    if (mem[x][y+1] == 0 && arr[x][y+1] == 'O' && key == 1 && y+1 < n)
    {
        key = 0;
        if (travel(x,y+1,a,b,key))
            return true;
        else
            key = 1;
    }
    if (mem[x-1][y] == 0 && arr[x-1][y] == 'O' && key == 1 && x-1 > -1)
    {
        key = 0;
        if (travel(x-1,y,a,b,key))
            return true;
        else
            key = 1;
    }
    if (mem[x][y-1] == 0 && arr[x][y-1] == 'O' && key == 1 && y-1 > -1)
    {
        key = 0;
        if (travel(x,y-1,a,b,key))
            return true;
        else
            key = 1;
    }
    return false;
}

int main()
{
    int r,c,a,b;
    cin >> n >> q;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cin >> arr[i][j];
    }
    for (int i=0;i<q;i++)
    {
        cin >> r >> c >> a >> b;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                mem[i][j] = 0;
        }
        if (travel(r-1,c-1,a-1,b-1,1))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}