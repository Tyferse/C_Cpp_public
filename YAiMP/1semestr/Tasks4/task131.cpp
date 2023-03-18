#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main() {
    const int max_digits = 200;
    const int base = 1000000, cell_l = (int)log10(base);
    const int length = max_digits / cell_l + 1;
    int A[length] = {}, B[length] = {};
    // ifstream fin;
    // fin.open("input.txt", ios_base::in);


    char c = getchar();
    while (48 <= c && c <= 57) {
        for (int i = A[0] - 1; i > 0; i--) {
            A[i + 1] = A[i + 1] * 10 + (A[i] * 10) / base;
            A[i] = (A[i] * 10) % base;
        }

        A[1] += int(c) - 48;
        if (A[A[0] + 1] > 0) {
            A[0]++;
        }

        cout << c << " = " << int(c) - 48 << endl;
        c = getchar();
    }

    c = getchar();
    while (48 <= c && c <= 57) {
        for (int i = B[0] - 1; i > 0; i--) {
            B[i + 1] = B[i + 1] * 10 + (B[i] * 10) / base;
            B[i] = (B[i] * 10) % base;
        }

        B[1] += int(c) - 48;
        if (B[B[0] + 1] > 0) {
            B[0]++;
        }

        cout << c << " = " << int(c) - 48 << endl;
        c = getchar();
    }

    // Comparision
    int max_length = max(A[0], B[0]) + 1;
    for (int i = max_length; i > 0; i--) {
        if (A[i] > B[i]) {
            cout << ">";
            break;
        }
        else if (A[i] < B[i]) {
            cout << "<";
            break;
        }
        else if (A[i] == B[i] && i == 1) {
            cout << "=";
            break;
        }
    }

    return 0;
}
