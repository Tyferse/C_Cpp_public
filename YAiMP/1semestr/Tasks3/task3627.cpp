#include <iostream>
using namespace std;


int main () {
    int n;
    float x, a1, a2, a0 = 0;
    cin >> n >> x >> a2;

    if (n == 0) {
        cout << a2;
    }
    else if (n == 1) {
        cin >> a1;
        cout << a2*x + a1;
    }
    else {
        cin >> a1;
        float summ = a2 * x + a1;
        // cout << summ << endl;
        n--;
        for (int i = n; i > 0; i--) {
            cin >> a0;
            summ = summ * x + a0;
            // cout << summ << endl;
        }

        cout << summ;
    }
    
    return 0;
}
