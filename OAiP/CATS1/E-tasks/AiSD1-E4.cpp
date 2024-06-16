#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


int sort(vector<vector<int>> &v, int start, int end) {
    int m = start, k = (start + end) / 2;
    vector<int> p;
    
    if (end - start < 1) 
        return 0;
    
    int x = v[k][0];
    
    for (int i = start; i <= end; i++)
        if(v[i][0] < x) 
            m++;
    
    p = v[m];
    v[m] = v[k];
    v[k] = p;
    
    int s1 = start, s2 = m + 1;
    while (s1 < m && s2 <= end) {
        if (v[s1][0] >= x) {
            while (v[s2][0] >= x && s2 < end)
                s2++;
            
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
        }

        s1++;
    }
  
    sort(v, start, m - 1);
    sort(v, m + 1, end);
  
    return 0;
}


int main() {
    vector<vector<int>> settlements = {};
    vector<vector<int>> settlements1 = {};
    vector<vector<int>> shelters = {};
  
    int n, m, seti,sheli, j = 0;
    
    ifstream fin("shelter.in");
    ofstream fout("shelter.out");
    
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> seti;
        settlements.push_back({seti, i});
    }
    
    fin >> m;
    for (int i = 1; i <= m; i++){
        fin >> sheli;
        shelters.push_back({sheli, i});
    }
    
    settlements1 = settlements;
    
    sort(settlements, 0, n - 1);
    
    sort(shelters, 0, m - 1);
    
    for (int i = 0; i < n; i++) {
        while (j < m - 1 && abs(settlements[i][0] - shelters[j][0]) > abs(settlements[i][0] - shelters[j + 1][0])){
            j++;
        }

        settlements1[settlements[i][1]][1] = shelters[j][1];
        // fout << shelters[j][1] << " ";
    }
    
    
    for (int i = 0; i < n; i++) {
        fout << settlements1[i][1] << " ";
    }
}
