#include <iostream>
#include <vector>
using namespace std;


bool is_bipartite = true;

void dfs(vector<vector<bool>> graph, vector<int> &colored, int vertex, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && colored[i] == 0) {
            colored[i] = colored[vertex] == 1 ? 2 : 1;
            if (is_bipartite)
                dfs(graph, colored, i, n);
            else
                return;
        }
        else if (is_bipartite && graph[vertex][i] && colored[i] != 0 && colored[i] == colored[vertex]) {
            // cout << "colormap: ";
            // for (int j = 0; j < n; j++)
            //     cout << colored[j] << " ";
            
            cout << "NO";
            is_bipartite = false;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    bool tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    vector<int> colored(n);
    colored[0] = 1;
    dfs(graph, colored, 0, n);
    // for (int i = 0; i < n; i++)
    //     if (visited[i]) 
    //         k++;
        
    // cout << k;
    if (is_bipartite)
        cout << "YES";
    
    /*
    0 0 0 0 1 1 0 0
    0 0 0 0 1 0 1 0
    0 0 0 1 0 1 0 1
    0 0 1 0 0 0 0 0
    1 1 0 0 0 0 0 0
    1 0 1 0 0 0 0 0
    0 1 0 0 0 0 0 0
    0 0 1 0 0 0 0 0

    0 1 1 0 0
    1 0 0 1 0
    1 0 0 1 0
    0 1 1 0 1
    0 0 0 1 0

    0 1 0 0 1 1 0 0
    1 0 0 0 1 0 1 0
    0 0 0 1 0 1 0 1
    0 0 1 0 0 0 0 0
    1 1 0 0 0 0 1 0
    1 0 1 0 0 0 0 0
    0 1 0 0 1 0 0 0
    0 0 1 0 0 0 0 0
    */

    return 0;
}
