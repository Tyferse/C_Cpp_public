#include <iostream>
#include <vector>
using namespace std;


void dfs(int n, vector<vector<bool>> graph, vector<bool> &visited, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(n, graph, visited, i);
        }
    }
}

int main() {
    int n, s, k = 0;
    cin >> n >> s;

    vector<vector<bool>> graph(n, vector<bool>(n, 0));
    bool tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    vector<bool> visited(n);
    dfs(n, graph, visited, s - 1);
    for (int i = 0; i < n; i++)
        if (visited[i]) 
            k++;
        
    cout << k;
    
    return 0;
}
