#include <iostream>
using namespace std;


int main() {
    int k, sn, pn, sn2;
    FILE *f1 = fopen("a.in", "r");
    fscanf(f1, "%d %d", &k, &sn);
    fclose(f1);

    sn2 = sn % k;
    if (sn2 == 0) 
        sn2 = k;

    pn = sn / k + (sn % k != 0);

    // cout << pn << " " << sn2 << endl;
    FILE *f2 = fopen("a.out", "w");
    fprintf(f2, "%d %d", pn, sn2);
    fclose(f2);

    return 0;
}