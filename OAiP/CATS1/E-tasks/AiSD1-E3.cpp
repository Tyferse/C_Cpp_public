#include <iostream>
#include <fstream>
using namespace std;


int main() {
    int n, N, i, j, line, ch = 0, sh_kr = 0, elem = 0, k = 0, krugi = 0;
    
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    fin >> n >> line;
    
    if (line > n / 2 + n % 2) {
        elem = n - line + 1;
        // кол-во элементов, которые считаются через круг слева\справа
    } 
    else
        elem = line - 1;
    
    int ch_po_krugu[elem];
    
    for (i = 0; i < n; i++) {
        if (line == 1) {
            int el_tmp = n * n;
            for (j = 0; j < n; j++) {
                fout << el_tmp << " ";
                el_tmp--;
            }
            
            break;
        }
        
        if (i < elem) {
            sh_kr = sh_kr + ((4 * (n - 1 - i * 2) - 1)); //шаги по полному кругу
            ch = n * n - sh_kr + (line - 2 * (i + 1));
            krugi++;

            ch_po_krugu[i] = sh_kr + i - (n - 2 * (i + 1)) - (n - 1 - 2 * i) - ((n - line) - i);
            
            fout << ch << " ";
        }
      
        if ((i >= elem) && (i < elem + (n - 2 * elem)) && (line <= n / 2 + n % 2)){
            //элементы, которые считаются вычитанием единицы, т.к. идут слева направо
            ch--;
            fout << ch << " ";
        }
        
        if ((i >= elem) && (i < elem + (n - 2 * elem)) && (line > n / 2 + n % 2)){
            //элементы, которые считаются прибавлением единицы
            ch++;
            fout << ch << " ";
        }
        
        if (i >= elem + (n - 2 * elem)){
            for (j = elem-1; j >= 0; j--){
                fout << n * n - ch_po_krugu[j] << " ";
            } 
            
            break;
        }
      
    }
    
    // 4 * (n - 1 - i * 2) - 1 i-тый круг
    // (line - 1) - i кол-во шагов, чтобы вернуться в нужную строку
    // (stroki) кол-во элементов, которые считаются через круг слева\справа
    // n - 2 * (stroki) кол-во элементов, которые считаются вычитанием единицы

}
