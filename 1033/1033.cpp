#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;

signed a[N], tag[N];

void pushup(int p)
{
    a[p] = min(a[p * 2], a[p * 2 + 1]);
}

void pushdown(int p)
{
    if (tag[p] == 0)
        return;
    tag[p * 2] += tag[p];
    tag[p * 2 + 1] += tag[p];
    a[p * 2] += tag[p];
    a[p * 2 + 1] += tag[p];
    tag[p] = 0;
}

void build(int p, int l, int r)
{
    if (l == r)
        a[p] = l;
    else
        build(p * 2, l, (l + r) / 2), build(p * 2 + 1, (l + r) / 2 + 1, r), pushup(p);
}

void modify(int p, int l, int r, int ql, int qr, int x)
{
    if (l > qr || r < ql)
        return;
    if (l >= ql && r <= qr)
    {
        a[p] += x;
        tag[p] += x;
    }
    else
    {
        pushdown(p);
        modify(p * 2, l, (l + r) / 2, ql, qr, x);
        modify(p * 2 + 1, (l + r) / 2 + 1, r, ql, qr, x);
        pushup(p);
    }
}

struct Pair
{
    int d, p;
    bool operator<(const Pair &rhs) const
    {
        if (p == rhs.p)
            return d > rhs.d;
        else
            return p > rhs.p;
    }
} p[N / 2];

void solve()
{
    int n;
    cin >> n;
    memset(a, 0, sizeof a);
    memset(tag, 0, sizeof tag);
    for (int i = 1; i <= n; i++)
        cin >> p[i].d >> p[i].p, p[i].d = min(p[i].d, n);
    sort(p + 1, p + n + 1);
    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i].d <= 0)
            continue;
        modify(1, 1, n, p[i].d, n, -1);
        if (a[1] < 0)
        {
            modify(1, 1, n, p[i].d, n, 1);
        }
        else
        {
            ans += p[i].p;
        }
    }
    cout << ans << endl;
}

signed main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
}