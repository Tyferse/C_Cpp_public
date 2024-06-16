#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int w, h, a;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d %d", &w, &h, &a);
    fclose(f1);

    FILE *f2 = fopen("output.txt", "w");

    int ans = (int)ceil((float)h * w / (a * a));
    // int d = w * h - a*a;
    // int dw = w - a, dh = h - a;
    // int s = 0;
    // if ((dw <= 0 && dh <= 0) || d <= 0)
    //     fprintf(f2, "1");
    // else if (dw <= 0 || dw <= 0) {
    //     dw = ~(dw) + 1;
    //     dh = ~(dh) + 1;
    //     ans = (int)ceil(w * h / (a * a));
    // }
    // else {

    // }

    // cout << ans;
    fprintf(f2, "%d", ans);

    fclose(f2);

    return 0;
}
