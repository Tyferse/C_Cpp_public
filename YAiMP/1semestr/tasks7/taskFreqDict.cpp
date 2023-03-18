#include <iostream>
#include <vector>
using namespace std;


int main() {
    int sz = 0, k = 0, nc = 0;
    char * symbols = (char *)malloc(sizeof(char));
    int * counts = (int *)malloc(sizeof(int));
    FILE * fin = fopen("input.txt", "r");

    char c = getc(fin);
    while (c != EOF) {
        if (sz < int(c)) {
            sz = int(c);
            symbols = (char *)realloc(symbols, sz);
            counts = (int *)realloc(counts, sz*4);
            counts[sz] = 0;
        }

        if (counts[int(c)] != 0) {
            nc++;
            
            counts[int(c)] = 0;
        }

        symbols[nc] = c;
        counts[int(c)]++;
        nc++;
        k++;
        c = getc(fin);
        // cout << c << endl;
    }

    char tmps;
    for (int i = 0; i < maxchar; i++) {
        for (int j = i + 1; j <= maxchar; j++) {
            //if (0 < counts[i] && counts[i] <= k && 0 < counts[j] && counts[j] <= k) {
                if (counts[i] < counts[j]) {
                    tmps = symbols[i];
                    symbols[i] = symbols[j];
                    symbols[j] = tmps;
                }
            //}
        }
    }

    for (int i = sz; i >= 0; i--) {
        if (0 < counts[i] && counts[i] <= k && isprint(symbols[i]))
            cout << symbols[i] << " | " << counts[(int)symbols[i]] << endl;
    }
    

    return 0;
}
