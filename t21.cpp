#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string m, n;
        cin >> m;
        cin >> n;
        long long int sm = 0, sn = 0;
        for (int i = 0; i < m.length(); i++)
            sm += ((long long int)m[i] - 48);
        for (int i = 0; i < n.length(); i++)
            sn += ((long long int)n[i] - 48);
        long long int ans = ((sm % 3) * (sn % 3)) % 3;
        cout << ans << "\n";
    }
    return 0;
}