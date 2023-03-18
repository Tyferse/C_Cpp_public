#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
// #include <windows.h>
#define g 9.8
using namespace std;


double f1(double x) {
    return x * x * x + 2 * x * x - 8 * x + 1 + 2 * sin(x) + 15 * cos(x);
}


float parabola(float x) {
    return x * x;
}


double f3(double x, double a, double v0) {
    return x * tan(a / 180 * M_PI) - g * x * x /
           (2 * v0 * v0 * cos(a / 180 * M_PI) * cos(a / 180 * M_PI));
}


float ellipsis(float x, float a, float b) {
    return sqrt(b * b - b * b / (a * a) * x * x);
}


double f4b(double x) {
    return 4 * cos(x);
}


void pr1() {
    double a = -5, b = 5, eps = 0.001;

    while (a + 2 * eps < b) {
        if (f1(a) * f1(a + 2 * eps) > 0)
            a += 2 * eps;
        else {
            cout << setprecision(4) << a + eps << endl;
            a += 2 * eps;
        }
    }
}


void pr2() {
    double c, a = -5, b = 5, eps = 0.001;
    int k = 0;
    while (a < b) {
        while (b - a > eps) {
            c = (a + b) / 2;

            if (f1(a) * f1(c) <= 0) {
                b = c;
            }
            else
                a = c;

            k++;
            // cout << c << " ";
        }

        cout << "Solution: ";
        cout << setprecision(4) << (a + b - eps) / 2 << "; steps: " << k << endl;

        a = c + 2 * eps;
        b = 5, k = 0;
        while (f1(a) * f1(b) > 0 and a < b) {
            a += 0.01;
            b -= 0.01;
            // cout << '(' << a << ' ' << b << ')' << endl;
        }
    }
}


void pr3a() {
    float x = 0, h = 0.1, len = 0;
    float y1, y2;
    while (x < 10) {
        y2 = parabola(x + h);
        y1 = parabola(x);
        len += sqrtf(h * h + (y2 - y1) * (y2 - y1));
        x += h;
    }

    cout << len << endl;
}


void pr3b() {
    double alpha = 65.8;
    double v0 = (10 / cos(alpha / 180 * M_PI))
                * sqrt(g / (20 * tan(alpha / 180 * M_PI) - 4));

    float x = 0, h = 0.1, len = 0;
    float y1, y2;
    while (x < 10) {
        y2 = f3(x + h, alpha, v0);
        y1 = f3(x, alpha, v0);
        len += sqrtf(h * h + (y2 - y1) * (y2 - y1));
        x += h;
    }

    cout << len << endl;
}


void pr3c() {
    float a = 2, b = 3;
    float x = 0, h = 0.05, len = 0;
    float y1, y2;
    while (x < a - h) {
        y2 = ellipsis(x + h, a, b);
        y1 = ellipsis(x, a, b);
        len += sqrtf(h * h + (y2 - y1) * (y2 - y1));
        x += h;
        // cout << "f(" << x << ") = " << y2 << endl;
    }

    cout << 4 * len << " ~ ";

    float L = M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    cout << L << endl;
    cout << "Error: " << ((L - 4 * len) / L) * 100 << "%" << endl;
}


void pr4a() {
    float x = 0, h = 0.1, S = 0;
    float y1, y2;
    while (x < 10) {
        y2 = parabola(x + h);
        y1 = parabola(x);
        S += (y2 + y1) / 2;
        x += h;
    }

    cout << S * h << endl;
}


void pr4b() {
    double t1, t2, a = -5, b = 5, eps = 0.001, p[2];
    int k = 0;
    while (a + 2 * eps < b) {
        t1 = parabola(a) - f4b(a);
        t2 = parabola(a + 2 * eps) - f4b(a + 2 * eps);
        if (t1 * t2 > 0)
            a += 2 * eps;
        else {
            cout  << "Intersection point " << k + 1 << ": " << a + eps << endl;
            p[k] = a + eps;
            k++;
            a += 2 * eps;
        }
    }

    double S = 0, h = 0.01;
    for (double x = p[0]; x < p[1]; x += h) {
        S += (f4b(x) - parabola(x) + f4b(x + h) - parabola(x + h)) / 2;
    }

    S *= h;
    cout << S << endl;
}


void pr4c() {
    double a = 2, b = 3, S = 0, h = 0.09;
    for (double x = 0; x < a - h; x += h) {
        S += (ellipsis(x, a, b) + ellipsis(x + h, a, b)) / 2;
    }

    S *= h;
    cout << 4 * S << " ~ ";

    double S2 = M_PI * a * b;
    cout << S2 << endl;
    cout << "Error: " << ((S2 - 4 * S) / S2) * 100 << "%";
}


int main() {
    // SetConsoleCP(CP_REGION);
    // pr1();
    // pr2();
    // pr3a();
    // pr3b();
    // pr3c();
    // pr4a();
    // pr4b();
    // pr4c();
}
