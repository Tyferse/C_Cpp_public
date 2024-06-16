#include <fstream>
#include <string>
#include <deque>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream Out("output.txt");
    deque<char> S;
    deque<char> D;


    int n, i;
    string s, d;
    fin >> n;
    fin >> s;
    fin >> d;
    for (i = 0; i < s.length(); i++) {
        S.push_back(s[i]);
        if (i < n) {
        }
    }
    for (i = 0; i < d.length(); i++) {
        D.push_back(d[i]);

    }

    for (int i = 0; i < d.length(); i++) {
        if (D[i] >='a' && D[i] <='z' ) {
            S.insert(S.begin()+n, D[i]);
            n++;
        }
        if (D[i] == 'L') {
            n--;
        }
        if (D[i] == 'R') {
            n++;
        }
        if ((int)D[i] == 'X') {
            S.erase(S.begin()+n);
        }
    }
    
    for (int i = 0; i < S.size(); i++) {
        Out << S[i];
    }

}
