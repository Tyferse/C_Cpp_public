#include <iostream>
#include <cmath>
using namespace std;


double f(int n, double x) {
    double ans = 1.;
    double num = x;
    double denum = 1;

    if (n == 1) 
        return ans + x;
        
    for (int i = 2; i - 1 <= n; i++) {
        ans += num / denum;

        num *= x;
        denum *= i;
    }

    return ans;
}


int main () {
    int n;
    double x;
    cin >> n >> x;

    if (n < 13) 
        cout << f(n, x) << endl;
    else if (n >= 13)
        cout << exp(x);
    
    
    return 0;
}
