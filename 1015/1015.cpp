#include <bits/stdc++.h>
using namespace std;

int n, m, L[50005], R[50005], H[50005];

struct Event
{
    int x, y, z;
    bool operator<(const Event b)
    {
        return x < b.x;
    }
} E[100005];

int a[200005];

void modify(int p, int l, int r, int pos, int val)
{
    while (pos <= 200000)
    {
        a[pos] += val;
        pos += pos & (-pos);
    }
}

int sum(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += a[i];
        i -= i & (-i);
    }
    return ans;
}

int query(int p, int l, int r, int ql, int qr)
{
    return sum(qr) - sum(ql - 1);
}

int find(int p, int l, int r, int k)
{
    l = 0, r = 200000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int res = sum(mid);
        if (res > k)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int lastans = 0;
int imp[200005];

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i] >> R[i] >> H[i];
        mp[L[i]]++;
        mp[R[i]]++;
        mp[L[i] - 1]++;
        mp[R[i] + 1]++;
    }
    int ind = 0;
    for (auto &x : mp)
        x.second = ++ind, imp[ind] = x.first;
    for (int i = 1; i <= n; i++)
    {
        L[i] = mp[L[i]];
        R[i] = mp[R[i]];
        E[2 * i - 1] = (Event){L[i], H[i], +1};
        E[2 * i] = (Event){R[i], H[i], -1};
    }
    sort(E + 1, E + 2 * n + 1);
    for (int i = 1; i <= n * 2; i++)
    {
        modify(1, 1, ind, 1, E[i].z);
        modify(1, 1, ind, E[i].y, -E[i].z);
        if (E[i].x != E[i + 1].x)
        {
            int tmpans = find(1, 1, ind, 0);
            if (tmpans != lastans)
            {
                lastans = tmpans;
                cout << imp[E[i].x] << " " << tmpans << endl;
            }
        }
    }
}