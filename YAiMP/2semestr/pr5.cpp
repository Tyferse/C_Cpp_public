#include <iostream>
#include <cmath>
#include <iomanip>
#define phi 1.6180339887498949
using namespace std;


float f(float x) {
    return x * x * x + 2 * x * x - 8 * x + 1 + 2 * sin(x) + 15 * cos(x);
}

int main() {
    float x1, x2, a = -5, b = 5, eps = 0.001;
    while (b - a >= 2 * eps) {
        x1 = b - (b - a) / phi;
        x2 = a + (b - a) / phi;
        // cout << x1 << " " << x2 << endl;
        if (f(x2) < f(x1))
            a = x1;
        else 
            b = x2;
    }

    float xmin = (a + b) / 2;
    cout << "Min: (";
    cout << fixed << setprecision(3) << xmin << ", " << f(xmin) << ")" << endl;

    b = 5, a = -5;
    while (b - a >= 2 * eps) {
        x1 = b - (b - a) / phi;
        x2 = a + (b - a) / phi;
        if (f(x2) > f(x1))
            a = x1;
        else 
            b = x2;
    }

    float xmax = (a + b) / 2;
    cout << "Max: (";
    cout << fixed << setprecision(3) << xmax << ", " << f(xmax) << ")" << endl;
}
