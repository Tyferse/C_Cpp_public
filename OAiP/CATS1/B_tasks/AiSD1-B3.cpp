#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int n, a;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);

    long long s = 0;
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &a);
        s += a;
    }

    fclose(f1);

    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%ld", s);
    fclose(f2);

    return 0;
}
