#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int A, B;
    int revA, revB;

    scanf("%d %d", &A, &B);

    revA = (A % 10) * 100 + ((A / 10) % 10) * 10 + (A / 100);
    revB = (B % 10) * 100 + ((B / 10) % 10) * 10 + (B / 100);

    if (revA > revB)
        printf("%d", revA);
    else
        printf("%d", revB);

    return 0;
}
