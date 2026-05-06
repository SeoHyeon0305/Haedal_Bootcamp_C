#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, target;
    int arr[1000][1000];

    scanf("%d", &N);
    scanf("%d", &target);

    int x = N / 2;   
    int y = N / 2;

    int num = 1;
    arr[x][y] = 1;

    int row = x + 1, col = y + 1; 

    int step = 1;

    while (num < N * N) {

        for (int i = 0; i < step && num < N * N; i++) {
            x--;
            num++;
            arr[x][y] = num;

            if (num == target) {
                row = x + 1;
                col = y + 1;
            }
        }

        for (int i = 0; i < step && num < N * N; i++) {
            y++;
            num++;
            arr[x][y] = num;

            if (num == target) {
                row = x + 1;
                col = y + 1;
            }
        }

        step++;

        for (int i = 0; i < step && num < N * N; i++) {
            x++;
            num++;
            arr[x][y] = num;

            if (num == target) {
                row = x + 1;
                col = y + 1;
            }
        }

        for (int i = 0; i < step && num < N * N; i++) {
            y--;
            num++;
            arr[x][y] = num;

            if (num == target) {
                row = x + 1;
                col = y + 1;
            }
        }

        step++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("%d %d", row, col);

    return 0;
}
