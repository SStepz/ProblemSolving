/*
LANG: C++
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,c[1001];
    stack<int> s;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        while (true)
        {
            cin >> c[0];
            if (c[0] == 0)
            {
                cout << endl;
                break;
            }
            for (int i=1;i<n;i++)
                cin >> c[i];
            int cpos=0;
            for (int i=1;i<=n;i++)
            {
                s.push(i);
                while (s.empty() == 0 && s.top() == c[cpos] && cpos < n)
                {
                    s.pop();
                    cpos += 1;
                }
            }
            if (s.empty() == 1)
                cout << "Yes" << endl;
            else
            {
                cout << "No" << endl;
                while (s.empty() == 0)
                    s.pop();
            }
        }
    }
}