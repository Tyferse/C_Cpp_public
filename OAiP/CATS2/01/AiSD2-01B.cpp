#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void merge(vector<float> * a, int l, int mean, int r, long long * swaps) {
    int li = 0, ri = 0;
    vector<float> ma;
    // cout << l << " " << mean << " " << r << endl;
    while (li + l < mean && ri + mean < r) {
        if ((*a)[l + li] < (*a)[mean + ri]) {
            ma.push_back((*a)[mean + ri]);
            ri++;
            // cout << "amr[" << mean + ri - 1 << "] = " << (*a)[mean + ri - 1] << "; ";
        }
        else {
            ma.push_back((*a)[l + li]);
            li++;
            *swaps += ri;
            // cout << "aml[" << l + li - 1 << "] = " << (*a)[l + li - 1] << "; ";
        }
    }

    while (li + l < mean) {
        ma.push_back((*a)[l + li]);
        li++;
        *swaps += ri;
        // cout << "al[" << l + li - 1 << "] = " << (*a)[l + li - 1] << "; ";
    }

    while (ri + mean < r) {
        ma.push_back((*a)[mean + ri]);
        ri++;
        // cout << "ar[" << mean + ri - 1 << "] = " << (*a)[mean + ri - 1] << "; ";
    }
    
    
    // cout << "ma(";
    for (int i = l; i < r; i++) {
        (*a)[i] = ma[i - l];
        // cout << ma[i - l] << ", ";
    }

    // cout << ") _ " << *swaps << endl;
}

void merge_sort(vector<float> *a, int l, int r, long long *swaps) {
    if (r - l > 1) {
        merge_sort(a, l, (l + r) / 2, swaps);
        merge_sort(a, (l + r) / 2, r, swaps);
        merge(a, l, (l + r) / 2, r, swaps);
    }
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    float s;
    string name;
    vector<float> solders;
    for (int i = 0; i < n; i++) {
        fin >> s >> name;
        solders.push_back(s);
        // cout << s << endl;
    } 

    long long swaps = 0;
    merge_sort(&solders, 0, n, &swaps);

    fout << swaps;

    fin.close();
    fout.close();
    
    return 0;
}
