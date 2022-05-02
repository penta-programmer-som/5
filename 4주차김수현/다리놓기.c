/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int pick(int n, int picked[], int m, int toPick)
{
	int smallest;
	int lastIndex;
	int i;
	int count = 0;
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			count++;
		return count;
	}
	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);
	}
}

int main(void)
{
	int n;
	int i;
	int* p;
	int a;
	int b;

	scanf("%d ", &n);

	if (n <= 0) return 0;
	p = (int*)malloc(sizeof(int) * n);
	if (!p) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		p[i] = pick(a, p, b, b);
	}

	for (i = 0; i < n; i++)
		printf("%d", p[i]);

	free(p);
}*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void pick(int n, int picked[], int m, int toPick)
{
	int smallest;
	int lastIndex;
	int i;
	int count = 0;
	if (toPick == 0) {
		
		for (i = 0; i < m; i++)
		{
			count++;


		}printf("%d", count-1);
		printf("\n");
		return;
	}
	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);
	}
}
int main(void)
{
	int n;
	int m;
	int* p;
	printf("Enter n and m:");
	scanf("%d %d", &n, &m);
	if (m <= 0) return 0;
	p = (int*)malloc(sizeof(int) * m);
	if (!p) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	pick(n, p, m, m);

	free(p);

}