#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int N; // Количество досок 
    int dEven = 0; // Отличие чётной последовательности от изначальной
    int dUneven = 0; // Отличие нечётной последовательности от изначальной
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> N;
    // cout << N << endl;
    int plank;
    int planks_arr1[N]; // Нечётные

    for (int i = 0; i < N; i++) {
        fin >> plank;
        planks_arr1[i] = plank;
    }


    int planks_arr2[N]; 
    copy(planks_arr1, planks_arr1 + N, planks_arr2); // Чётные

    if (N > 1) {
        if (N == 2) {
            int plank1 = planks_arr1[0], plank2 = planks_arr1[1];
            if (plank1 == plank2)
                plank1++;
            
            fout << plank1 << " " << plank2;
            cout << plank1 << " " << plank2;
        }
        else {
            int plank3, plank11, plank12, plank21, plank22;
            int d;
            for (int i = 2; i < N; i++) {
                plank3 = planks_arr1[i];

                plank11 = planks_arr1[i - 2], plank12 = planks_arr1[i - 1],
                plank21 = planks_arr2[i - 2], plank22 = planks_arr2[i - 1];
                if ((i + 1) % 2 != 0) { // Если index 3-го элемента нечётный (1, 2, 3)
                    if (plank11 <= plank12) {
                        d = 1 + plank12 - plank11;
                        planks_arr1[i - 2] += d;
                        dUneven += d;
                    }

                    if (plank3 <= plank12) {
                        d = 1 + plank12 - plank3;
                        planks_arr1[i] += d;
                        dUneven += d;
                    }

                    if (plank22 <= max(plank21, plank3)) {
                        d = 1 + max(plank21, plank3) - plank22;
                        planks_arr2[i - 1] += d;
                        dEven += d;
                    }
                }
                else { // Если index 3-го элемента чётный (0, 1, 2)
                    if (plank12 <= max(plank11, plank3)) {
                        d = 1 + max(plank11, plank3) - plank12;
                        planks_arr1[i - 1] += d;
                        dUneven += d;
                    }

                    if (plank21 <= plank22) {
                        d = 1 + plank22 - plank21;
                        planks_arr2[i - 2] += d;
                        dEven += d;
                    }
                    if (plank3 <= plank22) {
                        d = 1 + plank22 - plank3;
                        planks_arr2[i] += d;
                        dEven += d;
                    }
                }
            }
            if (dUneven < dEven) {
                for (int i = 0; i < N; i++) {
                    fout << planks_arr1[i] << " ";
                    cout << planks_arr1[i] << " ";
                }
            }
            else {
                for (int i = 0; i < N; i++) {
                    fout << planks_arr2[i] << " ";
                    cout << planks_arr2[i] << " ";
                }
            }
        }
    }
    else
        fout << planks_arr1[0];
    

    return 0;
}
