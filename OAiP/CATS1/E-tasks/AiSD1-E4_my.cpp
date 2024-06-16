#include <cmath>
#include <iostream>
using namespace std;


int partition(int list[], int indexes[], int start, int pivot) {
	int i = start;
    if (!indexes) {
        while (i < pivot) {
            if(list[i] > list[pivot] && i == pivot - 1) {
                swap(list[i], list[pivot]);

                swap(indexes[i], indexes[pivot]);
                pivot--;
            }
            else if(list[i] > list[pivot]) {
                swap(list[pivot - 1], list[pivot]);
                swap(list[i], list[pivot]);

                swap(indexes[pivot - 1], indexes[pivot]);
                swap(indexes[i], indexes[pivot]);
                pivot--;
            }
            else 
                i++;
        }
    }
    else {
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
    }

	return pivot;
}

void quickSort(int list[], int indexes[], int start, int end) {
	if (start < end) {
		int pivot = partition(list, indexes, start, end);
		
		quickSort(list, indexes, start, pivot - 1);
		quickSort(list, indexes, pivot + 1, end);
	}
}


int main() {
    FILE *f1 = fopen("shelter.in", "r");

    int n;
    fscanf(f1, "%d", &n);

    int settlements[n];
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &settlements[i]);
    }

    int m;
    fscanf(f1, "%d", &m);

    int shelters[m];
    int si[m];
    for (int i = 0; i < m; i++) {
        fscanf(f1, "%d", &shelters[i]);
        si[i] = i + 1;
    }

    fclose(f1);

    quickSort(shelters, si, 0, m - 1);
    // quickSort(settlements, 0, 0, n - 1);

    /*
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (shelters[i] > shelters[j]) {
                swap(shelters[i], shelters[j]);
                swap(si[i], si[j]);
            }
        }
    }
    */
    
    /*
    for (int i = 0; i < m; i++) {
        cout << shelters[i] << " " << si[i] << endl;
    }
    */

    FILE *f2 = fopen("shelter.out", "w");  

    
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        while ((abs(shelters[j] - settlements[i]) > abs(shelters[j + 1] - settlements[i])) && j < m - 1) {
            j++;
        }

        if ((abs(shelters[j] - settlements[i]) <= abs(shelters[j + 1] - settlements[i]) && j < m - 1) || j == m - 1) {
            fprintf(f2, "%d ", si[j]);
        }
        else {
            fprintf(f2, "%d ", si[j + 1]);
        }
    }
    

    fclose(f2);

    return 0;
}
