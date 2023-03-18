#include <iostream>
using namespace std;


int main() {
    int n, k;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> k;
    k %= n;
    if (k > 0)
        k = n - k;
    else
        k = abs(k);

    // Переворачиваем левую часть массива
    int tmp;
    for (int i = 0; i < k / 2; i++) {
        tmp = A[i];
        A[i] = A[k - i - 1];
        A[k - i - 1] = tmp;
    }

    // Переворачиваем правую часть массива
    for (int i = 0; i < (n - k) / 2; i++) {
        tmp = A[i + k];
        A[i + k] = A[n - i - 1];
        A[n - i - 1] = tmp;
    }

    // Переворачиваем весь массив целиком и таким образом 
    // переносим правую часть в левую сторону массива, 
    // а левую часть - в правую сторону массива
    for (int i = 0; i < n / 2; i++) {
        tmp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
