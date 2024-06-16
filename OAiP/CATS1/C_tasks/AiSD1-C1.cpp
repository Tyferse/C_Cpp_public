#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int n, ai;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);
    int A[n] = {};
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &ai);
        if (i == 0) 
            A[i] = ai;
        else 
            A[i] = ai + A[i - 1];
        
        cout << A[i] << endl;
    }

    int M, lj, rj;
    fscanf(f1, "%d", &M);
    FILE *f2 = fopen("output.txt", "w");
    for (int j = 0; j < M; j++) {
        fscanf(f1, "%d %d", &lj, &rj);
        // cout << A[rj] << " " << A[lj] << endl;
        if (lj == 1) 
            fprintf(f2, "%d ", A[rj - 1]);
        else
            fprintf(f2, "%d ", A[rj - 1] - A[lj - 2]);

        cout << A[rj - 1] - A[lj - 1] << endl;
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
