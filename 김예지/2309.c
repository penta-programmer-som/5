#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_false(int tall[], int over, int find[])
{
	int i, j;
	int no1 = 0, no2 = 0;

	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if ((tall[i] + tall[j]) == over) {
				no1 = i;
				no2 = j;
				break;
			}
		}
	}

	j = 0;
	for (i = 0; i < 9; i++) {
		if (i != no1 && i != no2) {
			find[j] = tall[i];
			j++;
		}
	}

}

void sort(int tall[], int find[])
{
	int i, j;
	int temp;

	for (i = 0; i < 7; i++) {
		for (j = i + 1; j < 7; j++) {
			if (find[i] > find[j]) {
				temp = find[i];
				find[i] = find[j];
				find[j] = temp;
			}
		}
	}
}

int main(void)
{
	int sum = 0;
	int over = 0;
	int tall[9];
	int find[7];
	int i;


	for (i = 0; i < 9; i++) {
		scanf("%d", &tall[i]);
		sum += tall[i];
	}

	over = sum - 100;
	find_false(tall, over, find);
	sort(tall, find);

	for (i = 0; i < 7; i++) 
		printf("%d\n", find[i]);
}
