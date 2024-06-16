#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");



    fin.close();
    fout.close();
    
    return 0;
}
