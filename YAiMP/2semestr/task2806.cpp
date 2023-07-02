#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    long long xa, ya, xb, yb, xc, yc, x, y;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    long long ab[2] = {xb - xa, yb - ya}, 
              ac[2] = {xc - xa, yc - ya}, 
              bc[2] = {xc - xb, yc - yb};

    long long a_angle = ac[0] * ab[0] + ac[1] * ab[1], 
              b_angle = ab[0] * bc[0] + ab[1] * bc[1], 
              c_angle = ac[0] * bc[0] + ac[1] * bc[1];
    
    // cout << a_angle << " " << b_angle << " " << c_angle << endl;
    // cout << ab[0] << " " << ab[1] << " : " << bc[0] << " " << bc[1] << " : " << ac[0] << " " << ac[1] << endl;
    if (a_angle == 0) {
        x = ab[0] + ac[0] + xa;
        y = ab[1] + ac[1] + ya;
    }
    else if (b_angle == 0) {
        x = -ab[0] + bc[0] + xb;
        y = -ab[1] + bc[1] + yb;
    }
    else if (c_angle == 0) {
        x = -ac[0] - bc[0] + xc;
        y = -ac[1] - bc[1] + yc;
    }

    cout << x << " " << y;
}
