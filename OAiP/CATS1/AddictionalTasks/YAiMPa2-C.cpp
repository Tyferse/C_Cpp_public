#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int n;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);

    int b[n];
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &b[i]);
    }

    FILE *f2 = fopen("output.txt", "w");

    int total = 0;
    char c;
    fscanf(f1, "\n\r%c", &c);
    // cout << c << "|";
    for (int i = 0; i < n; i++) {
        if (c == '+')
            total += b[i];
        
        fscanf(f1, "%c", &c);
        // cout << c;
    }

    // cout << endl << total;
    fprintf(f2, "%d", total);

    fclose(f1);
    fclose(f2);

    return 0;
}
