#include <stdio.h>
#include <stdlib.h>


int main() {
    float A, B, C, D;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%f %f", &A, &B);
    fclose(f1);

    printf("%f\n", A / B);
    int cch = (A/B);
    float dch = A / B - cch;
    printf("%d %f\n", cch, dch);    


    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%d %d", &C, &D);
    fclose(f2);
    
    return 0;
}
