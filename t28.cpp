#include <bits/stdc++.h>
#define min(x, y) (x < y ? x : y)
#define M 1000000009
using namespace std;

long long int exponentiation(long long int a, long long int b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return exponentiation((a * a) % M, b / 2);
    else
        return (((a % M) * exponentiation((a * a) % M, (b - 1) / 2)) % M);
}

int main()
{
    long long int n, q;
    cin >> n >> q;
    pair<long long int, long long int> a[n];
    map<long long int, long long int> me;
    map<long long int, long long int> mo;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
        if (a[i].first == a[i].second)
        {
            if (me.find(a[i].first) != me.end())
                me[a[i].first] += 1;
            else
                me[a[i].first] = 1;
        }
        if (abs(a[i].first - a[i].second) == 1)
        {
            int x = min(a[i].first, a[i].second);
            if (mo.find(x) != mo.end())
                mo[x] += 1;
            else
                mo[x] = 1;
        }
    }
    while (q--)
    {
        long long int k;
        cin >> k;
        if (k % 2 == 0)
        {
            if (me.find(k / 2) == me.end())
                cout << "-1\n";
            else
                cout << exponentiation(me[k / 2], M - 2) << "\n";
        }
        else
        {
            if (mo.find(k / 2) == mo.end())
                cout << "-1\n";
            else
                cout << exponentiation(mo[k / 2], M - 2) << "\n";
        }
    }
    return 0;
}