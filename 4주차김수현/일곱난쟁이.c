#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int list[9];
	int i;
	int j;
	int check = 0;
	int temp;
	int real[7];
		for (i = 0; i < 9; i++)
			scanf("%d", &list[i]);

	for (i = 0; i < 9 - 1; i++)
		for (j = 0; j < 9 - 1 - i; j++)
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}

	j = 0;
	for (i = 0; i < 9; i++)
	{
		if (check <= 100) {
			check += list[i];
			real[j++] = list[i];
		}
	}

	printf("%d \n", check);

	for (i = 0; i < 7; i++)
		printf("%d ", real[i]);
}