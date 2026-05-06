#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// malloc, free쓰기 위해 stdlib 헤더 사용

int main(void) {
	int n, max;
	int* arr;

	// 입력할 숫자 개수 입력받기
	printf("입력할 숫자 개수: ");
	scanf("%d", &n);

	// 정수 n개 크기만큼 메모리 할당, arr에 시작 주소 저장
	arr = (int*)malloc(sizeof(int) * n);
	// 실패 시 NULL 들어감 >> NULL참조 시 오류나기 때문에 오류 처리
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// malloc, free쓰기 위해 stdlib 헤더 사용

	int main(void) {
		int n, max;
		int* arr;

		// 입력할 숫자 개수 입력받기
		printf("입력할 숫자 개수: ");
		scanf("%d", &n);

		// 정수 n개 크기만큼 메모리 할당, arr에 시작 주소 저장
		arr = (int*)malloc(sizeof(int) * n);
		// 실패 시 NULL 들어감 >> NULL참조 시 오류나기 때문에 오류 처리
		if (arr == NULL)
			exit(1);

		// n개만큼 숫자 입력받기
		for (int i = 0; i < n; i++) {
			printf("%d번째 숫자 입력: ", i);
			scanf("%d", &arr[i]);
		}

		// 맨 첫번쨰 원소를 max에 저장
		max = arr[0];
		// arr부터 저장된 숫자 보면서 max보다 크면 max에 저장
		for (int i = 0; i < n; i++)
			if (max <= arr[i])
				max = arr[i];

		printf("입력한 숫자 중 최댓값: %d\n", max);

		// arr 다 쓰고 난 뒤에는 반납!
		free(arr);
		return 0;
	}c

	// n개만큼 숫자 입력받기
	for (int i = 0; i < n; i++) {
		printf("%d번째 숫자 입력: ", i);
		scanf("%d", &arr[i]);
	}

	// 맨 첫번쨰 원소를 max에 저장
	max = arr[0];
	// arr부터 저장된 숫자 보면서 max보다 크면 max에 저장
	for (int i = 0; i < n; i++)
		if (max <= arr[i])
			max = arr[i];

	printf("입력한 숫자 중 최댓값: %d\n", max);

	// arr 다 쓰고 난 뒤에는 반납!
	free(arr);
	return 0;
}