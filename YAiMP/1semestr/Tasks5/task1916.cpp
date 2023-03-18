#include <iostream>
#include <string>
using namespace std;


int main() {
    int state = 1, category = 0;
    int N[8][5] = {{2,  3, -1, -1, -1}, 
                   {2, -1,  4,  5, 11}, 
                   {2, -1, -1, -1, -1}, 
                   {6, -1, -1, -1, -1}, 
                   {8,  7, -1, -1, -1}, 
                   {6, -1, -1,  5, 11}, 
                   {8, -1, -1, -1, -1}, 
                   {8, -1, -1, -1, 11}}; 
    char c = cin.get();

    while (1) {
        if (48 <= c && c <= 57)
            category = 0;
        else if (c == '+' || c == '-')
            category = 1;
        else if (c == '.')
            category = 2;
        else if (c == 'E' || c == 'e')
            category = 3;
        else if (c == '\n') {
            category = 4;
        }
        else {
            cout << "NO";
            break;
        }
            
        state = N[state - 1][category];
        if (state == -1) {
            cout << "NO";
            break;
        }
        else if (state == 11) {
            cout << "YES";
            break;
        }

        c = cin.get();
    }


    return 0;
}
