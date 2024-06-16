#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector<int> arr;

class compmin {
public:
    bool operator() (int ai, int bi) {    
        return arr[ai] > arr[bi] || (arr[ai] == arr[bi] && ai > bi);    
    }

};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    arr.resize(n + m);
    priority_queue<int, vector<int>, compmin> indexes;

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        indexes.push(i);
    }

    int ai, bi, deleted = 10001;
    for (int i = 0; i < m; i++) {
        ai = indexes.top();
        indexes.pop();
        bi = indexes.top();
        indexes.pop();

        arr[n + i] = arr[ai] + arr[bi];
        indexes.push(n + i);
        arr[ai] = deleted;
        arr[bi] = deleted;
    }

    // sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != deleted) {
            // cout << arr[i] << " ";
            fout << arr[i] << " ";
        }
    }
 
    fin.close();
    fout.close();
    
    return 0;
}
