#pragma GCC optimize(4)
#include <bits/stdc++.h>
using namespace std;

// Init: init() !!!!!
// Input: make(u,v,cap,cost)
// Solver: solve(s,t)
// Output: ans, cost
namespace flow
{
    const int N = 205;
    const int M = 5005;
    const int inf = 1e9;
    struct Edge
    {
        int p, c, w, nxt = -1;
    } e[M];
    int s, t, tans, ans, cost, ind, bus[N], qhead = 0, qtail = -1, qu[M], vis[N], dist[N];

    void reset()
    {
        for (int i = 0; i < N; i++)
            e[i].p = 0, e[i].c = 0, e[i].w = 0, e[i].nxt = -1;
        s = 0;
        t = 0;
        tans = 0;
        ans = 0;
        cost = 0;
        ind = 0;
        memset(bus, 0, sizeof bus);
        qhead = 0;
        qtail = -1;
        memset(qu, 0, sizeof qu);
        memset(vis, 0, sizeof vis);
        memset(dist, 0, sizeof dist);
    }

    void graph_link(int p, int q, int c, int w)
    {
        e[ind].p = q;
        e[ind].c = c;
        e[ind].w = w;
        e[ind].nxt = bus[p];
        bus[p] = ind;
        ++ind;
    }
    void make(int p, int q, int c, int w)
    {
        graph_link(p, q, c, w);
        graph_link(q, p, 0, -w);
    }
    int dinic_spfa()
    {
        qhead = 0;
        qtail = -1;
        memset(vis, 0x00, sizeof vis);
        memset(dist, 0x3f, sizeof dist);
        vis[s] = 1;
        dist[s] = 0;
        qu[++qtail] = s;
        while (qtail >= qhead)
        {
            int p = qu[qhead++];
            vis[p] = 0;
            for (int i = bus[p]; i != -1; i = e[i].nxt)
                if (dist[e[i].p] > dist[p] + e[i].w && e[i].c > 0)
                {
                    dist[e[i].p] = dist[p] + e[i].w;
                    if (vis[e[i].p] == 0)
                        vis[e[i].p] = 1, qu[++qtail] = e[i].p;
                }
        }
        return dist[t] < inf;
    }
    int dinic_dfs(int p, int lim)
    {
        if (p == t)
            return lim;
        vis[p] = 1;
        int ret = 0;
        for (int i = bus[p]; i != -1; i = e[i].nxt)
        {
            int q = e[i].p;
            if (e[i].c > 0 && dist[q] == dist[p] + e[i].w && vis[q] == 0)
            {
                int res = dinic_dfs(q, min(lim, e[i].c));
                cost += res * e[i].w;
                e[i].c -= res;
                e[i ^ 1].c += res;
                ret += res;
                lim -= res;
                if (lim == 0)
                    break;
            }
        }
        return ret;
    }
    void solve(int _s, int _t)
    {
        s = _s;
        t = _t;
        ans = 0;
        cost = 0;
        while (dinic_spfa())
        {
            memset(vis, 0x00, sizeof vis);
            ans += dinic_dfs(s, inf);
        }
    }
    void init()
    {
        reset();
        memset(bus, 0xff, sizeof bus);
    }
}

int a[55][55];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    flow::init();
    for (int i = 1; i <= n; i++)
    {	
        int k;
        cin >> k;
        while (k--)
        {
            int j;
            cin >> j;
            flow::make(2 + i, 2 + n + j, 1, a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        flow::make(1, 2 + i, 1, 0);
    for (int i = 1; i <= m; i++)
        flow::make(2 + n + i, 2, 1, 0);
    flow::solve(1, 2);
    cout << flow::ans << " " << flow::cost << endl;
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