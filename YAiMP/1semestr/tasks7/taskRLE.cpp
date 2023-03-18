/*
#include <iostream>
#include <vector>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    vector<char> chars;
    vector<int> amount;
    int m = 0, l = 0;
    char prev;
    char cur = getchar();
    chars.push_back(cur);
    amount.push_back(1);

    while (cur != EOF) {
        prev = cur;
        cur = getchar();
        cout << prev << " " << cur << endl;
        if ((cur == prev && amount.at(l) <= 127) || l == 0) {
            amount.at(l)++;
            cout << chars.at(m) << " | " << amount.at(l) << endl;
        }
        // else if (cur == prev && l != 0) {
            
        // }
        else if (cur == prev && amount.at(l) > 127) {
            amount.at(l)--;
            m++;
            l++;
            chars.push_back(cur);
            amount.push_back(1);
            cout << chars.at(m) << " | " << amount.at(l) << endl;
        }

        if (cur != prev) {
            if (amount.at(l) == 1 && l == 0) {
                amount.at(l) = 129;
            }
            else if ((amount.at(l) < 128 || amount.at(l) == 255) && l != 0) {
                l++;
                amount.push_back(129);
            }
            else {
                amount.at(l)++;
            }

            m++;
            chars.push_back(cur);
            cout << chars.at(m - 1) << " | " << amount.at(l) << endl;
        }
    }
    
    // int m1 = 0;
    // for (int i = 0; i < l + 1; i++) {
    //     cout << amount.at(i) - 128;
    //     if (amount.at(i) < 128) {
    //         cout << " " << chars.at(m1) << endl;
    //         m1++;
    //     }
    //     else {
    //         cout << endl << " | ";
    //         for (int j = 0; j < amount.at(i) - 128; j++) {
    //             cout << chars.at(m1);
    //             m1++;
    //         }
    //     }
    // }

    // freopen("output.txt", "wb", stdout);
    FILE * fo = fopen("output.txt", "w");
    vector<char> tmpc;
    int tmpa = 128;

    // for (int i = 0; i <= j; j++) {
    //     if (i < j && tmpa == 0 && amount.at(i) == 1 && amount.at(i + 1) == 1) {
    //         tmpa += 2;
    //         tmpc.push_back(chars.at(i));
    //         tmpc.push_back(chars.at(i + 1));
    //     }
    //     else if (i < j && tmpa < 255 && amount.at(i) == 1 && amount.at(i + 1) == 1) {
    //         tmpa++;
    //         tmpc.push_back(chars.at(i + 1));
    //     }

    //     if (i < j && 128 < tmpa && tmpa < 256 || (amount.at(i) != 1 || amount.at(i + 1) != 1)) {
    //         cout << tmpa;
    //         fprintf(fo, "%d", tmpa);
    //         for (int k = 128; k <= tmpa; k++) {
    //             cout << tmpc.at(k - 128);
    //             fprintf(fo, "%c", tmpc.at(k - 128));
    //         }

    //         tmpa = 128;
    //         tmpc.clear();
    //     }

    //     if (tmpa == 128 && i < j) {
    //         cout << amount.at(i + 1);
    //         cout << chars.at(i + 1);
    //         fprintf(fo, "%d", amount.at(i + 1));
    //         fprintf(fo, "%c", chars.at(i + 1));
    //     }
    //     else {
    //         cout << amount.at(i);
    //         cout << chars.at(i);
    //         fprintf(fo, "%d", amount.at(i));
    //         fprintf(fo, "%c", chars.at(i));
    //     }
    // }


    return 0;
}
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char k = 0;

    char temp[128];
    char c = 0;
    
    bool cmp;

    while (!fin.eof()) {
        if (!k) { // если 0, то вводится 1 символ, увеличиввется количество и сохраняется текущий символ в массив
            c = fin.get();
            k++;
            temp[0] = c;
        }
        else if (k == 1) { 
            // если 1, то вводится 1 символ, сравниваются текущий и предыдущий символы, 
            // добавляется текущий символ в массив и увеличивается счётчик
            c = fin.get();
            cmp = c == temp[0];
            temp[1] = c;
            k++;
        }
        else {      
            c = fin.get(); // считывается 1 символ
            
            // если соответствие предыдущей пары символов не соотвсетствует сравнению текущей пары символов,
            // или количество больше 127
            if (cmp != (c == temp[k - 1]) || k == 127) {
                if (cmp) {  
                    // если два предыдущих символа соответствуют,
                    // то выводим количество и первый символ
                    cout << (int)k << " " << temp[0] << endl;
                    fout << k << temp[0];
                    
                    // output.write((char*)&k, 1);
                    // output.write((char*)&(temp[0]), 1);
                }
                else {   
                    // если не соответствуют,
                    // то прибавляем 8 бит к количеству
                    k += 128;
                    fout << k; // выводим количество
                    cout << (int)k << " " << endl;
                    for (int i = 0; i < -k; i++)
                        fout << temp[i];
                        // output.write((char*)&(temp[i]), 1);
                        // и в цикле выводим все символы из массива 
                }

                k = 0;  // обнуляем счётчик
            }

            k++;
            temp[k] = c; // увеличиваем количество и сохраняем символ в массив
        }
    }

    if (k) { // если счётчик не нулевой
        if (cmp) { // выводим количество и сомвол, если предыдущая пара совпадала
            cout << (int)k << " " << temp[0] << endl;
            fout << k << temp[0];
            // output.write((char*)&k, 1);
            // output.write((char*)&(temp[0]), 1);
        }
        else {
            k += 128; // прибавляем 8 бит
            cout << (int)k << endl;
            fout << k; // выводим количество в виде символа

            for (int i = 0; i < k - 128; i++)
                fout << temp[i];
                // output.write((char*)&(temp[i]), 1);
                // в цикле выводим символы из временного массива
        }
    }

    fin.close();
    fout.close();

    return 0;
}