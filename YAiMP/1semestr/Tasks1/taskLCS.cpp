#include <iostream>
#include <cmath>
using namespace std;


int f(int n, int m) {
    int ans;

    m %= 32;
    if (n >= 0)
        ans = (n << m) | (n >> (32 - m));
    else {
        int mask = (n & (~(1 << (32 - m)) + 1));
        ans = (n << m) | ((mask >> (32 - m)) & ((1 << m) - 1));
    }

    return ans;
}


int main() {
    int n, m, ans;
    cin >> n >> m;

    ans = f(n, m);

    cout << ans;


    return 0;
}
