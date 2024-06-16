#include <iostream>
#include <fstream>
using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");

void permutations(int num[], int index, int n) { 
    if (num[0] == 0) {
        for (int i = 1; i <= n; i++) {
            num[index] = i;
            permutations(num, index + 1, n);
        }
    }
    else {
        bool unique = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < index; j++) {
                if (num[j] == i) {
                    unique = false;
                    break;   
                }
            }

            if (unique) {
                if (index < n - 1) {
                    num[index] = i;
                    permutations(num, index + 1, n);
                }
                else if (index == n - 1) {
                    for (int j = 0; j < n - 1; j++) {
                        fout << num[j] << " ";
                    }

                    fout << i << endl;
                }
            }
            else if (i < n)
                unique = true;
        }
    }
}


int main() {
    int n;
    fin >> n;
    int num[n] = {0};
    if (n == 1)
        fout << 1;
    else
        permutations(num, 0, n);
    
    fin.close();
    fout.close();
    return 0;
}
