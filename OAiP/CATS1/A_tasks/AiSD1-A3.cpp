#include <iostream>
#include <cmath>
using namespace std;


int reverse(int a) {
    int ra = 0;
    int a_clone = a;
    int d;
    for (int i = log10(a); i >= 0; i--) {
        d = a_clone / (int)pow(10, i);
        ra += (d * (int)pow(10, (int)log10(a) - i));

        //cout << d << " " << rk << endl;

        a_clone -= d * (int)pow(10, i);
    }
    return ra;
}


int main() {
    int k, n = 0;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &k);
    fclose(f1);

    int ri;
    for (int i = 0; i < k; i++) {
        ri = reverse(i);
        if (ri + i == k) 
            n++;
            //cout << i <<  '!' << endl;
    }

    //cout << n << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d", n);
    fclose(f2);

    return 0;
}