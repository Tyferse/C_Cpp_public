#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;

    float x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    
    float angle, 
          ab[2] = {x[n - 2] - x[n - 1], y[n - 2] - y[n - 1]}, 
          bc[2] = {x[n - 1] - x[0], y[n - 1] - y[0]};
    
    angle = ab[0] * bc[1] - ab[1] * bc[0];
    bool sign = angle > 0 ? true : false;
    string ans = "YES";

    for (int i = 1; i < n; i++) {
        if (i == 1) {
            ab[0] = x[n - 1] - x[0];
            ab[1] = y[n - 1] - y[0];
            bc[0] = x[0] - x[1];
            bc[1] = y[0] - y[1];
        }
        else {
            ab[0] = x[i - 2] - x[i - 1];
            ab[1] = y[i - 2] - y[i - 1];
            bc[0] = x[i - 1] - x[i];
            bc[1] = y[i - 1] - y[i];
        }

        angle = ab[0] * bc[1] - ab[1] * bc[0];
        if ((angle > 0 && !sign) || (angle < 0 && sign)) {
            ans = "NO";
            break;
        }
    }

    cout << ans;
}
