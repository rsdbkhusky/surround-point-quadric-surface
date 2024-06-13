#include<bits/stdc++.h>
#include"eigen-3.3.8/Eigen/Dense"
using namespace std;
using namespace Eigen;

struct Point {
    double x, y, z;
};

vector<double> fitQuadraticSurface(const vector<Point>& points) {
    int n = points.size();
    MatrixXd A(n, 6);
    VectorXd b(n);
    for (int i = 0; i < n; ++i) {
        double x = points[i].x;
        double y = points[i].y;
        double z = points[i].z;
        A(i, 0) = x * x;
        A(i, 1) = y * y;
        A(i, 2) = x * y;
        A(i, 3) = x;
        A(i, 4) = y;
        A(i, 5) = 1;
        b(i) = z;
    }
    VectorXd params = A.colPivHouseholderQr().solve(b);
    vector<double> result(params.data(), params.data() + params.size());
    return result;
}

int main() {
    vector<Point> points;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        Point p;
        cin >> p.x >> p.y >> p.z;
        points.push_back(p);
    }
    vector<double> params = fitQuadraticSurface(points);
    cout << "Parameters obtained by fitting:" << endl;
    char paramNames[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < 6; ++i) {
        cout << paramNames[i] << " = " << params[i] << endl;
    }
    return 0;
}
