#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef double db;
const db eps = 1e-6;
const db pi = acos(-1);
int sign(db k)
{
    if (k > eps)
        return 1;
    else if (k < -eps)
        return -1;
    return 0;
}
int cmp(db p1, db p2) { return sign(p1 - p2); }
int inmid(db p1, db p2, db p3) { return sign(p1 - p3) * sign(p2 - p3) <= 0; } // p3 在 [p1,p2] 内
struct point
{
    db x, y;
    point operator+(const point &p1) const { return (point){p1.x + x, p1.y + y}; }
    point operator-(const point &p1) const { return (point){x - p1.x, y - p1.y}; }
    point operator*(db p1) const { return (point){x * p1, y * p1}; }
    point operator/(db p1) const { return (point){x / p1, y / p1}; }
    int operator==(const point &p1) const { return cmp(x, p1.x) == 0 && cmp(y, p1.y) == 0; }
    // 逆时针旋转
    point turn(db p1) { return (point){x * cos(p1) - y * sin(p1), x * sin(p1) + y * cos(p1)}; }
    point turn90() { return (point){-y, x}; }
    bool operator<(const point p1) const
    {
        int a = cmp(x, p1.x);
        if (a == -1)
            return 1;
        else if (a == 1)
            return 0;
        else
            return cmp(y, p1.y) == -1;
    }
    db abs() { return sqrt(x * x + y * y); }
    db abs2() { return x * x + y * y; }
    db dis(point p1) { return ((*this) - p1).abs(); }
    point unit()
    {
        db w = abs();
        return (point){x / w, y / w};
    }
    void scan()
    {
        double p1, p2;
        cin >> p1 >> p2;
        x = p1;
        y = p2;
    }
    void print() { printf("%.11lf %.11lf\n", x, y); }
    db getw() { return atan2(y, x); }
    point getdel()
    {
        if (sign(x) == -1 || (sign(x) == 0 && sign(y) == -1))
            return (*this) * (-1);
        else
            return (*this);
    }
    int getP() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1); }
};
int inmid(point p1, point p2, point p3) { return inmid(p1.x, p2.x, p3.x) && inmid(p1.y, p2.y, p3.y); }
db cross(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }
db dot(point p1, point p2) { return p1.x * p2.x + p1.y * p2.y; }
db rad(point p1, point p2) { return atan2(cross(p1, p2), dot(p1, p2)); }
// -pi -> pi
int compareangle(point p1, point p2)
{
    return p1.getP() < p2.getP() || (p1.getP() == p2.getP() && sign(cross(p1, p2)) > 0);
}
point proj(point p1, point p2, point q)
{ // q 到直线 p1,p2 的投影
    point k = p2 - p1;
    return p1 + k * (dot(q - p1, k) / k.abs2());
}
point reflect(point p1, point p2, point q) { return proj(p1, p2, q) * 2 - q; }
int clockwise(point p1, point p2, point p3)
{ // p1 p2 p3 逆时针 1 顺时针 -1 否则 0
    return sign(cross(p2 - p1, p3 - p1));
}
int checkLL(point p1, point p2, point p3, point p4)
{ // 求直线 (L) 线段 (S)p1,p2 和 p3,p4 的交点
    return cmp(cross(p3 - p1, p4 - p1), cross(p3 - p2, p4 - p2)) != 0;
}
point getLL(point p1, point p2, point p3, point p4)
{
    db w1 = cross(p1 - p3, p4 - p3), w2 = cross(p4 - p3, p2 - p3);
    return (p1 * w2 + p2 * w1) / (w1 + w2);
}
int intersect(db l1, db r1, db l2, db r2)
{
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return cmp(r1, l2) != -1 && cmp(r2, l1) != -1;
}
int checkSS(point p1, point p2, point p3, point p4)
{
    return intersect(p1.x, p2.x, p3.x, p4.x) && intersect(p1.y, p2.y, p3.y, p4.y) &&
           sign(cross(p3 - p1, p4 - p1)) * sign(cross(p3 - p2, p4 - p2)) <= 0 &&
           sign(cross(p1 - p3, p2 - p3)) * sign(cross(p1 - p4, p2 - p4)) <= 0;
}
db disSP(point p1, point p2, point q)
{
    point p3 = proj(p1, p2, q);
    if (inmid(p1, p2, p3))
        return q.dis(p3);
    else
        return min(q.dis(p1), q.dis(p2));
}
db disSS(point p1, point p2, point p3, point p4)
{
    if (checkSS(p1, p2, p3, p4))
        return 0;
    else
        return min(min(disSP(p1, p2, p3), disSP(p1, p2, p4)), min(disSP(p3, p4, p1), disSP(p3, p4, p2)));
}
int onS(point p1, point p2, point q) { return inmid(p1, p2, q) && sign(cross(p1 - q, p2 - p1)) == 0; }
struct circle
{
    point o;
    db r;
    void scan()
    {
        o.scan();
        scanf("%lf", &r);
    }
    int inside(point k) { return cmp(r, o.dis(k)); }
};
struct line
{
    // p[0]->p[1]
    point p[2];
    line(point p1, point p2)
    {
        p[0] = p1;
        p[1] = p2;
    }
    point &operator[](int k) { return p[k]; }
    int include(point k) { return sign(cross(p[1] - p[0], k - p[0])) > 0; }
    point dir() { return p[1] - p[0]; }
    line push()
    { // 向外 ( 左手边 ) 平移 eps
        const db eps = 1e-6;
        point delta = (p[1] - p[0]).turn90().unit() * eps;
        return {p[0] - delta, p[1] - delta};
    }
};
point getLL(line p1, line p2) { return getLL(p1[0], p1[1], p2[0], p2[1]); }
int parallel(line p1, line p2) { return sign(cross(p1.dir(), p2.dir())) == 0; }
int sameDir(line p1, line p2) { return parallel(p1, p2) && sign(dot(p1.dir(), p2.dir())) == 1; }
int operator<(line p1, line p2)
{
    if (sameDir(p1, p2))
        return p2.include(p1[0]);
    return compareangle(p1.dir(), p2.dir());
}
int checkpos(line p1, line p2, line p3) { return p3.include(getLL(p1, p2)); }

vector<line> getHL(vector<line> &L)
{ // 求半平面交 , 半平面是逆时针方向 , 输出按照逆时针
    sort(L.begin(), L.end());
    deque<line> q;
    for (int i = 0; i < (int)L.size(); i++)
    {
        if (i && sameDir(L[i], L[i - 1]))
            continue;
        while (q.size() > 1 && !checkpos(q[q.size() - 2], q[q.size() - 1], L[i]))
            q.pop_back();
        while (q.size() > 1 && !checkpos(q[1], q[0], L[i]))
            q.pop_front();
        q.push_back(L[i]);
    }
    while (q.size() > 2 && !checkpos(q[q.size() - 2], q[q.size() - 1], q[0]))
        q.pop_back();
    while (q.size() > 2 && !checkpos(q[1], q[0], q[q.size() - 1]))
        q.pop_front();
    vector<line> ans;
    for (int i = 0; i < q.size(); i++)
        ans.push_back(q[i]);
    return ans;
}
db closepoint(vector<point> &A, int l, int r)
{ // 最近点对 , 先要按照 x 坐标排序
    if (r - l <= 5)
    {
        db ans = 1e20;
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
                ans = min(ans, A[i].dis(A[j]));
        return ans;
    }
    int mid = l + r >> 1;
    db ans = min(closepoint(A, l, mid), closepoint(A, mid + 1, r));
    vector<point> B;
    for (int i = l; i <= r; i++)
        if (abs(A[i].x - A[mid].x) <= ans)
            B.push_back(A[i]);
    sort(B.begin(), B.end(), [](point p1, point p2) { return p1.y < p2.y; });
    for (int i = 0; i < B.size(); i++)
        for (int j = i + 1; j < B.size() && B[j].y - B[i].y < ans; j++)
            ans = min(ans, B[i].dis(B[j]));
    return ans;
}
int checkposCC(circle p1, circle p2)
{ // 返回两个圆的公切线数量
    if (cmp(p1.r, p2.r) == -1)
        swap(p1, p2);
    db dis = p1.o.dis(p2.o);
    int w1 = cmp(dis, p1.r + p2.r), w2 = cmp(dis, p1.r - p2.r);
    if (w1 > 0)
        return 4;
    else if (w1 == 0)
        return 3;
    else if (w2 > 0)
        return 2;
    else if (w2 == 0)
        return 1;
    else
        return 0;
}
vector<point> getCL(circle p1, point p2, point p3)
{ // 沿着 p2->p3 方向给出 , 相切给出两个
    point k = proj(p2, p3, p1.o);
    db d = p1.r * p1.r - (k - p1.o).abs2();
    if (sign(d) == -1)
        return {};
    point del = (p3 - p2).unit() * sqrt(max((db)0.0, d));
    return {k - del, k + del};
}
vector<point> getCC(circle p1, circle p2)
{ // 沿圆 p1 逆时针给出 , 相切给出两个
    int pd = checkposCC(p1, p2);
    if (pd == 0 || pd == 4)
        return {};
    db a = (p2.o - p1.o).abs2(), cosA = (p1.r * p1.r + a - p2.r * p2.r) / (2 * p1.r * sqrt(max(a, (db)0.0)));
    db b = p1.r * cosA, c = sqrt(max((db)0.0, p1.r * p1.r - b * b));
    point k = (p2.o - p1.o).unit(), m = p1.o + k * b, del = k.turn90() * c;
    return {m - del, m + del};
}
vector<point> TangentCP(circle p1, point p2)
{ // 沿圆 p1 逆时针给出
    db a = (p2 - p1.o).abs(), b = p1.r * p1.r / a, c = sqrt(max((db)0.0, p1.r * p1.r - b * b));
    point k = (p2 - p1.o).unit(), m = p1.o + k * b, del = k.turn90() * c;
    return {m - del, m + del};
}
vector<line> TangentoutCC(circle p1, circle p2)
{
    int pd = checkposCC(p1, p2);
    if (pd == 0)
        return {};
    if (pd == 1)
    {
        point k = getCC(p1, p2)[0];
        return {(line){k, k}};
    }
    if (cmp(p1.r, p2.r) == 0)
    {
        point del = (p2.o - p1.o).unit().turn90().getdel();
        return {(line){p1.o - del * p1.r, p2.o - del * p2.r}, (line){p1.o + del * p1.r, p2.o + del * p2.r}};
    }
    else
    {
        point p = (p2.o * p1.r - p1.o * p2.r) / (p1.r - p2.r);
        vector<point> A = TangentCP(p1, p), B = TangentCP(p2, p);
        vector<line> ans;
        for (int i = 0; i < A.size(); i++)
            ans.push_back((line){A[i], B[i]});
        return ans;
    }
}
vector<line> TangentinCC(circle p1, circle p2)
{
    int pd = checkposCC(p1, p2);
    if (pd <= 2)
        return {};
    if (pd == 3)
    {
        point k = getCC(p1, p2)[0];
        return {(line){k, k}};
    }
    point p = (p2.o * p1.r + p1.o * p2.r) / (p1.r + p2.r);
    vector<point> A = TangentCP(p1, p), B = TangentCP(p2, p);
    vector<line> ans;
    for (int i = 0; i < A.size(); i++)
        ans.push_back((line){A[i], B[i]});
    return ans;
}
vector<line> TangentCC(circle p1, circle p2)
{
    int flag = 0;
    if (p1.r < p2.r)
        swap(p1, p2), flag = 1;
    vector<line> A = TangentoutCC(p1, p2), B = TangentinCC(p1, p2);
    for (line k : B)
        A.push_back(k);
    if (flag)
        for (line &k : A)
            swap(k[0], k[1]);
    return A;
}
db getarea(circle p1, point p2, point p3)
{
    // 圆 p1 与三角形 p2 p3 p1.o 的有向面积交
    point k = p1.o;
    p1.o = p1.o - k;
    p2 = p2 - k;
    p3 = p3 - k;
    int pd1 = p1.inside(p2), pd2 = p1.inside(p3);
    vector<point> A = getCL(p1, p2, p3);
    if (pd1 >= 0)
        if (pd2 >= 0)
            return cross(p2, p3) / 2;
        else
            return p1.r * p1.r * rad(A[1], p3) / 2 + cross(p2, A[1]) / 2;
    else if (pd2 >= 0)
        return p1.r * p1.r * rad(p2, A[0]) / 2 + cross(A[0], p3) / 2;
    else if (cmp(p1.r, disSP(p2, p3, p1.o)) <= 0)
        return p1.r * p1.r * rad(p2, p3) / 2;
    else
        return cross(A[0], A[1]) / 2 + p1.r * p1.r * (rad(p2, A[0]) + rad(A[1], p3)) / 2;
}
circle getcircle(point p1, point p2, point p3)
{
    db a1 = p2.x - p1.x, b1 = p2.y - p1.y, c1 = (a1 * a1 + b1 * b1) / 2;
    db a2 = p3.x - p1.x, b2 = p3.y - p1.y, c2 = (a2 * a2 + b2 * b2) / 2;
    db d = a1 * b2 - a2 * b1;
    point o = (point){p1.x + (c1 * b2 - c2 * b1) / d, p1.y + (a1 * c2 - a2 * c1) / d};

    return (circle){o, p1.dis(o)};
}
circle getScircle(vector<point> A)
{
    random_shuffle(A.begin(), A.end());
    circle ans = (circle){A[0], 0};
    for (int i = 1; i < A.size(); i++)
        if (ans.inside(A[i]) == -1)
        {
            ans = (circle){A[i], 0};
            for (int j = 0; j < i; j++)
                if (ans.inside(A[j]) == -1)
                {
                    ans.o = (A[i] + A[j]) / 2;
                    ans.r = ans.o.dis(A[i]);
                    for (int k = 0; k < j; k++)
                        if (ans.inside(A[k]) == -1)
                            ans = getcircle(A[i], A[j], A[k]);
                }
        }
    return ans;
}
db area(vector<point> A)
{ // 多边形用 vector<point> 表示 , 逆时针
    db ans = 0;
    for (int i = 0; i < A.size(); i++)
        ans += cross(A[i], A[(i + 1) % A.size()]);
    return ans / 2;
}
int checkconvex(vector<point> A)
{
    int n = A.size();
    A.push_back(A[0]);
    A.push_back(A[1]);
    for (int i = 0; i < n; i++)
        if (sign(cross(A[i + 1] - A[i], A[i + 2] - A[i])) == -1)
            return 0;
    return 1;
}
int contain(vector<point> A, point q)
{ // 2 内部 1 边界 0 外部
    int pd = 0;
    A.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        point u = A[i - 1], v = A[i];
        if (onS(u, v, q))
            return 1;
        if (cmp(u.y, v.y) > 0)
            swap(u, v);
        if (cmp(u.y, q.y) >= 0 || cmp(v.y, q.y) < 0)
            continue;
        if (sign(cross(u - v, q - v)) < 0)
            pd ^= 1;
    }
    return pd << 1;
}
vector<point> ConvexHull(vector<point> A, int flag = 1)
{ // flag=0 不严格 flag=1 严格
    int n = A.size();
    vector<point> ans(n * 2);
    sort(A.begin(), A.end());
    int now = -1;
    for (int i = 0; i < A.size(); i++)
    {
        while (now > 0 && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) < flag)
            now--;
        ans[++now] = A[i];
    }
    int pre = now;
    for (int i = n - 2; i >= 0; i--)
    {
        while (now > pre && sign(cross(ans[now] - ans[now - 1], A[i] - ans[now - 1])) < flag)
            now--;
        ans[++now] = A[i];
    }
    ans.resize(now);
    return ans;
}
db convexDiameter(vector<point> A)
{
    int now = 0, n = A.size();
    db ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        now = max(now, i);
        while (1)
        {
            db p1 = A[i].dis(A[now % n]), p2 = A[i].dis(A[(now + 1) % n]);
            ans = max(ans, max(p1, p2));
            if (p2 > p1)
                now++;
            else
                break;
        }
    }
    return ans;
}
vector<point> convexcut(vector<point> A, point p1, point p2)
{
    // 保留 p1,p2,p 逆时针的所有点
    int n = A.size();
    A.push_back(A[0]);
    vector<point> ans;
    for (int i = 0; i < n; i++)
    {
        int w1 = clockwise(p1, p2, A[i]), w2 = clockwise(p1, p2, A[i + 1]);
        if (w1 >= 0)
            ans.push_back(A[i]);
        if (w1 * w2 < 0)
            ans.push_back(getLL(p1, p2, A[i], A[i + 1]));
    }
    return ans;
}
int checkPoS(vector<point> A, point p1, point p2)
{
    // 多边形 A 和直线 ( 线段 )p1->p2 严格相交 , 注释部分为线段
    struct ins
    {
        point m, u, v;
        int operator<(const ins &k) const { return m < k.m; }
    };
    vector<ins> B;
    //if (contain(A,p1)==2||contain(A,p2)==2) return 1;
    vector<point> poly = A;
    A.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
        if (checkLL(A[i - 1], A[i], p1, p2))
        {
            point m = getLL(A[i - 1], A[i], p1, p2);
            if (inmid(A[i - 1], A[i], m) /*&&inmid(p1,p2,m)*/)
                B.push_back((ins){m, A[i - 1], A[i]});
        }
    if (B.size() == 0)
        return 0;
    sort(B.begin(), B.end());
    int now = 1;
    while (now < B.size() && B[now].m == B[0].m)
        now++;
    if (now == B.size())
        return 0;
    int flag = contain(poly, (B[0].m + B[now].m) / 2);
    if (flag == 2)
        return 1;
    point d = B[now].m - B[0].m;
    for (int i = now; i < B.size(); i++)
    {
        if (!(B[i].m == B[i - 1].m) && flag == 2)
            return 1;
        int tag = sign(cross(B[i].v - B[i].u, B[i].m + d - B[i].u));
        if (B[i].m == B[i].u || B[i].m == B[i].v)
            flag += tag;
        else
            flag += tag * 2;
    }
    //return 0;
    return flag == 2;
}
int checkinp(point r, point l, point m)
{
    if (compareangle(l, r))
    {
        return compareangle(l, m) && compareangle(m, r);
    }
    return compareangle(l, m) || compareangle(m, r);
}
int checkPosFast(vector<point> A, point p1, point p2)
{ // 快速检查线段是否和多边形严格相交
    if (contain(A, p1) == 2 || contain(A, p2) == 2)
        return 1;
    if (p1 == p2)
        return 0;
    A.push_back(A[0]);
    A.push_back(A[1]);
    for (int i = 1; i + 1 < A.size(); i++)
        if (checkLL(A[i - 1], A[i], p1, p2))
        {
            point now = getLL(A[i - 1], A[i], p1, p2);
            if (inmid(A[i - 1], A[i], now) == 0 || inmid(p1, p2, now) == 0)
                continue;
            if (now == A[i])
            {
                if (A[i] == p2)
                    continue;
                point pre = A[i - 1], ne = A[i + 1];
                if (checkinp(pre - now, ne - now, p2 - now))
                    return 1;
            }
            else if (now == p1)
            {
                if (p1 == A[i - 1] || p1 == A[i])
                    continue;
                if (checkinp(A[i - 1] - p1, A[i] - p1, p2 - p1))
                    return 1;
            }
            else if (now == p2 || now == A[i - 1])
                continue;
            else
                return 1;
        }
    return 0;
}
// 拆分凸包成上下凸壳 凸包尽量都随机旋转一个角度来避免出现相同横坐标
// 尽量特判只有一个点的情况 凸包逆时针
void getUDP(vector<point> A, vector<point> &U, vector<point> &D)
{
    db l = 1e100, r = -1e100;
    for (int i = 0; i < A.size(); i++)
        l = min(l, A[i].x), r = max(r, A[i].x);
    int wherel, wherer;
    for (int i = 0; i < A.size(); i++)
        if (cmp(A[i].x, l) == 0)
            wherel = i;
    for (int i = A.size(); i; i--)
        if (cmp(A[i - 1].x, r) == 0)
            wherer = i - 1;
    U.clear();
    D.clear();
    int now = wherel;
    while (1)
    {
        D.push_back(A[now]);
        if (now == wherer)
            break;
        now++;
        if (now >= A.size())
            now = 0;
    }
    now = wherel;
    while (1)
    {
        U.push_back(A[now]);
        if (now == wherer)
            break;
        now--;
        if (now < 0)
            now = A.size() - 1;
    }
}
// 需要保证凸包点数大于等于 3,2 内部 ,1 边界 ,0 外部
int containCoP(const vector<point> &U, const vector<point> &D, point k)
{
    db lx = U[0].x, rx = U[U.size() - 1].x;
    if (k == U[0] || k == U[U.size() - 1])
        return 1;
    if (cmp(k.x, lx) == -1 || cmp(k.x, rx) == 1)
        return 0;
    int where1 = lower_bound(U.begin(), U.end(), (point){k.x, -1e100}) - U.begin();
    int where2 = lower_bound(D.begin(), D.end(), (point){k.x, -1e100}) - D.begin();
    int w1 = clockwise(U[where1 - 1], U[where1], k), w2 = clockwise(D[where2 - 1], D[where2], k);
    if (w1 == 1 || w2 == -1)
        return 0;
    else if (w1 == 0 || w2 == 0)
        return 1;
    return 2;
}
// d 是方向 , 输出上方切点和下方切点
pair<point, point> getTangentCow(const vector<point> &U, const vector<point> &D, point d)
{
    if (sign(d.x) < 0 || (sign(d.x) == 0 && sign(d.y) < 0))
        d = d * (-1);
    point whereU, whereD;
    if (sign(d.x) == 0)
        return mp(U[0], U[U.size() - 1]);
    int l = 0, r = U.size() - 1, ans = 0;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (sign(cross(U[mid + 1] - U[mid], d)) <= 0)
            l = mid + 1, ans = mid + 1;
        else
            r = mid;
    }
    whereU = U[ans];
    l = 0, r = D.size() - 1, ans = 0;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (sign(cross(D[mid + 1] - D[mid], d)) >= 0)
            l = mid + 1, ans = mid + 1;
        else
            r = mid;
    }
    whereD = D[ans];
    return mp(whereU, whereD);
}
// 先检查 contain, 逆时针给出
pair<point, point> getTangentCoP(const vector<point> &U, const vector<point> &D, point k)
{
    db lx = U[0].x, rx = U[U.size() - 1].x;
    if (k.x < lx)
    {
        int l = 0, r = U.size() - 1, ans = U.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (clockwise(k, U[mid], U[mid + 1]) == 1)
                l = mid + 1;
            else
                ans = mid, r = mid;
        }
        point w1 = U[ans];
        l = 0, r = D.size() - 1, ans = D.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (clockwise(k, D[mid], D[mid + 1]) == -1)
                l = mid + 1;
            else
                ans = mid, r = mid;
        }
        point w2 = D[ans];
        return mp(w1, w2);
    }
    else if (k.x > rx)
    {
        int l = 1, r = U.size(), ans = 0;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (clockwise(k, U[mid], U[mid - 1]) == -1)
                r = mid;
            else
                ans = mid, l = mid + 1;
        }
        point w1 = U[ans];
        l = 1, r = D.size(), ans = 0;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (clockwise(k, D[mid], D[mid - 1]) == 1)
                r = mid;
            else
                ans = mid, l = mid + 1;
        }
        point w2 = D[ans];
        return mp(w2, w1);
    }
    else
    {
        int where1 = lower_bound(U.begin(), U.end(), (point){k.x, -1e100}) - U.begin();
        int where2 = lower_bound(D.begin(), D.end(), (point){k.x, -1e100}) - D.begin();
        if ((k.x == lx && k.y > U[0].y) || (where1 && clockwise(U[where1 - 1], U[where1], k) == 1))
        {
            int l = 1, r = where1 + 1, ans = 0;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (clockwise(k, U[mid], U[mid - 1]) == 1)
                    ans = mid, l = mid + 1;
                else
                    r = mid;
            }
            point w1 = U[ans];
            l = where1, r = U.size() - 1, ans = U.size() - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (clockwise(k, U[mid], U[mid + 1]) == 1)
                    l = mid + 1;
                else
                    ans = mid, r = mid;
            }
            point w2 = U[ans];
            return mp(w2, w1);
        }
        else
        {
            int l = 1, r = where2 + 1, ans = 0;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (clockwise(k, D[mid], D[mid - 1]) == -1)
                    ans = mid, l = mid + 1;
                else
                    r = mid;
            }
            point w1 = D[ans];
            l = where2, r = D.size() - 1, ans = D.size() - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (clockwise(k, D[mid], D[mid + 1]) == -1)
                    l = mid + 1;
                else
                    ans = mid, r = mid;
            }
            point w2 = D[ans];
            return mp(w1, w2);
        }
    }
}

int case_id = 0;

void solve()
{
    ++case_id;
    int n;
    cin >> n;
    vector<point> v;
    for (int i = 1; i <= n; i++)
    {
        point pt;
        pt.scan();
        v.push_back(pt);
    }
    sort(v.begin(), v.end());
    vector<point> u;
    for (auto i : v)
    {
        if (u.size() == 0)
            u.push_back(i);
        else if (!(u.back() == i))
            u.push_back(i);
    }
    v = u;
    v = ConvexHull(v);
    int min_id = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].y < v[min_id].y || (v[i].y == v[min_id].y && v[i].x < v[min_id].x))
            min_id = i;
    }
    cout << "case " << case_id << ":" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        int id = (i + min_id) % v.size();
        cout << (int)v[id].x << " " << (int)v[id].y << endl;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}