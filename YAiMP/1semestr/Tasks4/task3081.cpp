#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int xi, n = 0, s = 0;
    double a;

    cin >> xi;
    while (xi != 0) {
        s += xi;
        a += xi * xi;
        n++;
        cin >> xi;
    }

    a = a - double(s) * s / n;
    a = sqrt(a / (n - 1));
    cout << setprecision(11) << fixed << a;


    return 0;
}
