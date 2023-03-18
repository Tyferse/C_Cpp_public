#include <iostream>
using namespace std;


int main() {
    int last_out = 0, stack[100] = {};
    char c = cin.get(), prev_char;  // Realize this case

    while (c != '\n') {
        if (48 <= c && c <= 57) {
            if (stack[last_out] == 0)
                stack[last_out] = int(c) - 48;
            else {
                stack[last_out] *= 10;
                stack[last_out] += int(c) - 48;
            }
        }
        else if (c == ' ') {
            last_out++;
        }
        else if (c == '+') {
            last_out -= 2;
            // cout << stack[last_out] << " " << stack[last_out + 1] <<  endl;
            stack[last_out] = stack[last_out] + stack[last_out + 1];
            stack[last_out + 1] = 0;
        }
        else if (c == '-') {
            last_out -= 2;
            // cout << stack[last_out] << " " << stack[last_out + 1] <<  endl;
            stack[last_out] = stack[last_out] - stack[last_out + 1];
            stack[last_out + 1] = 0;
        }
        else if (c == '*') {
            last_out -= 2;
            // cout << stack[last_out] << " " << stack[last_out + 1] <<  endl;
            stack[last_out] = stack[last_out] * stack[last_out + 1];
            stack[last_out + 1] = 0;
        }

        c = cin.get();
    }

    cout << stack[0];
    // for (int i = 99; i >= 0; i--)
    //     cout << stack[i] << endl;


    return 0;
}
