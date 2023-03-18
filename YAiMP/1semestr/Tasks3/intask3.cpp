#include <iostream>
using namespace std;


int main() {
    int n;
    float summ, ai;

    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);
    float aArray[n];
    
    for (int i = 0; i < n; i++) {
        fscanf(f, "%f", &ai);
        summ += ai;
        aArray[i] = ai;
    }

    for (int i = 0; i < n; i++) {
        cout << (summ - aArray[i]) / (n - 1) << endl;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << bArray[i] << endl;
    // }
}