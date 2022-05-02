// 수 찾기 (시간초과) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100000] = { 0 };

void sort(int arr[], int size)
{
	int i, j;
	int temp = 0;
	int max = 0;

	for (i = 0; i < size - 1; i++) {
		max = i;
		for (j = i + 1; j < size; j++) {
			if (arr[max] > arr[j])
				max = j;
		}

		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

int search(int arr[], int key, int low, int high)
{
	int middle;

	if (low <= high) {
		middle = (low + high) / 2;
		if (key == arr[middle])
			return 1;
		else if (key < arr[middle])
			return search(arr, key, low, middle - 1);
		else
			return search(arr, key, middle + 1, high);
	}
	return 0;
}

int main(void)
{
	int n, m;
	int i;
	int find;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	// 정렬
	sort(arr,n);

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &find);
		printf("%d\n", search(arr, find, 0, n));
	}
}
