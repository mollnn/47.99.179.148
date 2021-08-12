#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_NODE = 10005;
const int MAX_EDGE = 100005;

template <class T>
class Kru
{ // 使用Kruskal算法计算最小生成树
public:
    struct ufs
    {
        int fa[MAX_NODE];
        void reset(int maxnode)
        {
            for (int i = 0; i <= maxnode; i++)
                fa[i] = i;
        }
        ufs(int maxnode)
        {
            reset(maxnode);
        }
        ufs()
        {
            reset(MAX_NODE);
        }
        int find(int p)
        {
            int t = p, tt = p, tmp;
            while (t && fa[t] - t)
                t = fa[t];
            while (tt && fa[tt] - tt)
                tmp = fa[tt], fa[tt] = t, tt = tmp;
            return t;
        }
        void merge(int p, int q)
        {
            p = find(p);
            q = find(q);
            if (p - q)
                fa[p] = q;
        }
    } s;
    struct edge
    {
        int u, v;
        T w;
        bool operator<(const edge &x) const
        {
            return (this->w < x.w);
        }
    } e[MAX_EDGE];
    int n, m;
    T ans;
    void reset_graph()
    {
        memset(e, 0, sizeof e);
        n = m = 0;
    }
    void reset_solver(int numNodes)
    {
        n = numNodes;
        ans = 0; // 类型依赖
        s.reset(numNodes);
    }
    void make_edge(int u, int v, T w)
    {
        edge tmp;
        tmp.u = u;
        tmp.v = v;
        tmp.w = w;
        e[++m] = tmp;
    }
    T solve(int numNodes)
    { // 执行主计算任务
        reset_solver(numNodes);
        sort(e + 1, e + m + 1);
        for (int i = 1; i <= m; i++)
        {
            if (s.find(e[i].u) - s.find(e[i].v))
                s.merge(e[i].u, e[i].v),
                    ans += e[i].w;
        }
        for (int i = 2; i <= n; i++)
            if (s.find(i) != s.find(1))
                return -1;
        return ans;
    }
};

Kru<int> graph;

signed main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        graph.reset_graph();
        graph.n = n;
        graph.m = m;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            graph.make_edge(x, y, z);
        }
        cout << graph.solve(n) << endl;
    }
}