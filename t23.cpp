#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        cin >> a[0];
        for (int i = 1; i < n; i++)
            cin >> a[i];
        set<int> s(a, a + n);
        set<int>::iterator it1 = s.begin();
        set<int>::iterator it2 = s.end();
        if (s.size() == 1)
        {
            if (*it1 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int first = *it1;
            it1++;
            if (first == 1)
            {
                cout << "YES\n";
            }
            else
            {
                bool flag = 0;
                while (it1 != it2)
                {
                    if (*it1 % first != 0)
                    {
                        flag = 1;
                        break;
                    }
                    it1++;
                }
                if (flag)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}