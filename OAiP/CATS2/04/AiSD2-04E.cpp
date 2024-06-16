#include <iostream>
#include <fstream>
using namespace std;


float min_sum = 120 * 4;
int min_permut[4] = {1, 2, 3, 4};

void permutations(int num[], float (*time)[4], int n=4, int h=0) {
    if (h == n) {
        float curr_sum = 0;
        for (int i = 0; i < n; i++)
            curr_sum += time[i][num[i] - 1];

        if (curr_sum < min_sum) {
            min_sum = curr_sum;
            // cout << curr_sum << endl;
            for (int i = 0; i < 4; i++) {
                min_permut[i] = num[i];
                // cout << num[i] << " ";
            }

            // cout << endl;
        }
    }
    else {
        for (int i=h; i < n; i++) {
            swap(num[h], num[i]);
            permutations(num, time, n, h + 1);
            // cout << i << " " << curr_sum << endl;
            swap(num[h], num[i]);
        }
    }

    return;
}

int main() {
    /*
    Считаем сумму
    индекс строки - индекс числа в перестановке
    индекс столбца - само число в перестановке
    */
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    float time_matrix[4][4];
    for (int i = 0; i < 4; i++) {
        fin >> time_matrix[i][0] >> time_matrix[i][1] >> time_matrix[i][2] >> time_matrix[i][3];
    }

    int num[4] = {1, 2, 3, 4};
    // bool used[5] = {0 , false, false, false, false};
    
    permutations(num, time_matrix);
    
    for (int i = 0; i < 4; i++) {
        fout << min_permut[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}
