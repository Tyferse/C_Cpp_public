#include <iostream>
using namespace std;


int main() {
    /*
    int n;
    cin >> n;

    int a[100][100];
    for (int i = 0; i < n; i++) { //перебор строк
        for (int j = 0; j < n; j++) { //перебор столбцов
            if (i == j) {
                a[i][j] = 1;
            } 
            else if (i < j) {
                a[i][j] = 0;
            }   
            else {
                a[i][j] = 2;
            }
        }
    }

    //вывод
    for (int i = 0; i < n; i++) { //перебор строк
        for (int j = 0; j < n; j++) { //вывод одной строки
            cout << a[i][j] << " ";
        }
        cout << endl; //перевод строки после того, как выведены все элементы
    }
    */

    int n, m;
    cin >> n >> m;
    int mines[100][100];
    // чтение
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mines[i][j];
        }
    }

    int n, m;
    cin >> n >> m;
    // инициализация
    int mines[102][102];
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            mines[i][j] = 0;
        }
    }

    // чтение
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mines[i][j];
        }
    }

    int ans[102][102];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // координаты соседей (сдвиги)
            int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
            int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

            // перебор соседей
            int temp = 0;
            for (int k = 0; k < 8; k++)
                temp += mines[i + dy[k]][j + dx[k]];

            ans[i][j] = temp;
        }
    }

    // вывод
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mines[i][j] == 1) {
                cout << "*";
            } 
            else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
    
    return 0;
}
