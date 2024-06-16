#include <cmath>
#include <iostream>
using namespace std;


int partition(int list[], int start, int pivot) {
	int i = start;
	while (i < pivot) {
		if(list[i] > list[pivot] && i == pivot - 1) {
			swap(list[i], list[pivot]);
			pivot--;
		}
		else if(list[i] > list[pivot]) {
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}
		else 
            i++;
	}

	return pivot;
}

void quickSort(int list[], int start, int end) {
	if (start < end) {
		int pivot = partition(list, start, end);
		
		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}


int main() {
    int N, K;
    FILE *f1 = fopen("game.in", "r");
    fscanf(f1, "%d %d", &N, &K);

    int scores[N];
    for (int i = 0; i < N; i++) {
        fscanf(f1, "%d", &scores[i]);
    }

    fclose(f1);

    // Сортировка основного массива
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (scores[i] > scores[j]) {
                swap(scores[i], scores[j]);
            }
        }
    }
    

    // quickSort(scores, 0, N - 1);

    
    for (int i = 0; i < N; i++) {
        cout << scores[i] << endl;
    }
    
    
    int * unique = new int;
    int * counts = new int;
    int m = 0;
    int ans = 0; 
    bool t = false;

    unique[0] = scores[0], 
    counts[0] = 1;

    // cout << unique[0] << " ";
    for (int i = 1;  i < N; i++) {
        if (scores[i] == scores[i - 1]) {
            counts[m]++;

            // Первый случай: три одинаковых числа.
            // Существует всего одна уникальная комбинация трёх одинаковых чисел.
            if (!t && counts[m] > 2) {
                ans++;
                t = true;
            }
        }
        else {
            m++;
            unique[m] = scores[i];
            counts[m] = 1;
            // cout << unique[m] << " ";
            t = false;
        }
    }
    

    // cout << endl << m << endl;

    
    for (int i = 0; i <= m; i++) {
        cout << unique[i] << ": " << counts[i] << endl;
    }
    

    FILE *f2 = fopen("game.out", "w");

    // Второй случай: два одинаковых числа.
    // Сначала учтём последовательности, в которые дважды входит большее значение. 
    // Для этого просмотрим все элементы unique[i], i = 1, 2,…, m, для каждого из них определим минимальное unique[j],
    // удовлетворяющее условию unique[j] * K <= unique[i]. 
    // Тогда, если counts[i] > 1, то к двум числам unique[i] можно добавить любое из чисел 
    // unique[j], unique[j + 1], …, unique[i - 1]. 
    // Таким образом, можно составить (i - j) троек, 
    // а из каждой тройки можно получить C из 3 по 1 = 3 различных комбинации.

    // Последовательности, в которые дважды входит большее значение
    
    int j = 0;
    for (int i = 1; i <= m; i++) {
        while (j < i && (unique[j] * K < unique[i]))
            j++;
        
        if (counts[i] > 1) 
            ans += (i - j) * 3;
    }
    
    // Последовательности, в которые дважды входит меньшее значение
    j = m;
    for (int i = m - 1; i >= 0; i--) {
        while (j > i && unique[i] * K < unique[j])       
            j--;
        
        if (counts[i] > 1)
            ans += (j - i) * 3;
    }
    

    // Третий случай:  количество последовательностей, в которых все числа разные.
    // Перебирая значения unique[1], unique[2], … , unique[m], для каждого из них определим минимальное значение unique[j], 
    // которое удовлетворяет условию unique[j] * K >= unique[i]. 
    // Таких значений (i-j). Любые два из них можно добавить к a[i] и получить тройку чисел.
    // Их количкство равно числу сочетаний из (i - j) по 2:

    // C из (i - j) по 2 = (i - j)! / ((i - j - 2)! * 2!) = ((i - j)! * (i - j)(i - j - 1)) / ((i - j)! * 2) =
    // = (i - j)(i - j - 1) / 2

    // Но, так как мы считаем количество комбинаций внутри тройки чисел, 
    // то полученное выше значение нужно умножить на 6 (число перестановок в множестве из 3 элементов)
    // т. е. (i - j)(i - j - 1) * 3
    for (int i = 1; i <= m; i++) {
        while (j < i && unique[j] * K < unique[i])
            j++;
        
        ans += (i - j) * (i - j - 1) * 3;
    }

    fprintf(f2, "%d", ans);

    fclose(f2);

    return 0;
}
