#include <cmath>
#include <iostream>
using namespace std;


void merge(float arr[], int indexes[], int start, int end, int mid, int L);

void mergeSort(float arr[], int indexes[], int start, int end, int L) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(arr, indexes, start, mid, L);
		mergeSort(arr, indexes, mid + 1, end, L);
		merge(arr, indexes, start, end, mid, L);
	}
}

void merge(float arr[], int indexes[], int start, int end, int mid, int L) {
	float mergedArr[L];
    int mergedIndexes[L];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;
	
	while (i <= mid && j <= end) {
		if (arr[i] >= arr[j]) {
            // cout << arr[i] << " " << arr[j] << endl;
			mergedArr[k] = arr[i];
            mergedIndexes[k] = indexes[i];
			k++;
			i++;
		}
		else {
            // cout << arr[i] << " | " << arr[j] << endl;
			mergedArr[k] = arr[j];
            mergedIndexes[k] = indexes[j];

			k++;
			j++;
		}
	}
	
	while (i <= mid) {
		mergedArr[k] = arr[i];
        mergedIndexes[k] = indexes[i];
		k++;
		i++;
	}
	
	while (j <= end) {
		mergedArr[k] = arr[j];
        mergedIndexes[k] = indexes[j];
		k++;
		j++;
	}
	
	for (i = start; i < k; i++) {
		arr[i] = mergedArr[i];
        indexes[i] = mergedIndexes[i];
	}
}


int main() {
    int N;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &N);

    float R[N];
    char S[N][255];
    int a[N];

    for (int i = 0; i < N; i++) {
        fscanf(f1, "%f %s", &R[i], &S[i]);
        a[i] = i;
    }

    fclose(f1);

    
    mergeSort(R, a, 0, N - 1, N);
    

    FILE *f2 = fopen("output.txt", "w");

    /*
    name9
    name5
    name1
    name4
    name2
    name7
    name3
    name6
    name10
    name8
    */
    for (int i = 0; i < N; i++) {
        fprintf(f2, "%s\n", S[a[i]]);
        // printf("%d\n", a[i]);
    }

    fclose(f2);

    return 0;
}
