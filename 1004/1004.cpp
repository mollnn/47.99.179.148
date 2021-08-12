#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> solve(vector<int> a, int depth = 1)
{
    int n = a.size();
    if (n <= 1)
        return a;
    int mid = (n - 1) / 2;
    vector<int> p, q;
    for (int i = 0; i <= mid; i++)
        p.push_back(a[i]);
    for (int i = mid + 1; i < n; i++)
        q.push_back(a[i]);
    p = solve(p, depth + 1);
    q = solve(q, depth + 1);
    vector<int> ans;
    if (depth >= 3)
    {
        int i = 0, j = 0;
        while (i < p.size() && j < q.size())
        {
            if (p[i] < q[j])
                ans.push_back(p[i]), ++i;
            else
                ans.push_back(q[j]), ++j;
        }
        while (i < p.size())
        {
            ans.push_back(p[i]);
            ++i;
        }
        while (j < q.size())
        {
            ans.push_back(q[j]);
            ++j;
        }
    }
    else
    {
        for (int i = 0; i < p.size(); i++)
            ans.push_back(p[i]);
        for (int j = 0; j < q.size(); j++)
            ans.push_back(q[j]);
    }
    return ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        auto ans = solve(a);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}