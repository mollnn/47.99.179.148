#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 50005;

int dis[N], vis[N];
vector<pair<int, int>> g[N];
int n, m;
int s, t;

void solve()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    priority_queue<pair<int, int>> que;
    que.push({0, s});
    while (!que.empty())
    {
        int d = que.top().first;
        int p = que.top().second;
        que.pop();
        vis[p] = 1;
        for (int i = 0; i < g[p].size(); i++)
        {
            int q = g[p][i].first;
            int w = g[p][i].second;
            if (vis[q])
                continue;
            if (dis[q] > dis[p] + w)
            {
                dis[q] = dis[p] + w;
                que.push({-dis[q], q});
            }
        }
    }
    if (dis[t] > 9e9)
        cout << -1 << endl;
    else
        cout << dis[t] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}