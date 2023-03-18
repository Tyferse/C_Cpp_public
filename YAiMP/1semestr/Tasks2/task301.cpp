#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


vector<float> f(float a, float b, float c, int x) {
    float D = b*b - 4*a*c;

    if (D >= 0) {
        // switch (x) {
        //     case 1: {
        //         float x1 = (-b + sqrtf(D)) / (2*a);
        //         return x1;
        //         break;
        //     }
        //     case 2: {
        //         float x2 = (-b - sqrtf(D)) / (2*a);
        //         return x2;
        //         break;
        //     }
        //     default:
        //         break;
        // }
        float x1 = (-b + sqrtf(D)) / (2*a);
        float x2 = (-b - sqrtf(D)) / (2*a);
        return {x1, x2};

    }
    else 
        return {NAN};
}


int main (){
    float a, b, c;
    vector<float> v;
    cin >> a >> b >> c;

    // float X1 = f(a, b, c, 1);
    // float X2 = f(a, b, c, 2);
    v = f(a, b, c, 1);
    float X1 = v[0], X2 = v[1];
    if (not isnan(X1)) {
        if (X1 == X2) {
            cout << X1;
        }
        else 
            cout << X1 << " " << X2;
    }
    
    return 0;
}
