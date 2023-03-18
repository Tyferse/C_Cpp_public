#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int a, b, k = 0;
    cin >> a >> b;

    while (a != 0 and b != 0) {
        if (a > b) 
            a = a % b;
        else 
            b = b % a;
        
        k += 1;
    }

    cout << max(a, b) << " " << k;


    return 0;
}
