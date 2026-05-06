#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    int weight; // 몸무게
    int height; // 키
};

int main() {
    int N;
    struct Person p[50];

    scanf("%d", &N);

    // 입력
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].weight, &p[i].height);
    }

    // 등수 계산
    for (int i = 0; i < N; i++) {
        int rank = 1;

        for (int j = 0; j < N; j++) {
            if (p[j].weight > p[i].weight &&
                p[j].height > p[i].height) {
                rank++;
            }
        }

        printf("%d ", rank);
    }

    return 0;
}
