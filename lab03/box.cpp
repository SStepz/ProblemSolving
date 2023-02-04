/*
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

char arr[30][30];
bool mem[30][30];
int n,m;

bool visited(int x1,int x2,int y1,int y2)
{
    if (mem[x1][y1] && mem[x1][y2] && mem[x2][y1] && mem[x2][y2])
        return false;
    else
        return true;
}

bool path(int y1,int y2,int x1,int x2)
{
    mem[y1][x1] = true;
    mem[y1][x2] = true;
    mem[y2][x1] = true;
    mem[y2][x2] = true;
    if (arr[y2][x1] == 'F' && arr[y2][x2] == 'F')
        return true;
    if (visited(y1+1,y2+1,x1,x2) && (arr[y1+1][x1] == '.' || arr[y1+1][x1] == 'F') && (arr[y1+1][x2] == '.' || arr[y1+1][x2] == 'F') && (arr[y2+1][x1] == '.' || arr[y2+1][x1] == 'F') && (arr[y2+1][x2] == '.' || arr[y2+1][x2] == 'F') && y1+1 < n && y2+1 < n)
    {
        if (path(y1+1,y2+1,x1,x2))
            return true;
    }
    if (visited(y1,y2,x1+1,x2+1) && (arr[y1][x1+1] == '.' || arr[y1][x1+1] == 'F') && (arr[y1][x2+1] == '.' || arr[y1][x2+1] == 'F') && (arr[y2][x1+1] == '.' || arr[y2][x1+1] == 'F') && (arr[y2][x2+1] == '.' || arr[y2][x2+1] == 'F') && x1+1 < m && x2+1 < m)
    {
        if (path(y1,y2,x1+1,x2+1))
            return true;
    }
    if (visited(y1-1,y2-1,x1,x2) && (arr[y1-1][x1] == '.' || arr[y1-1][x1] == 'F') && (arr[y1-1][x2] == '.' || arr[y1-1][x2] == 'F') && (arr[y2-1][x1] == '.' || arr[y2-1][x1] == 'F') && (arr[y2-1][x2] == '.' || arr[y2-1][x2] == 'F') && y1-1 > -1 && y2-1 > -1)
    {
        if (path(y1-1,y2-1,x1,x2))
            return true;
    }
    if (visited(y1,y2,x1-1,x2-1) && (arr[y1][x1-1] == '.' || arr[y1][x1-1] == 'F') && (arr[y1][x2-1] == '.' || arr[y1][x2-1] == 'F') && (arr[y2][x1-1] == '.' || arr[y2][x1-1] == 'F') && (arr[y2][x2-1] == '.' || arr[y2][x2-1] == 'F') && x1-1 > -1 && x2-1 > -1)
    {
        if (path(y1,y2,x1-1,x2-1))
            return true;
    }
    return false;
}

int main()
{
    int check=0;
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            mem[i][j] = false;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin >> arr[i][j];
    }
    for (int i=0;i<m;i++)
        arr[n-1][i] = 'F';
    for (int i=0;i<m;i++)
    {
        if (arr[0][i] == '.' && arr[1][i] == '.' && arr[0][i+1] == '.' && arr[1][i+1] == '.' && path(0,1,i,i+1))
            check = 1;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                mem[i][j] = false;
        }
    }
    if (check == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}