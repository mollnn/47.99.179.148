#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 5;

int f[N], a[N];

void solve()
{
    int n;
    cin >> n;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    cout << *max_element(f + 1, f + n + 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();
}