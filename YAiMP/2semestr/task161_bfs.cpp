#include <iostream>
#include <queue>
using namespace std;


void reversed_bfs(int x1, int y1, int x2, int y2, vector<vector<int>> dist, vector<int> &ans) {
    int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    ans.push_back(x1);
    ans.push_back(y1);
    int k = dist[x1][y1] - 1;
    int xt = x1, yt = y1;
    while (k > 0) {
        for (int i = 0; i < 8; i++) {
            int xn = xt + dx[i], yn = yt + dy[i];
            if (0 <= xn && xn < dist.size() && 0 <= yn && yn < dist.size() && dist[xn][yn] == k) {
                ans.push_back(xn);
                ans.push_back(yn);
                xt = xn, yt = yn;
                k--;
                break;
            }
        }
    }
}

void bfs(int x1, int y1, int x2, int y2, int size) {
    queue<vector<int>> q;
    vector<vector<int>> dist(size, vector<int>(size, __INT_MAX__));
    int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    q.push({x1, y1});
    dist[x1][y1] = 0;
    while (!q.empty()) {
        int xq = q.front()[0], yq = q.front()[1];
        q.pop();
        for (int k = 0; k < 8; k++) {
            int u = xq + dx[k], v = yq + dy[k];
            if (0 <= u && u < size && 0 <= v && v < size && dist[u][v] > dist[xq][yq] + 1) {
                dist[u][v] = dist[xq][yq] + 1;
                q.push({u, v});  
            }
        }
    }

    cout << dist[x2][y2] << endl;

    vector<int> ans(dist[x2][y2] * 2);
    reversed_bfs(x2, y2, x1, y1, dist, ans);

    cout << x1 + 1 << " " << y1 + 1 << endl;
    for (int i = ans.size() - 1; i > 0; i -= 2) {
        cout << ans[i - 1] + 1 << " " << ans[i] + 1 << endl;
        if (ans[i - 1] == x2 && ans[i] == y2)
            break;
    }
}

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1, n);
    
    return 0;
}
