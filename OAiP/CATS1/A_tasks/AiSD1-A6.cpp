#include <iostream>
using namespace std;


int main() {
    int n;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);
    fclose(f1);

    FILE *f2 = fopen("output.txt", "w");

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                fprintf(f2, "%d ", (x + y + z) % n + 1);
            }
            fprintf(f2, "\n");
        }
    }

    fclose(f2);

    return 0;
}