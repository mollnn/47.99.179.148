#include <bits/stdc++.h>
using namespace std;

#define int long long

int f[105];

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int c, v;
        cin >> c >> v;
        for (int j = m; j >= c; j--)
            f[j] = max(f[j], f[j - c] + v);
    }
    cout << (f[m] > 0 ? f[m] : 0) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}