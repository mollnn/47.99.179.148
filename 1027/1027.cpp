#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

struct item
{
    int l, r, v;
    bool operator<(const item &rhs) const
    {
        return r < rhs.r;
    }
} a[N];

int f[N];
int n;

vector<int16_t> g[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r >> a[i].v;
    sort(a + 1, a + n + 1);
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = a[i].r;
        while (last < now)
            f[last + 1] = f[last], ++last;
        int id = i;
        int l = a[id].l, r = a[id].r, v = a[id].v;
        f[r] = max(f[r], f[l] + v);
    }
    cout << f[a[n].r] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}