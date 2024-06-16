#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    ifstream fin("function.in");
    ofstream fout("function.out");
    // FILE * fin = fopen("function.in", "r");
    // FILE * fout = fopen("function.out", "w");
    
    int n;
    string f;

    fin >> n;
    fin >> f;
    // fscanf(fin, "%d", &n);
    // fscanf(fin, "%s", &f);
    
    // cout << n << " " << f;
    if ((f[3] == '1') || (f[1] == '1' && n % 2 == 1)) {
        for (int i = 0; i < n; i++) 
            fout << "1";
            // fprintf(fout, "1");
    }
    else if (f[1] == '1' && n % 2 == 0) {
        // fprintf(fout, "0");
        fout << "0";
        for (int i = 0; i < n - 1; i++) 
            fout << "1";
            // fprintf(fout, "1");
    }
    else if (f == "1010" || f == "1000") {
        for (int i = 0; i < n - 1; i++) 
            fout << "1";
            // fprintf(fout, "1");

        fout << "0";
        // fprintf(fout, "0");
    }
    else if (f == "0010") {
        fout << "1";
        // fprintf(fout, "1");
        for (int i = 0; i < n - 1; i++) 
            fout << "0";
            // fprintf(fout, "0");
    }
    else
        fout << "No solution";
        // fprintf(fout, "No solution");


    fin.close();
    fout.close();
    // fclose(fin);
    // fclose(fout);

    return 0;
}
