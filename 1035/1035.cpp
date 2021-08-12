#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N], c[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        c[i] = min(c[i], c[i - 1] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * c[i];
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}