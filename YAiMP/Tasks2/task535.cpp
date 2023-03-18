#include <iostream>
using namespace std;


int months[12] = {31, 29, 31, 30, 31, 30, 
                  31, 31, 30, 31, 30, 31};

// int move(int d, int m, int p) {
//     static int steps[4][2] = {{d + 1, m}, {d, m + 1}, {d + 2, m}, {d, m + 2}};
//     return {steps, p + 1};
// }


// int game(int d, int m, int player) {
//     int *steps = move(d, m);
//     count = 0;
//     for (int i = 0; i < 4; i++) {
//         if (steps[i][0] == 31 and steps[i][1] == 12) {

//         }

//     }
// }


int main (){
    int d, m, p = 1, count = 0;
    cin >> d >> m;

    for (int i = 0; i < 12 - m; i++) {
        if (m < 11)
            m += 2;
            if (d == 31 and months[m - 1] == 30) {

                
            }
                
        else if (m == 11) 
            m += 1;
        else if (m == 12) 
            break;
                
        count++;
    }
    
    return 0;
}
