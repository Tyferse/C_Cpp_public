#include <iostream>
using namespace std;


int main() {
    double f;
    long long p;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%lf", &f);
    fclose(f1);

    // f = 0 и p < -126
    long long *fi = (long long *)&f;
    p = (*fi >> 52) & ((1 << 11) - 1);
    p -= 1023;  
    if (p < -126) 
        p = -126;
    
    if (f == 0) 
        p = 0;

    // cout << p << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d", p);
    fclose(f2);

    return 0;
}
