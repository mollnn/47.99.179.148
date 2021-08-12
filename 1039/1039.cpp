#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;

vector<int> g[N];
int vis[N], dfn[N], ind, deg[N], seq[N];
int n, m;

void dfs(int p)
{
    vis[p] = 1;
    for (int q : g[p])
    {
        if (vis[q])
            continue;
        dfs(q);
    }
    dfn[p] = ++ind;
    seq[ind] = p;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    memset(vis, 0, sizeof vis);
    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }
    memset(dfn, 0, sizeof dfn);
    ind = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0 && vis[i] == 0)
            dfs(i);
    int flag = 1;
    for (int i = 1; i <= n; i++)
        for (int j : g[i])
            if (dfn[i] < dfn[j])
                flag = 0;
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            flag = 0;
    if (flag == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = n; i >= 1; i--)
            cout << seq[i] << " ";
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}