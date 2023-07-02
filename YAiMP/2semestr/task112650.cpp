#include <iostream>
#include <vector>
using namespace std;


struct connection {
    int first;
    int second;
};

int main() {
    int n;
    cin >> n;

    int adj_matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> adj_matrix[i][j];
    }
    
    bool used[n] = {true};
    int k = 1, new_vert = 0, minr = (1 << 31) - 1;
    vector<connection> ostav;
    connection mincon;
    while (k < n) {
        for (int i = 0; i < n; i++) {
            if (!used[i])
                continue;
            
            for (int j = 0; j < n; j++) {
                if (adj_matrix[i][j] != 0 and adj_matrix[i][j] < minr and !used[j]) {
                    minr = adj_matrix[i][j];
                    mincon.first = i < j ? i + 1 : j + 1;
                    mincon.second = i > j ? i + 1 : j + 1;
                    new_vert = j;
                }
            }
        }

        used[new_vert] = true;
        ostav.push_back(mincon);
        k++;
        minr = (1 << 31) - 1;
    }

    for (int i = 0; i < ostav.size(); i++) {
        for (int j = 0; j < ostav.size() - i - 1; j++) {
            if (ostav[j].first > ostav[j + 1].first or 
                (ostav[j].first == ostav[j + 1].first and ostav[j].second > ostav[j + 1].second)) {
                    swap(ostav[j], ostav[j + 1]);
                }
        }
    }

    for (int i = 0; i < ostav.size(); i++) {
        cout << ostav[i].first << " " << ostav[i].second << endl;
    }
    
    
    return 0;
}
