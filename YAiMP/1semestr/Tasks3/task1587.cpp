#include <iostream>
using namespace std;


int main () {
    int n, a1, a2;
    cin >> n;

    if (n <= 1) {
        cin >> a1;
        cout << 0;
    }
    else if (n == 2) {
        cin >> a1 >> a2;
        if (a1 != a2) 
            cout << 0;
        else 
            cout << 1;
    }
    else {
        // общее количество элементов, входящих в пилообразную последовательность
        int k = 0;
        bool UpState = false, DownState = false;
        cin >> a1;
        // количество одинаковых пар элементов
        int k_equals = 0;
        --n;
        for (int i = 0; i < n; i++) {
            cin >> a2;
            if (a1 == a2) 
                k_equals++;
            else if ((a1 < a2) && !UpState) {
                UpState = true;
                DownState = false;
                k++;
            }
            else if ((a1 > a2) && !DownState) {
                UpState = false;
                DownState = true;
                k++;
            }
        
            a1 = a2;

            // // cout << a1 << " " << a2 << " " << a3 << endl;
            // if ((a1 < a2 and a2 < a3) or (a1 > a2 and a2 > a3) or a1 == a2 or a2 == a3) {
            //     a2 = a3;
            //     k++;
            //     // cout << "1cond " << n << endl;
            // }
            // else {
            //     a1 = a2;
            //     a2 = a3;
            // }

            // if (a1 == a2 and a2 == a3 and n > 0) {
            //     cin >> a2;
            //     k++;
            //     n--;
            //     // cout << "3cond " << n << endl;
            // }
        }

        if (k_equals == n) 
            cout << k_equals;
        else
            cout << n - k;
    }
    
    return 0;
}
