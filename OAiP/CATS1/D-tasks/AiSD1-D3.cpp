#include <cmath>
#include <iostream>
using namespace std;


int gcd(int a, int b) {
    int d = 1;
    while (a != 0 and b != 0) {
        if (a > b) 
            a = a % b;
        else
            b = b % a;
        
        if (a == 0) {
            d = b;
            return b;
        }
        else if (b == 0) {
            d = a;
            return a;
        }
    }

    return d;
}


int main() {
    int a, b;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d", &a, &b);
    fclose(f1);

    int d = gcd(a, b);
    int lc = a * b / d;

    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d %d", d, lc);
    fclose(f2);

    return 0;
}
