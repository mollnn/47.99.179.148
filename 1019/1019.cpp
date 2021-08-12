#include <bits/stdc++.h>
using namespace std;

#define int long long

int f[105];

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
    {
        int c, v;
        cin >> c >> v;
        for (int j = m; j >= c; j--)
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