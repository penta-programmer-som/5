#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int check(int A[], int m, int low, int high)
{
	int middle;
	if (low < high) {
		middle = (low + high) / 2;
		if (m == A[middle])
			return 1;
		else if (m < A[middle])
			return check(A, m, low, middle - 1);
		else return check(A, m, middle + 1, high);
	}
	return 0;
}

int main(void)
{

	int n;
	int i;
	int j;
	int temp;
	int m;
	int* A;
	int* key;
	int keyN;

	scanf("%d", &n);

	if (n <= 0) return 0;
	A = (int*)malloc(sizeof(int) * n);
	if (!A) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);


	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}

	
	scanf("%d", &m);

	if (m <= 0) return 0;
	key = (int*)malloc(sizeof(int) * m);
	if (!key) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}

	for (i = 0; i < m; i++)
		scanf("%d", &key[i]);


	for (i = 0; i < m; i++) {
		keyN = key[i];
		printf("%d ", check(A, keyN, 0, n));
	}

	free(A);
	free(key);

}