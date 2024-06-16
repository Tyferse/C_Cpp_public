#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    char pancake, burned = 'B';
    fin >> pancake;
    int flips = 0;
    bool prev_is_white = (pancake != burned);

    if (!prev_is_white)
        flips = 1;

    for(int i = 1; i < n; i++) {
        fin >> pancake;
        // cout << pancake << " " << flips << endl;
        if (pancake == burned && prev_is_white) {
            flips += 2;
            prev_is_white = false;
        }
        else if (pancake != burned && !prev_is_white) {
            prev_is_white = true;
        }
    }

    fout << flips;

    fin.close();
    fout.close();

    return 0;
}
