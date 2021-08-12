#include <bits/stdc++.h>
const int N = 105;
using namespace std;
int n, m, p, cx[N], cy[N], vis[N];
std::vector<int> e[N];
int dfs(int u, int Time)
{
    for (int i = 0; i < (int)e[u].size(); ++i)
    {
        int v = e[u][i];
        if (vis[v] ^ Time)
        {
            vis[v] = Time;
            if (!cy[v] || dfs(cy[v], Time))
            {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    memset(cx, 0, sizeof cx);
    memset(cy, 0, sizeof cy);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 100; i++)
        e[i].clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            e[i].push_back(x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dfs(i, i);
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