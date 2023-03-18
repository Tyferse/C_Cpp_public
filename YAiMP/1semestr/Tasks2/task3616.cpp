#include <iostream>
using namespace std;


void f(int p, int x, int y, int k) {
    // cout << p << " " << x << " " << y << " " << k << endl;
    // int sum = x * 100 + y;
    // for (int i = 1; i <= k; i++) {
    //     sum += sum * p / 100;
    // }

    // cout << sum / 100 << " " << sum % 100 << endl;
    int yy;
    for (int i = 0; i < k; i++) {
        yy = x * p % 100;
        x = x + x * p / 100;
        y = y + y * p / 100 + yy;
        x = x + y / 100;
        y = y % 100;
    }
    
    cout << x << " " << y << endl;
    
    // cout << x + int(y) / 100 << " " << y - (int(y) / 100) * 100 << endl;
}


int main (){
    int k;
    int p, x, y;

    // p = 12.; x = 179.; y = 0.; k = 5;
    // f(p, x, y, k);
    // f(12, 405, 99, 3);
    // f(19, 197, 79, 5);
    // f(0, 197, 34, 10);
    // f(2, 2000, 45, 1);

    cin >> p >> x >> y >> k;

    f(p, x, y, k);
    // for (int i = 1; i <= k; i++) {
    //     x = x * (1 + p/100);
    //     y = y * (1 + p/100) + (x - int(x)) * 100;
    //     x = int(x);
    //     y = int(y);
    // }

    // cout << x + int(y) / 100 << " " << y - (int(y) / 100) * 100;
    
    return 0;
}
