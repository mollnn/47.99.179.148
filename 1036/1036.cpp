#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char x[N], y[N];
int nxt[N]; // x[0..m-1] x[i..m-1] LCP
int ext[N]; // x[0..m-1] y[i..n-1] LCP
int m, n;
void exkmp_presolve(char x[], int m)
{
    nxt[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1])
        j++;
    nxt[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = nxt[k] + k - 1, l = nxt[i - k];
        if (i + l < p + 1)
            nxt[i] = l;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j])
                j++;
            nxt[i] = j;
            k = i;
        }
    }
}
void exkmp(char x[], int m, char y[], int n)
{
    exkmp_presolve(x, m);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])
        j++;
    ext[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = ext[k] + k - 1, l = nxt[i - k];
        if (i + l < p + 1)
            ext[i] = l;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])
                j++;
            ext[i] = j;
            k = i;
        }
    }
}

void solve()
{
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(nxt, 0, sizeof nxt);
    memset(ext, 0, sizeof ext);
    cin >> n >> m >> y >> x;
    exkmp(x, m, y, n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ext[i] >= m)
            ++ans;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}