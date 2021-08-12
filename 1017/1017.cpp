#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int b[N];

void add(int i)
{
    while (i < N)
        b[i]++, i += i & (-i);
}

int sum(int i)
{
    int ans = 0;
    while (i > 0)
        ans += b[i], i -= i & (-i);
    return ans;
}

int n;
int a[N];

void solve()
{
    cin >> n;

    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[a[i]]++;
    int ind = 0;
    for (auto &x : mp)
        x.second = ++ind;
    for (int i = 1; i <= n; i++)
        a[i] = mp[a[i]];

    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        ans += sum(a[i] - 1);
        add(a[i]);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
        solve();
}