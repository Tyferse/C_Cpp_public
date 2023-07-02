#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    int path_length, a, b;
    if (n > 1) {
        vector<vector<int>> path_map(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> path_length;
                if (path_length == 0)
                    path_map[i][j] = (__INT_MAX__ >> 1);
                else
                    path_map[i][j] = path_length;
            }
        }

        cin >> a >> b;
        a -= 1;
        b -= 1;

        if (a == b) {
            cout << 0 << endl << a << " " << b;
        }
        else {
            bool active[n] = {false};
            int min_rout, routs[n] = {0}, ranges[n] = {0};
            for (int i = 0; i < n; i++) {
                active[i] = true;
                ranges[i] = path_map[a][i]; 
                routs[i] = a;
            }

            active[a] = false;
            routs[a] = -1;

            for (int i = 0; i < n - 1; i++) {
                int min_dist = path_map[a][b];
                for (int j = 0; j < n; j++) {
                    if (active[j] && ranges[j] <= min_dist) {
                        min_dist = ranges[j];
                        min_rout = j;
                    }
                }

                active[min_rout] = false;
                for (int j = 0; j < n; j++) {
                    if (active[j] && ranges[min_rout] + path_map[min_rout][j] < ranges[j]) {
                        ranges[j] = ranges[min_rout] + path_map[min_rout][j];
                        routs[j] = min_rout;                        
                    }
                }

                // for (int i = 0; i < n; i++) 
                //     cout << a + 1 << " > " << i + 1 << " = " << ranges[i] << endl;

                // cout << endl << "-- ";
            }

            int s = 0, idx = b;
            vector<int> ans;
            while (idx != -1) {
                if (routs[idx] != -1)
                    s += path_map[idx][routs[idx]];
                // cout << ":" << ranges[idx] << endl;

                // cout << idx + 1 << " ";
                ans.push_back(idx + 1);
                idx = routs[idx];
            }

            if (s < (__INT_MAX__ >> 1)) {
                cout << s << endl;
                for (int i = ans.size() - 1; i >= 0; i--) {
                    cout << ans[i] << " ";
                }                
            }
            else
                cout << 0;
        }
    }
    else {
        cin >> path_length >> a >> b;
        cout << 0 << endl << a << " " << b;
    }
    
    return 0;
}
