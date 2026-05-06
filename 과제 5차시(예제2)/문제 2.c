#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, max;
	int* arr;

	printf("입력할 숫자 개수: ");
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
		exit(1);

	for (int i = 0; i < n; i++) {
		printf("%d번째 숫자 입력: ", i);
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for (int i = 0; i < n; i++)
		if (max <= arr[i])
			max = arr[i];

	printf("입력한 숫자 중 최댓값: %d\n", max);

	free(arr);
	return 0;
}