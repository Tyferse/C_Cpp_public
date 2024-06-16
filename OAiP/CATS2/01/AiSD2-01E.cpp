#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, L;
    fin >> N >> L;

    int ai, time[1001] = {};
    for (int i = 0; i < N; i++) {
        fin >> ai;
        time[ai]++;
        // cout << ai << endl;
    }

    int plane_time[N];
    int k = 0;
    for (int i = 0; i <= 1000; i++) {
        if (time[i] > 0) {
            for (int j = 0; j < time[i]; j++) {
                plane_time[k] = i; 
                k++;
            }
        }
    }

    /*
    for (int i = 1; i <= 1000; i++) {
        if (time[i] > 0) {
            if (total_time == 0) {
                total_time += i + L;
                time[i]--;
            }
            
            total_time += L * (time[i] - 1);
            if (i - iprev > L) {
                total_time += (i - iprev);
            }
            else 
                total_time += L;
            
            iprev = i;
        }
    }*/

    long long total_time = L + plane_time[0];
    for (int i = 0; i < N - 1; i++) {
        total_time += L;
        if (plane_time[i + 1] - plane_time[i] > L) {
            total_time += plane_time[i + 1] - plane_time[i] - L;
        }
    }

    // cout << total_time;
    fout << total_time;

    fin.close();
    fout.close();
    
    return 0;
}
