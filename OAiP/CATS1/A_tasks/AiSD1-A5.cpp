#include <iostream>
using namespace std;


int main() {
    int h, m, h2 = 0, m2 = 0;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d", &h, &m);
    fclose(f1);

    m2 = 60 - m;
    if (m2 == 60) 
        h2 = 1;
    
    h2 += 24 - h - 1;
    m2 = m2 % 60;

    // cout << h2 << " " << m2 << endl;
    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d %d", h2, m2);
    fclose(f2);

    return 0;
}