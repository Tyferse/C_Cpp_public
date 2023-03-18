#include <cmath>
#include <iostream>
using namespace std;


int f(int h, int a, int b) {
    int dif, days;
    dif = a - b;
    days = (h - b - 1) / dif + 1; 
    return days;
}


int main() {
    int h, a, b;
    cin >> h;
    cin >> a;
    cin >> b;

    cout << f(h, a, b);


    return 0;
}
