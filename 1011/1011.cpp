#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const double inf = 1e18;

struct vec2
{
    double x, y;
    bool operator<(const vec2 &b)
    {
        if (x != b.x)
            return x < b.x;
        else
            return y < b.y;
    }
} p[N];

bool cmp(const vec2 &a, const vec2 &b)
{
    return a.y < b.y;
}

double dist2(vec2 a, vec2 b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int n;

double solve(int l, int r)
{
    if (l == r)
    {
        return inf;
    }
    else
    {
        int mid = (l + r) / 2;
        double pos = p[mid].x;
        double ans = inf;
        ans = min(ans, solve(l, mid));
        ans = min(ans, solve(mid + 1, r));
        int pl = mid, pr = mid + 1;
        while (pow(p[pl].x - pos, 2) <= ans && pl >= l)
            --pl;
        ++pl;
        while (pow(p[pr].x - pos, 2) <= ans && pr <= r)
            ++pr;
        --pr;
        vector<vec2> v;
        for (int i = pl; i <= pr; i++)
            v.push_back(p[i]);
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ans = min(ans, dist2(v[i], v[j]));
            }
        }
        return ans;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + n + 1);
    printf("%.2lf\n", sqrt(solve(1, n)));
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