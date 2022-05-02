#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int* p;
	int n;
	int i, j;
	int temp;
	int count = 0;

	scanf("%d ", &n);

	if (n <= 0) return 0;
	p = (int*)malloc(sizeof(int) * n);
	if (!p) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (p[j] > p[j + 1]) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				count++;
			}

	printf("%d", count);
	free(p);
}