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
    FILE *f1 = fopen("input.txt", "r");

    int n;
    fscanf(f1, "%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &a[i]);
        cout << a[i] << " ";
    }

    fclose(f1);

    quickSort(a, 0, n - 1);

    FILE *f2 = fopen("output.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(f2, "%d ", a[i]);
    }

    fclose(f2);

    return 0;
}
