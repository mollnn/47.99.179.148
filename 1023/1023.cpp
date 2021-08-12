#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, s, t, k;
const int N = 505;
const int M = 105;
vector<pair<int, int>> g[N];
int a[N];
int d[N][M], v[N][M];

void make(int p, int q, int w)
{
    g[p].push_back({q, w});
    g[q].push_back({p, w});
}

void solve()
{
    cin >> n >> m >> s >> t >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        g[i].clear();
    memset(d, 0x3f, sizeof d);
    memset(v, 0x00, sizeof v);
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        make(t1, t2, t3);
    }

    queue<pair<int, int>> que;
    d[s][k] = 0;
    v[s][k] = 1;
    que.push({s, k});
    while (!que.empty())
    {
        int p = que.front().first;
        int i = que.front().second;
        v[p][i] = 0;
        que.pop();
        for (int _ = 0; _ < g[p].size(); _++)
        {
            int q = g[p][_].first;
            int j = i - a[q];
            int w = g[p][_].second;
            if (j < 0)
                continue;
            if (d[q][j] > d[p][i] + w)
            {
                d[q][j] = d[p][i] + w;
                if (!v[q][j])
                    v[q][j] = 1, que.push({q, j});
            }
        }
    }
    int ans = 1e18;
    for (int i = 0; i <= k; i++)
        ans = min(ans, d[t][i]);
    cout << (ans > 1e12 ? -1 : ans) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}