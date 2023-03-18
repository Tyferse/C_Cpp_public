#include <iostream>
#include <cmath>
using namespace std;


int f(int a, int n) {
    int ans = 0, mask;
    mask = pow(2, n) - 1;
    ans = a & mask;

    return ans;
}


int main() {
    int a, n;
    cin >> a >> n;

    cout << f(a, n);


    return 0;
}
