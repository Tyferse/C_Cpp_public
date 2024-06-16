#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int N, ai;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &N);

    int A[2001] = {};
    for (int i = 0; i < 2001; i++) {
        A[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        fscanf(f1, "%d", &ai);
        A[ai + 1000] += 1;
        // cout << ai << " " << A[ai + 1000] << endl;
    }

    fclose(f1);

    FILE *f2 = fopen("output.txt", "w");
    for (int i = 0; i < 2001; i++) {
        if (A[i] > 0) {
            fprintf(f2, "%d %d\n", i - 1000, A[i]);
            // cout << A[i] << "!!" << endl;
        }
        // else 
            // cout << endl << A[i - 1000] << endl;
    }

    fclose(f2);

    return 0;
}
