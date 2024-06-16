#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;


struct man {
    int height;
    string name;
};

bool cmp(man a, man b) {
    return a.height < b.height;
}

void print(vector <int> a) { // функция вывода вектора
    for (auto now : a) {
        cout << now << " ";
    }

    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (auto now : a) {
        cout << now << " ";
    }


    vector <pair <int, int>> b(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b[i] = {temp, i}; // создание пары значение - номер
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (auto now : b) {
        cout << now.second << " ";
    }


    vector <man> c(n);
    for (int i = 0; i < n; i++) {
        int temp;
        string s_temp;
        cin >> temp >> s_temp;
        man struct_temp; // временная структура
        struct_temp.height = temp;
        struct_temp.name = s_temp;
        c[i] = struct_temp; // создание пары значение - номер
    }

    stable_sort(c.begin(), c.end(), cmp);
    for (auto now : c) {
        cout << now.name << endl;
    }


    vector <int> d(n);
    for (int i = 1; i <= n; i++) {
        d[i - 1] = i;
    }

    while (next_permutation(d.begin(), d.end())) {
        print(d);
    }

    return 0;
}