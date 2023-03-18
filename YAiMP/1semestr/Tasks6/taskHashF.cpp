#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int N, M, hash = 0;
    // freopen("intput.txt", "r", stdin);
    // cin >> N >> M;
    FILE * fin = fopen("input.txt", "r");
    fscanf(fin, "%d %d", &N, &M);

    char c;
    c = getc(fin);
    c = getc(fin);
    c = getc(fin);
    // cout << c << endl;
    for (int i = 0; i < N; i++) {
        while (c != '\n' && c != EOF && c != (char)13){
            hash += int(c);
           
            // cout << "- - " << hash << " " << c << endl;
            c = getc(fin);
        }

        cout << hash % M << endl;
        hash = 0;
        c = getc(fin);
        c = getc(fin);
    }


    return 0;
}
