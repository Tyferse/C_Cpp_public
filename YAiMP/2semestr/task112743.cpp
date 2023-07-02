#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


struct point {
    double x;
    double y;
};

point operator+(point pt1, point pt2) {
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}

point operator-(point pt1, point pt2) {
    pt1.x -= pt2.x;
    pt1.y -= pt2.y;
    return pt1;
}

point operator*(double n, point pt) {
    pt.x *= n;
    pt.y *= n;
    return pt;
}

point operator*(point pt, double n) { 
    return n * pt;
}

double operator*(point pt1, point pt2) {
    return pt1.x * pt2.x + pt1.y * pt2.y;
}

double find_point(point inpt1, point dir1, point inpt2, point dir2) {
    double x0 = inpt1.x;
    double y0 = inpt1.y;
    double xr = inpt2.x;
    double yr = inpt2.y;
    double ux = dir1.x;
    double uy = dir1.y;
    double vx = dir2.x;
    double vy = dir2.y;

    if (vx != 0) {     
        double t = ((x0 - xr) * vy / vx + yr - y0) / (uy - ux * vy / vx);
        // s0 = (t * ux + x0 - xr) / vx
        return t;
    }
    else if (vy != 0) {
        double t = ((y0 - yr) * vx / vy + xr - x0) / (ux - uy * vx / vy);
        // s0 = (t * uy + y0 - yr) / vy
        return t;
    }

    return -1;
}

point *sort(point *arr) {
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = i; j < 4; j++) {
            if (arr[i].x > arr[j].x or (arr[i].x == arr[j].x and arr[i].y > arr[j].y)) {
                swap(arr[i], arr[j]);
                // break;
            }
        }
    }
 
    return arr;
}

int main() {
    point a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    bool has = false;
    point v1 = a - b;
    point v2 = c - d;
    point points[4] = {a, b, c, d};
    sort(points);

    // for (int i = 0; i < 4; i++) {
    //     cout << i + 1 << ". " << points[i].x << " " << points[i].y << endl; 
    // }

    // Если хотя бы один из отрезков является точкой
    if (v1.x == 0 and v1.y == 0 and v2.x == 0 and v2.y == 0) {
        if (b.x == d.x and b.y == d.y) {
            cout << fixed << setprecision(10) << b.x << " " << b.y;
            has = true;
        }
    }
    else if (v1.x == 0 and v1.y == 0) {
        double t;
        if (v2.x != 0)
            t = (a.x - d.x) / v2.x;
        else 
            t = (a.y - d.y) / v2.y;

        if (0 <= t and t <= 1) {
            cout << fixed << setprecision(10) << a.x << " " << a.y;
            has = true;
        }
    }
    else if (v2.x == 0 and v2.y == 0) {
        double t;
        if (v1.x != 0)
            t = (c.x - b.x) / v1.x;
        else 
            t = (c.y - b.y) / v1.y;

        if (0 <= t and t <= 1) {
            cout << fixed << setprecision(10) << c.x << " " << c.y;
            has = true;
        }
    }
    // Если угол между отрезками не равен нулю
    else if (fabs(v1 * v2) != sqrt((v1 * v1) * (v2 * v2))) {
        double t1 = find_point(b, v1, d, v2);
        double s1;
        // cout << fixed << setprecision(6) << fabs(v1 * v2) << " " << sqrt(v1 * v1) * sqrt(v2 * v2) << endl;
        // cout << (fabs(v1 * v2) != sqrt((v1 * v1) * (v2 * v2))) << endl;
        // cout << t1 << ": " << (fabs(t1) * v1 + b).x << endl;
        if (v2.x != 0)
            s1 = (t1 * v1.x + b.x - d.x) / v2.x;
        else if (v2.y != 0)
            s1 = (t1 * v1.y + b.y - d.y) / v2.y;

        // cout << s1 << " " << endl;
        if (0 <= t1 and t1 <= 1 and 0 <= s1 and s1 <= 1) {
            has = true;
            point pt = v1 * t1 + b;
            cout << fixed << setprecision(10) << pt.x << " " << pt.y;
        }
    }
    // Если два отрезка параллельны оси OY и лежат на одной прямой
    else if (v1.x == 0 and v2.x == 0 and b.x == d.x) {
        // sort(points);
        if ((a.y < c.y and b.y >= c.y) or (a.y >= c.y and b.y < c.y)
            or (a.y < d.y and b.y >= d.y) or (a.y >= d.y and b.y < d.y)) {
            has = true;
            cout << fixed << setprecision(10) << points[1].x << " " << points[1].y << endl;
            cout << fixed << setprecision(10) << points[2].x << " " << points[2].y << endl;
        }
    }
    // Если два отрезка параллельны оси OX и лежат на одной прямой
    else if (v1.y == 0 and v2.y == 0 and b.y == d.y) {
        // sort(points);
        if ((a.x < c.x and b.x >= c.x) or (a.x >= c.x and b.x < c.x)
            or (a.x < d.x and b.x >= d.x) or (a.x >= d.x and b.x < d.x)) {
            has = true;
            cout << fixed << setprecision(10) << points[1].x << " " << points[1].y << endl;
            cout << fixed << setprecision(10) << points[2].x << " " << points[2].y << endl;
        }
    }
    else if ((a.x - d.x) / v2.x == (a.y - d.y) / v2.y 
             and (b.x - d.x) / v2.x == (b.y - d.y) / v2.y) {
        // sort(points);
        double ta, tb;
        if (v2.x != 0) {
            ta = (a.x - d.x) / v2.x;
            tb = (b.x - d.x) / v2.x;
        }
        else {
            ta = (a.y - d.y) / v2.y;
            tb = (b.y - d.y) / v2.y;
        }

        if ((0 <= ta and ta <= 1) or (0 <= tb and tb <= 1)) {
            has = true;
            cout << fixed << setprecision(10) << points[1].x << " " << points[1].y << endl;
            cout << fixed << setprecision(10) << points[2].x << " " << points[2].y << endl;
        }
    }

    if (!has)
        cout << "Empty";
    
    return 0;
}
