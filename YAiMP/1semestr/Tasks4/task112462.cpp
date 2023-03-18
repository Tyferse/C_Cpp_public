#include <iostream>
// #include <fstream>
#include <cmath>
using namespace std;


int main() {
    const int max_digits = 10000;
    const int base = 1000000, cell_l = (int)log10(base);
    const int length = max_digits / cell_l + 1;
    int A[length] = {}, B[length] = {};
    FILE * fin = fopen("input.txt", "r");
    // ifstream fin;
    // fin.open("input.txt", ios_base::in);


    // The first number
    char c;
    // fin.read(&c, 1);
    c = fgetc(fin);
    while (48 <= c && c <= 57) {
        for (int i = A[0]; i > 0; i--) {
            A[i + 1] = A[i + 1] + (A[i] * 10) / base;
            A[i] = (A[i] * 10) % base;
        }

        // cout << A[A[0]] << " => ";
        A[1] += (int(c) - 48);
        if (A[A[0] + 1] > 0) {
            A[0]++;
        }

        // cout << A[A[0]] << " - A" << endl;
        // fin.read(&c, 1);
        c = fgetc(fin);
    }

    // The second number
    // fin.read(&c, 1);
    // fin.read(&c, 1);
    c = fgetc(fin);
    c = fgetc(fin);
    while (48 <= c && c <= 57 && c != EOF) {
        for (int i = B[0]; i > 0; i--) {
            B[i + 1] = B[i + 1] + (B[i] * 10) / base;
            B[i] = (B[i] * 10) % base;
        }

        B[1] += (int(c) - 48);
        if (B[B[0] + 1] > 0) {
            B[0]++;
        }

        // cout << B[B[0]] << " - B" << endl;
        // fin.read(&c, 1);
        c = fgetc(fin);
    }

    fclose(fin);
    // fin.close();


    // Sum
    // cout << A[A[0]] << " " << B[B[0]] << endl;
    int final_len = max(A[0], B[0]) + 1;
    for (int i = 1; i <= final_len; i++) {
        A[i] += B[i];
        A[i + 1] += A[i] / base;
        A[i] %= base;
    }

    if (A[final_len] == 0) 
        final_len -= 1;


    // Writing to file
    // ofstream fout;
    // fout.open("output.txt", ios_base::out);
    FILE * fout = fopen("output.txt", "w");

    int tmp;
    for (int i = final_len; i > 0; i--) {
        if (A[i] < base && i != final_len) {
            tmp = A[i] > 0 ? A[i] : 1;
            while (tmp < base / 10) {
                fprintf(fout, "0");
                // fout << 0;
                // cout << 0;
                tmp *= 10;
            }
        }

        fprintf(fout, "%d", A[i]);
        // fout << A[i];
        // cout << A[i];
    }

    // fout.close();
    fclose(fout);
    
    return 0;
}
