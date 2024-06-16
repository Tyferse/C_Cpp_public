#include <cmath>
#include <iostream>
using namespace std;


int main() {
    unsigned int x, k;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d", &x, &k);
    fclose(f1);

    unsigned int ans = ((x & (1 << k)) >> k) & 1;
    if (k > 32) 
        ans = 0;

    // cout << ans << " " << k << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d", ans);
    fclose(f2);

    return 0;
}
