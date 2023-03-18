#include <iostream>
#include <cmath>
using namespace std;


int f(int a, int i) {
    int ans = 0, mask;
    mask = pow(2, i);
    ans = a ^ mask;

    return ans;
}


int main() {
    int a, i;
    cin >> a >> i;

    cout << f(a, i);


    return 0;
}
