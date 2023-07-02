#include <iostream>
#include <vector>
using namespace std;


vector<vector<bool>> multimatrix(vector<vector<bool>> a, vector<vector<bool>> b, int n) {
    vector<vector<bool>> c(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] = c[i][j] | (a[i][k] & b[k][j]);
            }
        }
    }

    return c;
}

int main() {
    int n;
    cin >> n;

    // bool adj_matrix[n][n];
    bool connected;
    // int curr = 0;
    if (n > 1) {
        vector<vector<bool>> vertexes(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> connected;
                vertexes[i][j] = connected;
                // vertexes[i][j] = (int)connected;
                // if (connected) {
                //     if (!vertexes[i] and i == curr) {
                //         vertexes[i] = true;
                //         curr++;
                //     }
                //     // if (!vertexes[j] and j == curr) {
                //     //     vertexes[j] = true;
                //     //     curr++;
                //     // }
                // }
            }
        }

        // bool c = new **bool;
        vector<vector<bool>> c = multimatrix(vertexes, vertexes, n);
        for (int i = 0; i < n; i++) {
            cout << endl;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    cout << c[j][k] << " ";
                }

                cout << endl;
            }

            c = multimatrix(c, vertexes, n);
        }

        vector<bool> is_approx(n);
        for (int i = 1; i < n; i++) {
            // for (int j = 0; j < n; j++) {
                if (vertexes[0][i]) {
                    is_approx[i - 1] = true;
                    // is_approx[j] = true;
                }
                else {
                    is_approx[i - 1] = false;
                    break;
                    // is_approx[j] = false;
                }
            // }
        }

        for (int i = 0; i < n; i++) {
            if (!is_approx[i]) {
                connected = false;
                break;
            }
        }
    }
    else
        cin >> connected;
    
    if (connected)
        cout << "YES";
    else
        cout << "NO";

    
    return 0;
}
