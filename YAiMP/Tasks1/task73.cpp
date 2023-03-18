#include <iostream>
using namespace std;


int main () {
    int n, a1, a2, k, last_d;
    cin >> n >> a1;

    k = n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a2;
        if (a1 == a2)
            k--;
        
        a1 = a2;
    }

    cout << k;
    
    return 0;
}
