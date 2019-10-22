#include <bits/stdc++.h>
using namespace std;

bool prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int check[101] = {0};

int all_prime()
{
    for (int i = 2; i < 101; i++)
        if (prime(i))
            check[i] = 1;
}

int main()
{
    all_prime();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        if (a[0] != 1)
            cout << "-1\n";
        else
        {
            bool flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (check[a[i]] == 1)
                {
                    cout << a[i] << "\n";
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                cout << "-1\n";
        }
    }
    return 0;
}