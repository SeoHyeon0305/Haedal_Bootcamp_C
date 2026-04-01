#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, to, via);   
    printf("%d %d\n", from, to);   
    hanoi(n - 1, via, from, to);   
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", (1 << N) - 1);

    hanoi(N, 1, 2, 3);

    return 0;
}
