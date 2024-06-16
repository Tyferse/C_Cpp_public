#include <stdio.h>


int main() {
    int s, x, k;
    scanf("%d %d", &s, &k);

    x = ~(1<<k);
    printf("%x %x\n", s, x);
    s = s&x;

    printf("%d\n", s);
    return 0;
}
