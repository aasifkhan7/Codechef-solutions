#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int exponentiation(long long int a, long long int b, long long int M)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return exponentiation((a * a) % M, b / 2, M);
    else
        return (((a % M) * exponentiation((a * a) % M, (b - 1) / 2, M)) % M);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, ans;
        cin >> n >> k;
        if (k == 1)
            ans = 1;
        else
        {
            long long int num = exponentiation(k, n, mod);
            num -= 1;
            num = ((k % mod) * (num % mod)) % mod;
            long long int den = k - 1;
            den = exponentiation(den, mod - 2, mod);
            ans = ((num % mod) * (den % mod)) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}