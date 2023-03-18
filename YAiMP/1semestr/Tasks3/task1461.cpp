#include <iostream>
using namespace std;


int main () {
    int n;  // a1, a2, a3;
    cin >> n;

    if (n <= 2) {
        cout << 0;
    }
    else {
        int i1, i2, i3, k = 0, ibegin = 2, iend = n - 1;
        bool isnewchain = false;
        short array[n];
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int i = ibegin;
        while (i < n) {
            i1 = i - 2;
            i2 = i - 1;
            i3 = i;
                if (array[i1] >= 0 && array[i2] >= 0 && array[i3] == -1) {
                    i3 = iend;
                }
                if (array[i1] >= 0 && array[i2] == -1 && array[i3] == -1) {
                    if (iend + 1 < n) {
                        i2 = iend;
                        i3 = iend + 1;
                    }
                    else 
                        break;
                }
                if (array[i1] == -1 && array[i2] == -1 && array[i3] == -1) {
                    if (iend + 2 < n) {
                        i1 = iend;
                        i2 = iend + 1;
                        i3 = iend + 2;
                    }
                    else 
                        break;
                }
                if (array[i1] == -1 && array[i2] == -1 && array[i3] >= 0) {
                    if (i1 + 2 < n) {
                        i1 = i3;
                        i2 = i1 + 1;
                        i3 = i2 + 1;
                    }
                    else 
                        break;
                }
                if (array[i1] == -1 && array[i2] >= 0 && array[i3] >= 0) {
                    if (i3 + 1 < n) {
                        i1 = i2;
                        i2 = i3;
                        i3 = i2 + 1;
                    }
                    else 
                        break;
                }

            if (array[i1] != -1 && array[i1] == array[i2] && array[i2] == array[i3] && !isnewchain) {
                array[i1] = -1;
                isnewchain = true;
                ibegin = i1 >= 2 ? i1 : 2;
                k += 3;
                i++;
            }
            else if (array[i3] != -1 && array[i1] == array[i2] && array[i2] == array[i3] && isnewchain) {
                array[i1] = -1;
                k++;
                i++;
            }
            else if (isnewchain) {
                array[i1] = -1;
                array[i2] = -1;
                isnewchain = false;
                iend = i3;
                i = ibegin;
            }
            else 
                i++;
        }
        
        cout << k;
    }
    
    return 0;
}
