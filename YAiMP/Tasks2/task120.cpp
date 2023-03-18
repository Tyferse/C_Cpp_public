#include <iomanip>
#include <iostream>
using namespace std;


float f(int n) {
    float nf = 1.;
    float ans = 1.;
    for (int i = 1; i <= n; i++) {
        // if (nf == 0)
        //     break;

        nf = nf / i;
        ans += nf;
        // ans += 1. / nf;
        // nf *= i + 1;
        //cout << ans << " " << nf << " " << i << endl;
    }

    return ans;
}


int main () {
    int n;
    cin >> n;

    cout << f(n);
    // for (int i = 1; i <= 1000; i++){
    //     cout.precision(6);
    //     cout << i << " " << f(i) << endl;
    // }
    
    return 0;
}
