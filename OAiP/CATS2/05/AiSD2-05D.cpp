#include <iostream> 
#include <cmath>
using namespace std;


int main() {
    long long n, k;
    cin >> n >> k;

    if (k < 3) 
        cout << n;
    else if (n == k) {
        cout << 2;
    }
    else {
        long long  ksum = 0, max_degree = log10(n) / log10(k);
        long long kpows[max_degree + 1] = {1};
        int kcountsysn[max_degree + 1] = {0};
        for (int i = 1; i <= max_degree; i++) {
            kpows[i] = kpows[i - 1] * k;
        }

        for (int i = max_degree; i >= 0; i--) {
            if (ksum + kpows[i] <= n) {
                ksum += kpows[i];
                kcountsysn[i] = 1;
            }
        }

        long long ans = 0, pow2 = 1;
        for (int i = 0; i <= max_degree; i++) {
            ans += kcountsysn[i] * pow2;
            pow2 *= 2;
        }

        cout << ans;
    }

    return 0;
}
