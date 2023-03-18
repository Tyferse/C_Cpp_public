#include <iostream>
using namespace std;


int f(int n, int m) {
    int ans = 0;
    ans = (1 << n) | (1 << m);

    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;

    cout << f(n, m);


    return 0;
}
