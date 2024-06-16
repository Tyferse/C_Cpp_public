#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int n;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);
    fclose(f1);

    FILE *f2 = fopen("output.txt", "w");
    int bin[n];
    int tmp;
    for (int i = 0; i <= (1 << n) - 1; i++) {
        tmp = i;
        // cout << tmp << "!!" << endl;
        for (int j = n - 1; j >= 0; j--) {
            if (j == 0) {
                bin[j] = tmp;
            }
            else if (tmp > 0) {
                bin[j] = tmp % 2;
                tmp /= 2;
            }
            else 
                bin[j] = 0;
        }

        bin[n - 1] = i % 2;
        for (int k = 0; k < n; k++) {
            fprintf(f2, "%d", bin[k]);
            // cout << bin[k];
        }

        fprintf(f2, "\n");
        // cout << endl;
    }

    fclose(f2);

    return 0;
}
