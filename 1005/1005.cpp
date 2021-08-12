#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;

int a[N];
int n;

int quicksort(int l, int h, int depth = 1)
{
    if (l >= h)
    {
        return 0;
    }
    if (l + 1 == h)
    {
        if (a[l] > a[h])
        {
            int temp = a[l];
            a[l] = a[h];
            a[h] = a[l];
        }
        return 0;
    }
    int p = l;
    for (int i = l; i <= h; i++)
    {
        if (a[l] > a[i])
        {
            p++;
            int temp = a[p];
            a[p] = a[i];
            a[i] = temp;
        }
    }
    int temp = a[l];
    a[l] = a[p];
    a[p] = temp;

    if (depth < 2)
    {
        quicksort(l, p - 1, depth + 1);
        quicksort(p + 1, h, depth + 1);
    }

    return 0;
}

void solve()
{
    cin >> n;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quicksort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
