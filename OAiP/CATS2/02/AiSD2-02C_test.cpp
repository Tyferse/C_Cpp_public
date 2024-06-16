#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> pq; // очередь с приоритетом для хранения элементов
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        pq.push(x);
    }

    while (m--) {
        int x = pq.top(); // первое наименьшее число
        pq.pop();
        int y = pq.top(); // второе наименьшее число
        pq.pop();
        pq.push(x + y); // добавляем сумму в конец очереди
        // pq.push(x + y); // добавляем сумму в конец очереди (два раза, чтобы сохранить размер очереди)
    }

    vector<int> v; // создаем вектор для вывода элементов в порядке возрастания
    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }

    for (int x : v) {
        fout << x << " ";
    }

    fin.close();
    fout.close();

    return 0;
}