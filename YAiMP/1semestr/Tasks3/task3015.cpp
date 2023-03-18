#include <iostream>
using namespace std;


int main() {
    int n, summ = 0;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        summ += i;
    }

    cout << summ * (n + 2);

    return 0;
}