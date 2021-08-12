#include <bits/stdc++.h>
using namespace std;

#define int long long

int f[10005];

void solve()
{
    int n, m;
    cin >> m >> n;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
    {
        int c, v;
        cin >> c >> v;
        for (int j = c; j <= m; j++)
            f[j] = max(f[j], f[j - c] + v);
    }
    cout << f[m] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}