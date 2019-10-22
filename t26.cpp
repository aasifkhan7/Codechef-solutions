#include <bits/stdc++.h>
using namespace std;

int bin_search(int a[], int x, int beg, int end)
{
    int mid = (beg + end) / 2;
    if (beg < end)
    {
        if (a[mid] >= x)
            bin_search(a, x, beg, mid);
        else
            bin_search(a, x, mid + 1, end);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        a[l - 1] += 1;
        a[r] -= 1;
    }
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    sort(a, a + n);
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        if (k <= a[0])
            cout << n << "\n";
        else if (k > a[n - 1])
            cout << "0\n";
        else
        {
            int ind = bin_search(a, k, 0, n - 1);
            cout << (n - ind) << "\n";
        }
    }
}