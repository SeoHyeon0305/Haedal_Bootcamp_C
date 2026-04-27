#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int num, max, position;

    for (int i = 1; i <= 9; i++) {
        scanf("%d", &num);

        if (i == 1) {
            max = num;       // 첫 번째 값을 최댓값으로 초기 설정
            position = 1;    // 위치도 1로 설정
        }

        if (num > max) {
            max = num;
            position = i;
        }
    }

    printf("%d\n%d", max, position);

    return 0;
}