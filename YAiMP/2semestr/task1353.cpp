#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    float xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    float vec1[2] = {xb - xa, yb - ya};
    float vec2[2] = {xc - xa, yc - ya};
    // string ans;
    
    float cross = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    if (cross == 0)
        cout << "BOTH";
    else if (cross > 0)
        cout << "LEFT";
    else
        cout << "RIGHT";
    
    // cout << (vec[0] == 0 && (vec[1] < 0 && xc > xa || vec[1] > 0 && xc < xa)) << endl;
    // cout << (vec[1] == 0 && (vec[0] < 0 && yc < ya || vec[0] > 0 && yc > ya)) << endl;
    // if ((vec[0] == 0 && xc == xa) || (vec[1] == 0 && yc == ya)) 
    //     ans = "BOTH";
    // else if (vec[0] != 0 && vec[1] != 0 && (xc - xa) / vec[0] == (yc - ya) / vec[1]) 
    //     ans = "BOTH";
    // else if ((vec[0] == 0 && (vec[1] < 0 && xc > xa || vec[1] > 0 && xc < xa)) 
    //          || (vec[1] == 0 && (vec[0] < 0 && yc < ya || vec[0] > 0 && yc > ya)))
    //     ans = "LEFT";
    // else if (vec[0] != 0 && vec[1] != 0 && (xc - xa) / vec[0] > (yc - ya) / vec[1])
    //     ans = "LEFT";
    // else
    //     ans = "RIGHT";
}
