#include<bits/stdc++.h>
using namespace std;
const int MAXn = 2e3;
const double EPS = 1e-9;

int n, cnt, vis[MAXn + 10][MAXn + 10];

mt19937 rd(time(0));
int random(int l, int r) {
    return rd() % (r - l + 1) + l;
}

double randomeps() {
    return ((double)random(0, 327) - 0.5) * EPS;
}

struct Node {
    double x, y, z;
    void shake() {
        x += randomeps();
        y += randomeps();
        z += randomeps();
    }
    double len() { return sqrt(x * x + y * y + z * z); }
    Node operator-(Node A) { return {x - A.x, y - A.y, z - A.z}; }
    Node operator*(Node A) {
        return {y * A.z - z * A.y, z * A.x - x * A.z, x * A.y - y * A.x};
    }
    double operator&(Node A) { return x * A.x + y * A.y + z * A.z; }
} A[MAXn + 10];

struct Face {
    int v[3];
    Node Normal() { return (A[v[1]] - A[v[0]]) * (A[v[2]] - A[v[0]]); }
    double area() { return Normal().len() / 2.0; }
} f[MAXn + 10], C[MAXn + 10];

int see(Face a, Node b) { return ((b - A[a.v[0]]) & a.Normal()) > 0; }

void Convex_3D() {
    f[++cnt] = {1, 2, 3};
    f[++cnt] = {3, 2, 1};
    for (int i = 4, cc = 0; i <= n; i++) {
        for (int j = 1, v; j <= cnt; j++) {
            if (!(v = see(f[j], A[i]))) C[++cc] = f[j];
            for (int k = 0; k < 3; k++) vis[f[j].v[k]][f[j].v[(k + 1) % 3]] = v;
        }
        for (int j = 1; j <= cnt; j++)
            for (int k = 0; k < 3; k++) {
                int x = f[j].v[k], y = f[j].v[(k + 1) % 3];
                if (vis[x][y] && !vis[y][x]) C[++cc] = {x, y, i};
            }
        for (int j = 1; j <= cc; j++) f[j] = C[j];
        cnt = cc;
        cc = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
        A[i].shake();
    }
    Convex_3D();
    set<int> ndset;
    for (int i = 1; i <= cnt; ++i) {
        ndset.insert(f[i].v[0]);
        ndset.insert(f[i].v[1]);
        ndset.insert(f[i].v[2]);
    }
    puts("Points which on the three-dimensional convex hull:");
    for (auto i: ndset) {
        printf("(%lf,\t%lf,\t%lf)\n", A[i].x, A[i].y, A[i].z);
    }
    puts("Points which not on the three-dimensional convex hull:");
    for (int i = 1; i <= n; ++i) {
        if (ndset.find(i) == end(ndset)) {
            printf("(%lf,\t%lf,\t%lf)\n", A[i].x, A[i].y, A[i].z);
        }
    }
    return 0;
}
