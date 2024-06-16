#include <stdio.h>


int main () {
    int a, b, l, N, ans;
    scanf("%d\n%d\n%d\n%d", &a, &b, &l, &N);

    ans = l * 2;
    ans += (N - 1) * b * 2;
    ans += (N - 1) * a * 2 + a;
    printf("%d", ans);
    

    return 0;
}
