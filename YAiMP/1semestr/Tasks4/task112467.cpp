#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


// void f(int *A[], int start) {
//     for (int i = start; i <= *A[0]; i++) {
//         *A[i + 1] = *A[i] / 10;
//         *A[i] %= 10;
//     }

//     if (*A[*A[0] + 1] > 0)
//         *A[0]++;
// }


int main() {
    const int max_digits = 10000;
    // const int base = 1000000, cell_l = (int)log10(base);
    int A[max_digits + 1] = {}, B[max_digits + 1] = {};
    // FILE * fin = fopen("input.txt", "r");
    // ifstream fin;
    // fin.open("input.txt");
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char c;
    int coefficients[A[0] + B[0] + 1] = {A[0] + B[0]};
    int C[max_digits * 2 + 1] = {1};
    // The first number
    
    c = cin.get();
    // fin.read(&c, 1);
    // c = fgetc(fin);
    
    while (48 <= c && c <= 57) {
        for (int i = A[0]; i > 0; i--) {
            A[i + 1] = A[i];
        }

        // cout << A[A[0]] << " => ";
        A[1] = (int(c) - 48);
        A[0]++;
        
        // cout << A[A[0]] << " - A" << endl;
        // cout << A[1] << " - A" << endl;
        c = cin.get();
        // fin.read(&c, 1);
        // c = fgetc(fin);
    }

    // The second number
    // fin.read(&c, 1);
    // fin.read(&c, 1);
    c = cin.get();
    c = cin.get();
    // c = fgetc(fin);
    // c = fgetc(fin);
    while (48 <= c && c <= 57 && !cin.eof() && c != '\n') {
        for (int i = B[0]; i > 0; i--) {
            B[i + 1] = B[i];
        }

        B[1] = (int(c) - 48);
        B[0]++;
        
        // cout << B[B[0]] << " - B" << endl;
        // cout << B[1] << " - B" << endl;
        c = cin.get();
        // fin.read(&c, 1);
        // c = fgetc(fin);
    }

    // cout << A[1] << " " << B[1];

    // fclose(fin);
    // fin.close();


    // Multiplying
    // int coefficients[A[0] + B[0] + 1] = {A[0] + B[0]};
    for (int i = 1; i <= B[0]; i++) {
        for (int j = 1; j <= A[0]; j++) {
            coefficients[j + i - 1] += A[j] * B[i];
            // cout << coefficients[i + j - 1] << " - " << j + i - 1 << endl;
        }
    }

    // for (int j = 0; j <= coefficients[0]; j++) {
    //     cout << coefficients[j] << " - " << j << endl;
    // }

    // int C[max_digits * 2 + 1] = {1};
    for (int i = 1; i <= coefficients[0]; i++) {
        if (i == 1)
            C[i] = coefficients[i] % 10;
        else if (i == coefficients[0]) {
            C[i] = coefficients[i] + coefficients[i - 1] / 10 + C[i - 1] / 10;
            C[i - 1] %= 10;

            if (C[i] != 0)
                C[0] = i;

            // cout << coefficients[i] << " + " << coefficients[i - 1] / 10 << " + " << C[i - 1] / 10 << " = " << coefficients[i] % 10 + coefficients[i - 1] / 10 + C[i - 1] / 10 << endl;
        }
        else {
            C[i] = coefficients[i] % 10 + coefficients[i - 1] / 10 + C[i - 1] / 10;
            C[i - 1] %= 10;
            // cout << C[i] << " => ";
            // if (C[ji] / 10 == 0) {
            //     ji++;
            // }

            // for (int j = ji; j < i; j++) {
            //     C[i] += C[j] / (int)pow(10, i - j);
            //     C[j] %= (int)pow(10, i - j);
            // }
            if (C[i] != 0)
                C[0] = i;

            // cout << coefficients[i] % 10 << " + " << coefficients[i - 1] / 10 << " + " << C[i - 1] / 10 << " = " << coefficients[i] % 10 + coefficients[i - 1] / 10 + C[i - 1] / 10 << endl;
        }

        // if (i == 1)
        //     C[i] = coefficients[i];
        // else {

        //     C[i] = coefficients[i] % 10 + coefficients[i - 1] / 10 + C[i - 1] / 10;
        //     // C[i - 1] %= 10;
        // }
        
        // cout << C[i] << " <= " << C[i - 1] << " (" << coefficients[i] << ")" << endl;
    }

    // if (C[C[0] + 1] != 0)
    //     C[0]++;

    // cout << "_______________" << endl;

    // int ji = 1;
    // while (ji < C[0]) {
    //     for (int i = ji; i <= C[0]; i++) {
    //         C[i + 1] += C[i] / 10;
    //         C[i] %= 10;
    //         cout << C[i + 1] << " <= " << C[i] << endl;
    //     }

    //     if (C[C[0] + 1] > 0)
    //         C[0]++;
        
    //     if (C[ji] / 10 == 0)
    //         ji++;
        
    //     cout << "------------" << endl;
    // }


    // Writing to file
    // ofstream fout;
    // fout.open("output.txt");
    // FILE * fout = fopen("output.txt", "w");
    for (int i = C[0]; i > 0; i--) {
        if (C[i] == 0 && i == C[0])
            continue;

        printf("%d", C[i]);
        // cout << C[i];
        // fout << C[i];
    }
    
    if (C[0] == 1 && C[1] == 0)
        printf("%d", 0);
        // cout << 0;

    
    // fout.close();

    // fill_n(A, max_digits + 1, 0);
    // fill_n(B, max_digits + 1, 0);
    // fill_n(C, max_digits * 2 + 1, 0);
    // C[0] = 1;
    // cout << endl;
    

    return 0;
}
