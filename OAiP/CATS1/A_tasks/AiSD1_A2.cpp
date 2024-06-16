#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int a1, b1, ans = 0;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &a1);
    fclose(f1);

    if (a1 > 100) {
        b1 = a1 % 100;
        ans = abs(a1) / 100;
        ans += b1 % 50 == 0 ? 1 : 2;
    }
    else if (a1 >= 0) {
        b1 = abs(100 - a1);
        ans = b1 == 50 ? 1 : 2;
    } 
    else {
        if (a1 < -100) {
            ans = abs(a1 / 100) + 2;
            ans += abs(a1) % 50 == 0 ? 1 : 2;
        }
        else
            ans = 4;
    }

    cout << ans << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d", ans);
    fclose(f2);


    return 0;
}
