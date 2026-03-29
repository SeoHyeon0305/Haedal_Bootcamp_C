#include <stdio.h>

int main()
{
	int age = 30;
	if (age >= 20)
	{
		if (age >= 65)
			printf("당신은 어르신입니다.\n");
		printf("당신은 미성년자입니다.\n");

	}
	else
		printf("당신은 미성년자입니다.\n");
}