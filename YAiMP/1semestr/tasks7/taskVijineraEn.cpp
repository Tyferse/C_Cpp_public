#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fin("inputvij.txt");
    ofstream fout("output.txt");
    
    // Построение алфавита
    unsigned char alph[34] = {};
    for (int i = 192; i <= 192 + 32; i++) {
        if (i % 192 == 6) {
            alph[i % 192] = 168;
            // cout << (int)alph[i % 192] << " ";
        }
        else if (i % 192 > 6) {
            alph[i % 192] = i - 1;
            // cout << (int)alph[i % 192 - 1] << " ";
        }
        else {
            alph[i % 192] = i;
            // cout << (int)alph[i% 192] << " ";
        }
    }
    
    alph[33] = (unsigned char)32;

    /*
    for (int i = 0; i < 34; i++) {
        fout << alph[i];
        fout << i << " ";
        cout << (int)alph[i] << " ";
    }

    fout << endl;
    cout << endl;
    */

    // cout << (int)alph[33] << endl;

    // Ввод ключа
    vector <unsigned char> key;

    int ck = 0;
    unsigned char c = fin.get();
    if ((int)c != 208)
        key.push_back(c);

    // cout << (int)c << "* ";
    while (c != (unsigned char)'\n') {
        c = fin.get();
        if (int(c) != 208) {
            key.push_back(c);
            ck++;
        }

        // cout << (int)c << " ";
    }

    // cout << endl;
    ck -= 2;

    // Первести в CP1251
    // Учесть пробел и Ё
    // Присвоить смещения от 0 до 33 в массив moveto
    int moveto[ck] = {};
    for (int i = 0; i < ck; i++) {
        if ((key.at(i) + 48) % 192 < 6)
            moveto[i] = (key.at(i) + 48) % 192;
        else if (key.at(i) == 129) {
            moveto[i] = 6;
        }
        else if (key.at(i) == 32) {
            moveto[i] = 33;
        }
        // else if (key.at(i))
        else if ((key.at(i) + 48) % 192 >= 6) {
            cout << (int)key.at(i);
            moveto[i] = (key.at(i) + 48) % 192;
            cout << "!";
        }
        
        cout << moveto[i] << " / ";
    }

    
    for (int i = 0; i < ck; i++) {
        cout << moveto[i] << " ";
    }
    

    // cout << endl;
    key.clear();

    // Шифрорвание
    // int p = 1;
    short ci, s = 0;
    c = fin.get();
    while (!fin.eof()) {
        if ((int)c == 208) {
            c = fin.get();
            continue;
        }

        if ((c + 48) % 192 < 6) {
            ci = ((c + 48) % 192 + moveto[s]) % 34;
        }
        else if ((int)c == 129) {
            ci = (6 + moveto[s]) % 34;
        }
        else if ((int)c == 32) {
            ci = (33 + moveto[s]) % 34;
        }
        else {
            ci = ((c + 48 + 1) % 192 + moveto[s]) % 34;
            // cout << (int)c << " ";
        }

        
        fout << alph[ci];
        // cout << " " << p << "-" << (int)c << "|";
        // cout << (c + 48 + 1) % 192 << " " << ci << " ";
        
        s++;
        if (s == ck) {
            s = 0;
            // cout << endl;
        }

        // p++;
        c = fin.get();
    }

    return 0;
}
