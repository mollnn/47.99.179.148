#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 50005;

int f[N][2];

vector<int> g[N];

int n;

void dfs(int p, int from)
{
    f[p][1] = 1;
    for (int q : g[p])
    {
        if (q == from)
            continue;
        dfs(q, p);
        f[p][0] += max(f[q][0], f[q][1]);
        f[p][1] += f[q][0];
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(f[1][0], f[1][1]) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof f);
        solve();
    }
}

