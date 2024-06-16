#include <iostream>
#include <fstream>
using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");

void permutations(int num[], int index, int n) {
    if (num[0] == -1) {
        for (int i = 0; i < 2; i++) {
            num[index] = i;
            permutations(num, index + 1, n);
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            if (index < n - 1) {
                num[index] = i;
                permutations(num, index + 1, n);
            }
            else if (index == n - 1) {
                for (int j = 0; j < n - 1; j++) {
                    fout << num[j];
                }

                fout << i << endl;
            }
        }
    }
}

int main() {
    int n;
    fin >> n;
    int num[n] = {-1};
    if (n == 1)
        fout << 0 << endl << 1;
    else
        permutations(num, 0, n);
    
    fin.close();
    fout.close();
    return 0;
}
