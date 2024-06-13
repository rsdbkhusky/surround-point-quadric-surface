#include<bits/stdc++.h>
using namespace std;
const int MAXn = 1e5;

template <typename T>
inline void read(T &a) {
    char c;for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar());bool f = c == '-';T x = f ? 0 : (c ^ '0');for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) {x = x * 10 + (c ^ '0');}a = f ? -x : x;
}
template <typename T, typename ...Argv>
inline void read(T &a, Argv &...argv) {
    read(a), read(argv...);
}

const double EPS = 1e-8;
inline int sig(double x) {
    if (x < -EPS) return -1;
    else if (x > EPS) return 1;
    else return 0;
}
struct Point {
    double x, y, z;
    inline Point operator>>(Point sec) {return Point{sec.x - x, sec.y - y};}
    inline double operator*(Point sec) {return x * sec.x + y * sec.y;}
    inline double operator&(Point sec) {return x * sec.y - y * sec.x;}
    inline bool operator<(const Point sec) const {
        if (x != sec.x) return x < sec.x;
        else return y < sec.y;
    }
};
inline double length(Point a) {
    return sqrt(a * a);
}

int n;
Point a[MAXn + 10];

int bottomc, cntc, c[MAXn + 10]; bool inc[MAXn + 10];
inline void pop(int id) {
    while (cntc > bottomc && sig((a[c[cntc - 1]] >> a[c[cntc]]) & (a[c[cntc]] >> a[id])) <= 0) {
        inc[c[cntc]] = 0;
        --cntc;
    }	
}
inline void push(int id) {
    inc[id] = 1;
    c[++cntc] = id;
}
void evaconv() {
    bottomc = 1; cntc = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        pop(i); push(i);
    }
    bottomc = cntc;
    for (int i = n; i; --i) {
        if (inc[i]) continue;
        pop(i); push(i);
    }
    pop(1);
}

bool in[100000];
signed main() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z);
    }
    evaconv();
    puts("Points which on the two-dimensional convex hull:");
    for (int i = 1; i <= cntc; ++i) {
        in[c[i]] = 1;
        printf("(%lf,\t%lf,\t%lf)\n", a[c[i]].x, a[c[i]].y, a[c[i]].z);
    }
    puts("Points which not on the two-dimensional convex hull:");
    for (int i = 1; i <= n; ++i) {
        if (in[i]) continue;
        printf("(%lf,\t%lf,\t%lf)\n", a[i].x, a[i].y, a[i].z);
    }
    return 0;
}
