/*
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,t;
    int pos=0,ans=0;
    cin >> s;
    cin >> t;
    for (int i=0;i<t.length();i++)
    {
        if (t[i] == s[pos])
        {
            if (pos == s.length() - 1)
            {
                ans += 1;
                pos = 0;
            }
            pos += 1;
        }
    }
    cout << ans << endl;
}