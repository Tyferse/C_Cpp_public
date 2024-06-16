#include <cmath>
#include <iostream>
using namespace std;


int main() {
    int n, m;

    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%d", &n);

    int treesz = int(pow(2, ceil(log2(n))));
    int frtree[treesz * 2 + 1];
	// Чтение массива
    for (int i = treesz; i < treesz * 2; i++) {
        if (i < n + treesz)
            fscanf(f1, "%d", &frtree[i]);
        else
            frtree[i] = -float('inf');
    }

	// Построение дерева отрезков
    for (int i = treesz - 1; i > 0; i--) {
        frtree[i] = frtree[i*2] > frtree[i*2 + 1] ? frtree[i*2] : frtree[i*2 + 1];
    }

	// Вывод дерева отрезков
	/*for (int i = 1; i < treesz*2; i++) {
        printf("%d ", frtree[i]);
		if (log2(i + 1) == ceil(log2(i + 1)))
			printf("\n");
    }*/

    fscanf(f1, "%d", &m);
    int l = 0, r = 0, li = l, ri = r;
    int ans[m], maxel = frtree[treesz];


    char moveto; // = getc(f1);
    fscanf(f1, "%c", &moveto);
    // fscanf(f1, "%c");
    // getc(f1);
    for (int i = 0; i < m; i++) {
        // moveto = getc(f1);
        fscanf(f1, "%c", &moveto);
        // cout << moveto << " " << endl;
        if (moveto == 'R') {
            r++;
        }
        if (moveto == 'L') {
            l++;
        }


        // cout << endl << l << " " << r << " = ";
		li = l + treesz;
		ri = r + treesz;
        
        while (li < ri - 1) {
            // Если левая или правая граница нечётна или чётна соответственно, 
	        // то они "захватывают" не всю пару чисел, а лишь одно число из неё
            if (ri % 2 == 0) {
                maxel = maxel < frtree[ri] ? frtree[ri] : maxel;
            }
            if (li % 2 == 1) {
                maxel = maxel < frtree[li] ? frtree[li] : maxel;
            }

            li = (li + 1) / 2;
            ri = (ri - 1) / 2;
        }
        
        if (li == ri && maxel < frtree[ri])
            maxel = frtree[ri];
        else if (li == ri - 1 && (maxel < frtree[li] || maxel < frtree[ri])) {
            maxel = maxel < frtree[li] ? frtree[li] : maxel;
            maxel = maxel < frtree[ri] ? frtree[ri] : maxel;
        }

        // cout << maxel << endl;

        ans[i] = maxel;
        maxel = -1000000000;
        // cout << ans[i] << " ";
    }

    fclose(f1);
    

   	// Вывод ответа
    FILE *f2 = fopen("output.txt", "w");
    // cout << ans[0];
    fprintf(f2, "%d", ans[0]);
    for (int i = 1; i < m; i++) {
        fprintf(f2, " %d", ans[i]);
        // cout << " " << ans[i];
    }

    fclose(f2);

    return 0;
}
