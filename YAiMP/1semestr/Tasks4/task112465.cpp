#include <iostream>
// #include <fstream>
#include <cmath>
using namespace std;


int main() {
    const int max_digits = 10000;
    const int base = 1000000000, cell_l = (int)log10(base);
    const int length = max_digits / cell_l + 1;
    int A[length] = {}, N, B[length] = {};
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

    c = fgetc(fin);
    fscanf(fin, "%d", &N);

    fclose(fin);
    // fin.close();


    // Division
    int subdiv = 0, submod, dvs, mainmod, i = A[0];
    while (i > 0) {
        if (dvs == 0) {
            dvs = A[i];
            i--;
        }
        
        if (subdiv == 0)
            subdiv = dvs / N;

        B[i] = subdiv;
    
    }


    // Writing to file
    // ofstream fout;
    // fout.open("output.txt", ios_base::out);
    FILE * fout = fopen("output.txt", "a");

    int tmp;
    for (int i = A[0]; i > 0; i--) {
        if (A[i] < base && i != A[0]) {
            tmp = A[i] > 0 ? A[i] : 1;
            while (tmp < base / 10) {
                printf("0");
                // fout << 0;
                // cout << 0;
                tmp *= 10;
            }
        }

        printf("%d", A[i]);
        // fout << A[i];
        // cout << A[i];
    }

    // fout.close();
    fclose(fout);
    
    return 0;
}
