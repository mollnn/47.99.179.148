#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 20005;

int n;
int a[N];

void solve()
{
    int t;
    cin >> n >> t;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = n, father = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == t)
        {
            cout << "success, father is " << a[father] << endl;
            return;
        }
        else if (a[mid] < t)
        {
            father = mid;
            l = mid + 1;
        }
        else
        {
            father = mid;
            r = mid - 1;
        }
    }
    cout << "not found, father is " << a[father] << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}