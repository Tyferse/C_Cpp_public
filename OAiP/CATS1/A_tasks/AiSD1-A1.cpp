#include <iostream>
#include <cmath>
using namespace std;


int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) 
            a = a % b;
        else
            b = b % a;
    }
    return max(a, b);
}


int main() {
    int a, b;
    int c = 1, d = 0;
    FILE * f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d", &a, &b);
    fclose(f1);

    // cout << gcd(a, b) << endl;
    int g = gcd(a, b);
    int a1 = a / g;
    int b1 = b / g;

    int d5 = 0;
    while (b1 % 5 == 0) {
        b1 /= 5;
        d5++;
    }

    int d2 = 0;
    while (b1 % 2 == 0) {
        b1 /= 2;
        d2++;
    }

    int i = 0, b2 = b1, a2 = a1;
    // cout << a1 << " " << a2 << endl;
    // cout << b1 << " " << b2 << endl;
    while (b1 % 2 == 0 and i <= d) {
        a1 /= 2;
        b1 /= 2;
        i++;
    }
    // cout << a1 << " " << a2 << endl;
    // cout << b1 << " " << b2 << endl;
    i = 0;
    while (b2 % 5 == 0 and i <= d) {
        a2 /= 5;
        b2 /= 5;
        i++;
    }

    // cout << a1 << " " << a2 << endl;
    // cout << b1 << " " << b2 << endl;
    c = max(b1, b2);
    d = max(d2, d5);
    // int i = 0;
    // while ((b1 % 2 == 0 or b1 % 5 == 0) and i <= d) {
    //     if (b1 % 5 == 0) {
    //         a1 /= 5;
    //         b1 /= 5;
    //         i++;
    //     }
    //     if (b1 % 2 == 0) {
    //         a1 /= 2;
    //         b1 /= 2;
    //         i++;
    //     }
    // }

    // c = b1;
    /*
    float cch;
    for (int i = 1; i <= b/2; i++) {
        double val = ((a / (int(b) / i)) * pow(10, d));
        double m = modf(val, &cch);
        //cout << (a / (int(b) / i)) << " ! " << endl;
        //cout << m << endl;
        if (int(b) % i == 0 && m == 0) {
            c = i;
            break;
        }
    }
    */

    //cout << c << " " << d;
    FILE * f2 = fopen("output.txt", "w");
    fprintf(f2, "%d %d", c, d);
    fclose(f2);

    return 0;
}
