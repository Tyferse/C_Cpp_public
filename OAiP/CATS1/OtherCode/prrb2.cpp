#include <cmath>
#include <iostream>
using namespace std;


float f1(float e) {
    int i;
    float x, s = 0;

    x = 1. / 26;
    i = 1;
    while (x > e) {
        s += x;
        x = 1. / (pow(4, i) + pow(5, i + 2));
        i++;
        // cout << s << endl;
    }

    return s;
}


int main() {
    // int i;
    // float x, e, s = 0;
    // cin >> e;

    // x = 1./26;
    // i = 1;
    // while (x > e) {
    //     s += x;
    //     x = 1. / (pow(4, i) + pow(5, i + 2));
    //     i++;
    //     // cout << s << endl;
    // }

    // float e;
    // cin >> e;
    // cout << f1(e);


    float a1, a2, a3, a4, tmp;
    cin >> a1 >> a2;
    if (a1 > a2) {
            tmp = a2;
            a2 = a1;
            a1 = tmp;
    }
    float is1 = a1, is2 = a2;
    int n = 3;
    for (int i = 0; i < n; i += 2) {
        cin >> a3 >> a4;
        if (a1 > a2) {
            tmp = a2;
            a2 = a1;
            a1 = tmp;
        }
        if (a3 > a4) {
            tmp = a4;
            a4 = a3;
            a3 = tmp;
        }
        // cout << a1 << " " << a2 << endl;
        if (a4 >= a2 and a1 <= a3 and a3 <= a2) {
            // cout << is1 << " " << a2 << " 1 " << is2 << " " << a3 << endl;
            is1 = is1 < a3 ? a3 : is1;
            is2 = is2 > a2 ? a2 : is2;
            // cout << is1 << " 1 " << is2 << endl;
        }
        else if (a3 <= a1 and a1 <= a4 and a2 >= a4) {
            is1 = is1 < a1 ? a1 : is1;
            is2 = is2 > a4 ? a4 : is2;
            // cout << is1 << " 2 " << is2 << endl;
        }
        else if (a1 >= a3 and a2 <= a4) {
            is1 = is1 < a1 ? a1 : is1;
            is2 = is2 > a2 ? a2 : is2;
            // cout << is1 << " 3 " << is2 << endl;
        }
        else if (a3 >= a1 and a4 <= a2) {
            is1 = is1 < a3 ? a3 : is1;
            is2 = is2 > a4 ? a4 : is2;
            // cout << is1 << " 4 " << is2 << endl;
        }
        else {
            is1 = 0;
            is2 = 0;
            break;
        }
        // cout << is1 << " | " << is2 << endl;
        a1 = a3; 
        a2 = a4;
    }
    if (is1 < is2) 
        cout << "Yes " << is1 + 1 << endl;
    else
        cout << "No";


    return 0;
}
