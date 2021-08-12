#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;

int a[N];
int n;

void adjust(int p)
{
    int lc = p * 2;
    int rc = p * 2 + 1;
    if (lc > n)
        return;
    if (rc > n)
    {
        if (a[p] > a[lc])
            swap(a[p], a[lc]);
        return;
    }
    if (a[lc] <= a[rc] && a[p] > a[lc])
    {
        swap(a[p], a[lc]);
        adjust(lc);
    }
    else if (a[lc] > a[rc] && a[p] > a[rc])
    {
        swap(a[p], a[rc]);
        adjust(rc);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        adjust(n - i + 1);
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}