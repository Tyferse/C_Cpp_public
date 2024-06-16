#include <stdio.h>
#include <stdlib.h>


int main() {
    // Files
    FILE * fin = fopen("inpt1.txt", "w");
    fprintf(fin, "%d", 23142);
    fclose(fin);

    int a;
    FILE * fin1 = fopen("inpt1.txt", "r");
    fscanf(fin1, "%d", &a);
    printf("%d\n", a);
    fclose(fin1);

    // Arrays
    int n = 5;
    int arr [5] = {123, 2528582, 49249258, -1, 0};
    // float farr [2];
    char str [5] = "CATS\0";
    printf("%s\n", str);
    for (int i = 0; i < 5; i++) 
        printf("%d\n", arr[i]);

    // Ampersants, links and adresses
    int *m = &n;
    printf("%p --\n%d\n", n, m);
    printf("%d\n", sizeof(arr));

    int x = calloc(1, sizeof(int));
    printf("%d", &x);
    

    return 0;
}
