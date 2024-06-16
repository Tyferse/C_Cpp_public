#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> vertexdeg(n + 1, 0);
    queue<int> q;
    vector<int> result;

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        vertexdeg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (vertexdeg[i] == 0) {
            q.push(i);
            // cout << i << " ";
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for (int j = 0; j < graph[v].size(); j++) {
            vertexdeg[graph[v][j]]--;
            if (vertexdeg[graph[v][j]] == 0) {
                q.push(graph[v][j]);
                // cout << graph[v][j] << " ";
            }
        }
    }
    // cout << endl;

    if (result.size() != n) {
        // cout << -1;
        fout << -1;
    } 
    else {
        for (int v = 0; v < result.size(); v++) {
            // cout << result[v] << " ";
            fout << result[v] << " ";
        }
    }

    return 0;
}
