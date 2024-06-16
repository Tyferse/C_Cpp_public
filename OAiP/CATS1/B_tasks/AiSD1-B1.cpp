// #include <fstream>
#include <iostream>
using namespace std;


int main() {
    char n[5], settings[5];
    FILE *f1 = fopen("input.txt", "r");
    for (int i = 0; i < 5; i++) {
        fscanf(f1, "%c", &n[i]);
    }
    fclose(f1);

    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (n[i] == '=') {
            if (i > 0 and settings[i - 1] == '?') {
                settings[i] = '?';
                continue;
            }

            if (n[j] == '=') {
                settings[i] = '*';
            }
            else if (n[j] == '>') {
                settings[i] = '-';
            }
            else if (n[j] == '<') {
                settings[i] = '+';
            }
        }
        else if (n[i] == '>') {
            if (n[j] == '<') {
                settings[i] = '?';
                continue;
            }

            settings[i] = '-';
            j = i;
        }
        else if (n[i] == '<') {
            if (n[j] == '>') {
                settings[i] = '?';
                continue;
            }

            settings[i] = '+';
            j = i;
        }
        else 
            settings[i] = '?';
    }

    // cout << settings << endl;
    FILE *f2 = fopen("output.txt", "w");
    for (int i = 0; i < 5; i++) {
        fprintf(f1, "%c", settings[i]);
    }
    fclose(f2);

    return 0;
}
