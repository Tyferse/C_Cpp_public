#include <iostream>
#include <fstream>
#include <clocale>
#include <io.h>
#include <fcntl.h>
using namespace std;


int even(char c) {
    int k = 0;
    for (int i = 0; i < 8; i++) {
        if (c % 2 == 1) {
            k++;
            // cout << k << endl;
        }
        c = c >> 1;
    }

    return k;
}


int main() {
    ifstream fin1;
    fin1.open("input.txt", ios_base::in);
    ofstream fout;
    fout.open("output.txt", ios_base::out);
    setlocale(LC_CTYPE, "rus");
    // _setmode(fileno(stdout), );
    // SetConsoleOutputCP(1251);

    unsigned char c;
    c = fin1.get();
    for (int i = 0; !fin1.eof(); i++) {
        c = 128 * (even(c) % 2) + c;
        fout << c;
        cout << c;
        c = fin1.get();
    }

    return 0;
}
