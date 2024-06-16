#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int N;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &N);

    int a[N];
    for (int i = 0; i < N; i++) {
        fscanf(f1, "%d", &a[i]);
    }

    fclose(f1);

    int maxs = 0, L, M, R;

    for (int i = 0; i < N - 1; i++) {
        int ri = i, mi = i, M_sum = a[i], R_sum = 0;

        while (ri < N) {
            if (M_sum < R_sum) {
                mi++; 
                M_sum += a[mi];
                R_sum -= a[mi];
            }
            else { 
                ri++; 
                R_sum += a[ri]; 
            }

            if ((M_sum == R_sum) && (M_sum > maxs)) { 
                maxs = M_sum;
                L = i + 1;
                M = mi + 1;
                R = ri + 1;
                // cout << maxs << " " << L << " " << M << " " << R << endl;
            }
        }
    }

    FILE *f2 = fopen("output.txt", "w");

    if (maxs) { 
        fprintf(f2, "%d %d %d", L, M, R); 
    }
    else { 
        fprintf(f2, "%d", -1); 
    }

    fclose(f2);

    return 0;
}
