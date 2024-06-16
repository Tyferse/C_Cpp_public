#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct team {
    int number;
    int t[21] = {};
    long long total_time = 0;
    int solved[21] = {};
    int total_solved = 0;
};

bool operator>(team &a, team &b) {
    return a.total_solved > b.total_solved || 
          (a.total_solved == b.total_solved && a.total_time < b.total_time) || 
          (a.total_solved == b.total_solved && a.total_time == b.total_time && 
           a.number < b.number);
}

void merge(vector<team> & a, int l, int mean, int r) {
    int li = 0, ri = 0;
    vector<team> ma;
    // cout << l << " " << mean << " " << r << endl;
    /*((*a)[l + li].total_solved < (*a)[mean + ri].total_solved || 
            ((*a)[l + li].total_solved == (*a)[mean + ri].total_solved && 
             (*a)[l + li].total_time > (*a)[mean + ri].total_time) || 
            ((*a)[l + li].total_solved == (*a)[mean + ri].total_solved && 
             (*a)[l + li].total_time == (*a)[mean + ri].total_time && 
             (*a)[l + li].number > (*a)[mean + ri].number))*/
    while (li + l < mean && ri + mean < r) {
        team first = a[l + li], second = a[mean + ri];
        if (first > second) {
            ma.push_back(first);
            li++;
            // cout << "amr[" << mean + ri - 1 << "] = " << (*a)[mean + ri - 1] << "; ";
        }
        else {
            ma.push_back(second);
            ri++;
            // cout << "aml[" << l + li - 1 << "] = " << (*a)[l + li - 1] << "; ";
        }
    }

    while (li + l < mean) {
        ma.push_back(a[l + li]);
        li++;
        // cout << "al[" << l + li - 1 << "] = " << (*a)[l + li - 1] << "; ";
    }

    while (ri + mean < r) {
        ma.push_back(a[mean + ri]);
        ri++;
        // cout << "ar[" << mean + ri - 1 << "] = " << (*a)[mean + ri - 1] << "; ";
    }
    
    
    // cout << "ma(";
    for (int i = l; i < r; i++) {
        a[i] = ma[i - l];
        // cout << ma[i - l] << ", ";
    }
}

void merge_sort(vector<team> &a, int l, int r) {
    if (r - l > 1) {
        merge_sort(a, l, (l + r) / 2);
        merge_sort(a, (l + r) / 2, r);
        merge(a, l, (l + r) / 2, r);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int C, N;
    fin >> C >> N;

    vector<team> teams(C + 1);
    for (int i = 1; i <= C; i++) {
        teams[i].number = i;
    }

    int c, p, t, r;
    for (int i = 0; i < N; i++) {
        fin >> c >> p >> t >> r;
        if (r == 1 && !teams[c].solved[p]) {
            teams[c].solved[p] = r;
            teams[c].t[p] += t;
            teams[c].total_solved++;
        }
        else if (teams[c].solved[p]) {
            continue;
        }
        else {
            teams[c].t[p] += t + 20 * 60;
        }
    }

    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= 20; j++) {
            if (teams[i].solved[j]) {
                teams[i].total_time += teams[i].t[j];
            }
        }
    }

    merge_sort(teams, 1, C + 1);
    for (int i = 1; i <= C; i++) {
        // cout << teams[i].number << ") " << teams[i].total_solved << " " << teams[i].total_time << endl;
        fout << teams[i].number << " ";
    }

    fin.close();
    fout.close();
    
    return 0;
}
