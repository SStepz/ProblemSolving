/*
LANG: C++
*/

#include <iostream>

using namespace std;

char arr[30][30];
bool mem[30][30];
int n,m,quality=0,num=0;

void move(int x, int y, char ssym)
{
    mem[x][y] = 1;
    num += 1;
    if (quality == 0 && arr[x][y] != ssym && (arr[x][y] == '*' || arr[x][y] == '$'))
        quality = 1;
    if (mem[x+1][y] == 0 && arr[x+1][y] != '#' && x+1 < n)
        move(x+1,y,ssym);
    if (mem[x][y+1] == 0 && arr[x][y+1] != '#' && y+1 < m)
        move(x,y+1,ssym);
    if (mem[x-1][y] == 0 && arr[x-1][y] != '#' && x-1 > -1)
        move(x-1,y,ssym);
    if (mem[x][y-1] == 0 && arr[x][y-1] != '#' && y-1 > -1)
        move(x,y-1,ssym);
}

int main()
{
    int ans1=0,ans2=0;
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            mem[i][j] = 0;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mem[i][j] == 0 && (arr[i][j] == '*' || arr[i][j] == '$'))
            {
                move(i,j,arr[i][j]);
                if (quality == 1)
                    ans1 += num;
                else
                    ans2 += num;
            }
            quality = 0;
            num = 0;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}