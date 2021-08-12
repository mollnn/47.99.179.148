#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef struct
{
    int X;
    int Y;
} POINT;

typedef struct
{
    double s;
    double e;
} AREA;

POINT p[20005];
AREA a[20005];

using namespace std;

void Qsort(AREA a[], int low, int high)
{
    if (low >= high)
        return;
    int first = low;
    int last = high;
    AREA key = a[first]; /*用字表的第一个记录作为枢轴*/
    while (first < last)
    {
        while (first < last && a[last].e >= key.e)
            --last;
        a[first] = a[last];
        while (first < last && a[first].e <= key.e)
            ++first;
        a[last] = a[first];
    }
    a[first] = key; /*枢轴记录到位*/
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}

signed main()
{
    int i, j, t1, t2, n, d, n_r, count = 0;

    double f_t;
    double r;

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        int flag = 0;
        count++;
        if (n == 0 && d == 0)
            return 0;
        for (i = -1; ++i < n;)
        {
            cin >> p[i].X >> p[i].Y;
            if (p[i].Y > d)
                flag = 1;
            f_t = sqrt((double)(d * d - p[i].Y * p[i].Y));
            a[i].s = (double)p[i].X - f_t;
            a[i].e = (double)p[i].X + f_t;
        }
        if (d <= 0)
            goto CANNOTDOIT;
        if (flag == 1)
            goto CANNOTDOIT;
        Qsort(a, 0, n - 1);
        n_r = 1;
        r = a[0].e;
        for (i = 0; ++i < n;)
        {
            if (r > a[i].e)
                r = a[i].e;
            if (a[i].s > r)
            {
                n_r++;
                r = a[i].e;
            }
        }
        goto GONEXT;
    CANNOTDOIT:
        n_r = -1;
    GONEXT:
        cout << n_r << endl;
    }
    return 0;
}