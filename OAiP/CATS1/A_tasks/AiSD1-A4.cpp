#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int a, b = 0, c = 0;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &a);
    fclose(f1);

    int length = int(log10(a)) + 1;
    // cout << length << endl;
    int digits[length];
    for (int i = 1; i <= length; i++) {
        digits[i - 1] = (a / (int)pow(10, length - i) - (a / (int)pow(10, length - i + 1)) * 10);
        // cout << (a / (int)pow(10, length - i)) << " - " << (a / (int)pow(10, length - i + 1)) * 10 << " = " << digits[i - 1] << endl;
    }
    
    int tmp = 0;
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j >= i + 1 ;j--) {
            if (digits[j] < digits[j - 1]) {
                tmp = digits[j];
                digits[j] = digits[j - 1];
                digits[j - 1] = tmp;
            }
        }
    }
    
    // for (int i = 0; i < length; i++) {
    //     cout << digits[i] << "\t";
    // }

    c = digits[0];
    for (int i = 1; i < length; i++) {
        b += digits[i] * int(pow(10, i - 1));
    }
    
    // cout << endl << b << " /\\ " << c << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d\n%d", b, c);
    fclose(f2);

    return 0;
}