#include <fstream> 
#include <iostream> 
#include <queue>
using namespace std; 

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;

    fin >> n >> m;
    
    long long sm = 0;
    priority_queue<int, vector<int>, less<>> thirst;
    int ai;
    for (int i = 0; i < n; i++) {
        fin >> ai;
        sm += ai;
        thirst.push(ai);
    }

    for (int i = 0; i < m && sm > 0; i++) {
        int maxel = thirst.top();
        int decreased = maxel / 10;
        sm -= maxel - decreased;
        thirst.pop();
        thirst.push(decreased);
    }

    fout << sm;

    return 0;
}
