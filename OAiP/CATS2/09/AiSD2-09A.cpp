#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool is_tree = true;

void dfs(int n, vector<vector<bool>> graph, vector<bool> &visited, int vertex = 0, int prev = -1) {
    visited[vertex] = true;
    for (int i = 0; i < n; i++) {
        if (i == prev)
            continue;
        
        if (graph[vertex][i] && !visited[i]) {
            dfs(n, graph, visited, i, vertex);
        }
        else if (graph[vertex][i] && visited[i]) {
            is_tree = false;
            break;
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    if (n - m != 1) 
        is_tree = false;

    int li, ri;    
    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        fin >> li >> ri;
        adj_matrix[li - 1][ri - 1] = adj_matrix[ri - 1][li - 1] = true;   
    }

    vector<bool> v(n, false);
    dfs(n, adj_matrix, v);

    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            is_tree = false;
            break;
        }
    }

    if (is_tree)
        fout << "YES";
    else
        fout << "NO";

    fin.close();
    fout.close();

    return 0;
}
