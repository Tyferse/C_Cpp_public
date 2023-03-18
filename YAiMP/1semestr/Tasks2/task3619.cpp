#include <cmath>
#include <iostream>
using namespace std;


float f(float a, float b, float c, int x) {
    float D = b*b - 4*a*c;

    if (a == 0) 
        return -c / b;
    else if (b == 0 and -c / a >= 0) 
        return sqrt(-c / a);

    if (D >= 0) {
        switch (x) {
            case 1: {
                float x1 = (-b + sqrt(D)) / (2*a);
                return x1;
                break;
            }
            case 2: {
                float x2 = (-b - sqrt(D)) / (2*a);
                return x2;
                break;
            }
            default:
                break;
        }
    }
    
    return NAN;
}


int main () {
    float a, b, c;
    cin >> a >> b >> c;

    float X1 = f(a, b, c, 1);
    float X2 = f(a, b, c, 2);

    if (a == 0 and b == 0 and c == 0) 
        cout << 3;
    else if (a == 0 and b == 0 and c != 0) 
        cout << 0;
    else if (not isnan(X1)) {
        if (X1 == X2) {
            cout << 1 << " " << X1;
        }
        else 
            cout << 2 << " " << min(X1, X2) << " " << max(X1, X2);
    }
    else 
        cout << 0;
    
    return 0;
}
