#include <iostream>
// #include <fstream>
#include <vector>
using namespace std;


int k;

bool is_solution(int lzero[], int czero[]) {
    for (int i = 0; i < k; i++) {
        if (lzero[i] == 0 || czero[i] == 0) {
            return false;
        }
    }

    return true;
}

int find_min_sum(vector<vector<int>> m, vector<vector<int>> mtrx, vector<bool> & used, int step=0) {
    if (step == k)
        return 0;

    int curr_sum, min_sum = __INT_MAX__ >> 1;
    // bool has_ans = false;
    // vector<bool> used(k, false);
    for (int j = 0; j < k; j++) {
        if (m[step][j] == 0 && !used[j]) {
            used[j] = true;
            curr_sum = mtrx[step][j] + find_min_sum(m, mtrx, used, step + 1);
            // has_ans = true;
            // cout << mtrx[i][j] << " ";
            // cout << "cs " << curr_sum << endl;
            if (curr_sum < min_sum)
                min_sum = curr_sum;

            used[j] = false;
        }
    }

    // cout << endl;

    // cout << "ms " << min_sum << endl;

    return curr_sum;
}

int main() {
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

    cin >> k;

    vector<vector<int>> matrix(k, vector<int>(k, 0)), mtrx(k, vector<int>(k, 0));
    int minl[k] = {__INT_MAX__}, minc[k] = {__INT_MAX__};
    for (int i = 0; i < k; i++) {
        minl[i] = __INT_MAX__;
        for (int j = 0; j < k; j++) {
            cin >> matrix[i][j];
            mtrx[i][j] = matrix[i][j];
            minl[i] = matrix[i][j] < minl[i] ? matrix[i][j] : minl[i];
            minc[j] = __INT_MAX__;
        }
    }

    int lzeros[k] = {0}, czeros[k] = {0};
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            matrix[i][j] -= minl[i];
            if (matrix[i][j] == 0) {
                lzeros[i]++;
                czeros[j]++;
            }

            minc[j] = matrix[i][j] < minc[j] ? matrix[i][j] : minc[j];
        }
    }

    // cout << "-----" << endl;
    // for (int i = 0; i < k; i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << matrix[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    if (is_solution(lzeros, czeros)) {
        vector<bool> used(k, false);
        int ans = find_min_sum(matrix, mtrx, used);
        // cout << ans << endl;
        cout << ans;
    }
    else {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                matrix[i][j] -= minc[j];
                if (matrix[i][j] == 0 && minc[j] != 0) {
                    lzeros[i]++;
                    czeros[j]++;
                }
            }
        }

        bool lcrossed[k] = {false}, ccrossed[k] = {false};
        for (int i = 0; i < k; i++) {
            if (lzeros[i] > 1) {
                lcrossed[i] = true;
            }

            // czeros[i] = 0;
        }

        for (int i = 0; i < k; i++) {
            if (!lcrossed[i]) {
                for (int j = 0; j < k; j++) {
                    if (matrix[i][j] == 0) {
                        ccrossed[j] = true;
                    }
                }
            }
        }

        // cout << "-----" << endl;
        // for (int i = 0; i < k; i++) {
        //     for (int j = 0; j < k; j++) {
        //         cout << matrix[i][j] << " ";
        //     }

        //     cout << endl;
        // }

        if (is_solution(lzeros, czeros)) {
            vector<bool> used(k, false);
            int ans = find_min_sum(matrix, mtrx, used);
            // cout << " = " << ans << endl;
            cout << ans;
        }
        else {
            int sup_min = __INT_MAX__;
            for (int i = 0; i < k; i++) {
                if (!lcrossed[i]) {
                    for (int j = 0; j < k; j++) {
                        if (!ccrossed[j]) {
                            sup_min = matrix[i][j] < sup_min ? matrix[i][j] : sup_min;
                        }
                    }
                }
            }

            for (int i = 0; i < k; i++) {
                if (!lcrossed[i]) {
                    for (int j = 0; j < k; j++) {
                        if (!ccrossed[j]) {
                            matrix[i][j] -= sup_min;
                        }
                    }
                }
            }

            // vector<bool> used(k, false);

            // cout << "-----" << endl;
            // for (int i = 0; i < k; i++) {
            //     for (int j = 0; j < k; j++) {
            //         cout << matrix[i][j] << " ";
            //     }

            //     cout << endl;
            // }

            vector<bool> used(k, false);
            int ans = find_min_sum(matrix, mtrx, used);
            // cout << " : " << ans << endl;
            cout << ans;
        }
    }

    // fin.close();
    // fout.close();

    return 0;
}
