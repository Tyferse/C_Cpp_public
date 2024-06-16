#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    float n, n_tmp, answer[1000];
    int k;
    fin >> n >> k;

    int sqrtn_tmp, sqrtn = floor(sqrt(n));
    bool flag = false;
    // Перебираем все корни
    for (; sqrtn > 0; sqrtn--) {
        n_tmp = n;
        n_tmp = n_tmp - sqrtn*sqrtn;
        answer[0] = sqrtn;
        if(n_tmp != 0) {
            // В случае, если текущее число n не является квадратом
            for (int i = 1; i < k; i++) {
                sqrtn_tmp = floor(sqrt(n_tmp));
                n_tmp -= sqrtn_tmp * sqrtn_tmp;
                answer[i] = sqrtn_tmp;
                if (n_tmp == 0) { // Если n является суммой квадратов чисел
                    k = i + 1;
                    flag = true;
                    break;
                }
            }
        }
        else { // Если число n является квадратом
            flag = true;
            k = 1;
        }

        if (flag) 
            break;
        
        // Если вариант с максимальным корнем не подходит, то перебираем с корнем поменьше
        // повторяем пока не найдем нужный вариант или не переберем все возможные варианты
    }

    if (!flag) 
        fout << "NO";
    else {
        fout << "YES" << endl;
        for (int i = 0; i < k; i++) 
            fout << answer[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
