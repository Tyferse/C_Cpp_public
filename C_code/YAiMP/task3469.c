#include <stdio.h>
#include <iomanip>


int main () {
    int n, h, m, seconds;
    scanf("%d", &n);
    h = n / 3600;
    m = (n - 3600*h) / 60;
    seconds = n - 3600*h - 60*m;
    printf("%d:%d%d:%d%d", h % 24, m / 10 , m % 10, seconds / 10, seconds % 10);


    return 0;
}
