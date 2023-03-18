#include <iostream>
using namespace std;


int main () {
    int a1, a2, a3, k = 0, iMin = 1 << 30, i = 0;
    cin >> a1;
    if (a1 == 0) 
        cout << 0;
    
    cin >> a2;
    if (a2 == 0) 
        cout << 0;

    cin >> a3;
    while (a3 != 0) {
        if (a1 < a2 && a2 > a3) {
            iMin = i < iMin && i > 0 ? i : iMin;
            i = 0;
            k++;
        }
        else if (k > 0) {
            i++;
        }
        
        a1 = a2;
        a2 = a3;
        cin >> a3;
        // cout << "i == " << i << ", iMin == " << iMin << endl;
        // if (a != 0) 
        //     last_a = a;
    }

    // if (last_a == lMax and k > 1) {
    //     cout << i;
    // }
    // else
    if (k > 1)
        cout << iMin + 1;
    else 
        cout << 0;
    
    return 0;
}
