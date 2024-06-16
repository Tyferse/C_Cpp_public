#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s;
    fin >> s;

    char prev = s[0];
    bool t = true;
    for (int i = 1; i < s.length(); i++) {
        if (islower(s[i]) and isupper(prev)) {
            t = false;
            break;
        } 

        prev = s[i];
    }

    if (t)
        fout << "YES";
    else
        fout << "NO";

    fin.close();
    fout.close();
    
    return 0;
}
