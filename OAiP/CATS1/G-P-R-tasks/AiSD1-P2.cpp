#include <iostream>
#include <fstream>
#define L 100000
using namespace std;


struct score {
    long long int number;
    int count;
};

int arr_tmp[L], numbers_tmp[L];
score numbers[L], numbers_two[L];
void merge_sort(int arr[], int l, int r);
long long int min_next(score arr[], int size, long long int key);


int main() {
    ifstream fin("game.in");
    ofstream fout("game.out");
    int n, K, size_numbers;
    long long int answer = 0;

    fin >> n;
    fin >> K;

    // Вводим массив чисел с баллами
    for (int i = 0; i < n; i++)
        fin >> numbers_tmp[i];
    
    // Сортируем его по возастанию
    merge_sort(numbers_tmp, 0, n - 1);


    numbers[0].number = numbers_tmp[0];
    numbers[0].count = 1;
    size_numbers = 1;

    // Создаём массив из чисел и их количества
    for (int i = 1; i < n; i++) {
        if (numbers_tmp[i] == numbers[size_numbers - 1].number) {
            numbers[size_numbers - 1].count++;
        }
        else {
            size_numbers++;
            numbers[size_numbers - 1].number = numbers_tmp[i];
            numbers[size_numbers - 1].count = 1;
        }
    }

    // Проверка первого случая: три одинаковых числа
    // и параллельно создание массива из чисел, колличество которых больше или равно 2
    int size_numbers_two = 0;
    for (int i = 0; i < size_numbers; i++) {
        if (numbers[i].count > 2) 
            answer++;

        if (numbers[i].count > 1) {
            numbers_two[size_numbers_two] = numbers[i];
            size_numbers_two++;
        }
    }

    // Второй случай: с двумя одинаковыми баллами (a:b:b, где b НЕ БОЛЬШЕ а более чем в k раз)
    // функция min_next возвращает индекс минимального элемента, большего чем key
    for (int i = 0; i < size_numbers; i++) {
        long long int top = min_next(numbers_two, size_numbers_two, numbers[i].number * K);
        long long int bottom = min_next(numbers_two, size_numbers_two, numbers[i].number);
        answer += 3 * (top - bottom);
    }

    // Снова второй случай, но в счёте a:b:b, b НЕ МЕНЬШЕ а более чем в k раз
    for (int i = 0; i < size_numbers_two; i++) {
        long long int top = min_next(numbers, size_numbers, numbers_two[i].number * K);
        long long int bottom = min_next(numbers, size_numbers, numbers_two[i].number);
        answer += 3 * (top - bottom);
    }

    // Третий случай: три разных элемента a:b:c
    // Перебирая значения numbers[1], numders[2], … , numbers[size_numbers - 1], 
    // для каждого из них определим минимальное значение numbers[bottom], 
    // которое удовлетворяет условию numbers[bottom] * K >= numbers[top]. 
    // Таких значений (top - bottom). Любые два из них можно добавить к numbers[i] и получить тройку чисел.
    // Их количкство равно числу сочетаний из (top - bottom) по 2 
    // (для удобства, пусть i = top, j = bottom):

    // C из (i - j) по 2 = (i - j)! / ((i - j - 2)! * 2!) = ((i - j)! * (i - j)(i - j - 1)) / ((i - j)! * 2) =
    // = (i - j)(i - j - 1) / 2

    // Но, так как мы считаем количество комбинаций внутри тройки чисел, 
    // то полученное выше значение нужно умножить на 6 (число перестановок в множестве из 3 элементов)
    // т. е. (i - j)(i - j - 1) * 3
    for (int i = 0; i < size_numbers; i++) {
        long long int top = min_next(numbers, size_numbers, numbers[i].number * K);
        long long int bottom = min_next(numbers, size_numbers, numbers[i].number);
        long long int d = top - bottom;
        answer += 3 * d * (d - 1);
    }

    fout << answer;

    fin.close();
    fout.close();
    return 0;
}

void merge_sort(int arr[], int l, int r) {
    if (l == r) 
        return;

    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    int i = l;
    int j = m + 1;
    for (int k = 0; k <= r - l; k++) {
        if ((i <= m && arr[i] <= arr[j]) || j > r) {
            arr_tmp[k] = arr[i];
            i++;
        }
        else {
            arr_tmp[k] = arr[j];
            j++;
        }
    }

    for (int k = 0; k <= r - l; k++) 
        arr[l + k] = arr_tmp[k];
}

long long int min_next(score arr[], int size, long long int key) {
    long long int l = 0;
    long long int r = size - 1;
    long long int m = (r + l) / 2;
    while (l <= r) {
        if (arr[m].number == key) 
            return m + 1;
        else if (arr[m].number > key) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }

        m = (l + r) / 2;
    }

    if (arr[m].number > key) 
        return m;
    else 
        return m + 1;
}
