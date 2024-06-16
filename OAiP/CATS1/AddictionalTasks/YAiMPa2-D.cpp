#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int L = 0, sl = 0;
    int * spaces = (int *)malloc(sizeof(int));
    char * text = (char *)malloc(sizeof(char));
    char c = cin.get();
    while (c != '\n') {
        if (c == ' ') {
            spaces[sl] = L;
            sl++;
            spaces = (int *)realloc(spaces, sizeof(int) * (sl + 1));
        }

        text[L] = c;
        text = (char *)realloc(text, sizeof(char) * (L + 1));

        c = cin.get();
        L++;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << text[i] << " ";
    }

    int bgn, nd;
    if (n == 1) {
        bgn = 0;
        nd = spaces[0];
    }
    else if (n > sl) {
        bgn = spaces[sl - 1] + 1;
        nd = L;
    }
    else {
        bgn = spaces[n - 2] + 1;
        nd = spaces[n - 1];
    }

    for (int i = bgn; i < nd; i++) {
        cout << text[i];
    }


    return 0;
}
