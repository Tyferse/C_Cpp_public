#include <iostream>
using namespace std;


int gcd(int a, int b) {
    while (a != 0) {
        int c = a % b;
        b = a;
        a = c;
    }

    return b;
}


void reduce(int &a, int &b) {
    int c = gcd(a, b);
    a /= c;
    b /= c;
}


void rec() {
    int n;
    cin >> n;
    if (n != 0) {
        rec();
        cout << n;
    }
}


int fact(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fact(n - 1);
} 


int cnk(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}


bool is_even(int n) {
    return n % 2 == 0;
}


int main() {
    int n, m;

    cin >> n >> m;
    cout << gcd(n, m);

    reduce(n, m);
    cout << n << " " << m;

    if (is_even(n)) {
        cout << "EVEN";
    } 
    else {
        cout << "ODD";
    }
    
    return 0;
}
