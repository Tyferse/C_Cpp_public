#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int n, m;

    cin >> n >> m;

    long long A[n][m];
    for (int i = 0; i < n; i++) {
        A[i][0] = 1;
    }

    for (int j = 0; j < m; j++) {
        A[0][j] = 1;
        cout << setw(6) << 1;
    }

    cout << endl;

    for (int i = 1; i < n; i++) {
        cout << setw(6) << 1;
        // printf("%6d", 1);
        for (int j = 1; j < m; j++) {
            A[i][j] = A[i - 1][j] + A[i][j - 1];
            cout << setw(6) << A[i][j];
            // printf("%6d", A[i][j]);
        }

        cout << endl;
    }


    return 0;
}
