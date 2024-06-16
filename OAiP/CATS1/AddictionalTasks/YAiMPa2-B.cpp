#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int a, b;
    FILE * f1 = fopen("input.txt", "r");
    fscanf(f1, "%d %d", &a, &b);
    fclose(f1);

    if (a < b)
        swap(a, b);

    FILE * f2 = fopen("output.txt", "w");

    // Брошюра существует, если остаток от деления разности номеров страниц на 4 равен 1 или 3,
    // а также, если меньший элемент чётный / нечётный соответственно.
    if ((a - b) % 4 - b % 2 * 2 == 1) 
        fprintf(f2, "%d", b + a - 1);
    else
        fprintf(f2, "0");

    fclose(f2);

    return 0;
}
