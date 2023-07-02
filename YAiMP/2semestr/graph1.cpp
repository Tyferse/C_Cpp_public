#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


void print1(vector<string> grf) {
    for (int i = 0; i < grf.size(); i++)
        cout << '(' << grf[i][0] << ", " << grf[i][1] << ")" << endl;
}

void print2(int grf[26][26], int max_i) {
    for (int i = 0; i <= max_i; i++) {
        for (int j = 0; j <= max_i; j++) {
            cout << setw(2) << grf[i][j] << " ";
        }

        cout << endl;
    }
}

// void print3(int line, int colomn, int (*grf)[]) {
//     int grf[line][colomn] = *grf;
//     for (int i = 0; i <= line; i++) {
//         for (int j = 0; j <= colomn; j++) {
//             cout << setw(2) << (*(*grf)[i])[j] << " ";
//         }

//         cout << endl;
//     }
// }

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<string> graph;
    string s;
    while (!fin.eof()) {
        fin >> s;

        graph.push_back(s);
    }   

    cout << "Список рёбер\n";
    print1(graph);

    int adj_matrix[26][26] = {{0}};
    int max_idx = 0;
    for (int i = 0; i < graph.size(); i++) {
        int idx1 = graph[i][0] - 'A', idx2 = graph[i][1] - 'A';
        max_idx = max_idx < idx1 ? idx1 : max_idx;
        max_idx = max_idx < idx2 ? idx2 : max_idx;
        // cout << idx1 << " " << idx2 << endl;
        adj_matrix[idx1][idx2] = 1;
        adj_matrix[idx2][idx1] = 1;
    }

    cout << endl << "Матрица смежности\n";
    print2(adj_matrix, max_idx);

    int inc_matrix[26][graph.size()];
    for (int i = 0; i <= max_idx; i++)
        for (int j = 0; j < graph.size(); j++) 
            inc_matrix[i][j] = 0;

    for (int i = 0; i < graph.size(); i++) {
        int idx1 = graph[i][0] - 'A', idx2 = graph[i][1] - 'A';
        // cout << idx1 << " " << idx2 << endl;
        inc_matrix[idx1][i] = 1;
        inc_matrix[idx2][i] = -1;
        // inc_matrix[idx2][idx1] = -1;
    }

    // print3(max_idx, graph.size(), inc_matrix);
    cout << endl << "Матрица инцидентности\n";
    for (int i = 0; i <= max_idx; i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << setw(2) << inc_matrix[i][j] << " ";
        }

        cout << endl;
    }

    // сhar adj_list[26][graph.size()];
    // for (int i = 0; i < graph.size(); i++) {
    //     int idx1 = graph[i][0] - 'A', idx2 = graph[i][1] - 'A';
    //     max_idx = max_idx < idx1 ? idx1 : max_idx;
    //     max_idx = max_idx < idx2 ? idx2 : max_idx;
    //     // cout << idx1 << " " << idx2 << endl;
    //     adj_list[idx1][idx2] = 1;
    //     adj_list[idx2][idx1] = 1;
    // }

    fin.close();
    fout.close();

    return 0;
}
