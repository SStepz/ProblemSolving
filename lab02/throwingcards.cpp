/*
LANG: C++
*/

#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    int n;
    list<int> arr;
    list<int>::iterator it;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        if (n == 1)
        {
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: 1" << endl;
        }
        else
        {
            for (int i=1;i<=n;i++)
                arr.push_back(i);
            cout << "Discarded cards: ";
            it = arr.begin();
            cout << *it;
            arr.pop_front();
            arr.splice(arr.end(),arr,arr.begin());
            while (arr.size() > 1)
            {
                it = arr.begin();
                cout << ", " << *it;
                arr.pop_front();
                arr.splice(arr.end(),arr,arr.begin());
            }
            cout << endl << "Remaining card: ";
            it = arr.begin();
            cout << *it << endl;
            arr.clear();
        }
    }
}