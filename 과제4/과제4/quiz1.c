#define #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[9][9];
    int max = 0;
    int row, col;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);

            if (arr[i][j] > max) {
                max = arr[i][j];
                row = i + 1; // 행 번호
                col = j + 1; // 열 번호
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d", row, col);

    return 0;
}
