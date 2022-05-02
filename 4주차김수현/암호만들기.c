#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void pick(char item[], int n, int picked[], int m, int toPick)
{
	int smallest;
	int lastIndex;
	int i;
	int index;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
		{
			printf("%d ", picked[i]);
			index = picked[i];
			printf("%c ", item[index]);
		}
		printf("\n");
		return;
	}
	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, toPick - 1);
	}
}
int main(void)
{
	int n;
	int m;
	int* p;
	char* item;
	char temp;
	int i, j;
	int a;
	printf("Enter n and m:");
	scanf("%d %d", &n, &m);
	a = m;
	if (m <= 0) return 0;
	p = (int*)malloc(sizeof(int) * m);
	if (!p) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (i = 0; i < m; i++)
		p[i] = i;
	if (a <= 0) return 0;
	item = (char*)malloc(sizeof(char) * a);
	if (!item) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}
	for (i = 0; i < a; i++)
		scanf("%c ", &item[i]);

	for (i = 0; i < a; i++)
		for (j = 0; j < (a - 1) - i; j++)
			if (item[j] > item[j + 1])
			{
				temp = item[j];
				item[j] = item[j + 1];
				item[j + 1] = temp;
			}

	pick(item, n, p, m, m);

	free(p);

}
