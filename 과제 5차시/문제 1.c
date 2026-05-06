#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* org = fopen("input.txt", "rt");
	FILE* copy = fopen("output.txt", "wt");
	char str[100];

	if (org == NULL || copy == NULL)
	{
		printf("파일 열기 실패!\n");
		exit(1);
	}

	printf("---------- org 내용 ----------\n");
	while (fgets(str, sizeof(str), org) != NULL) {
		printf("현재 복사 문자열:\n");
		printf("%s\n, str");
		fputs(str, copy);
	}
	printf("\n");
	printf("--------------------------\n");

	if (feof(org) != 0)
		printf("파일 복사 성공!\n");
	else
		printf("파일 복사 실패!\n");

	fclose(org);
	fclose(copy);

	return 0;
}