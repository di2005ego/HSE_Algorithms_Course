#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* arr;
	int n, i, target, mid, left = 0;
	int pos = -1;
	scanf("%d %d", &n, &target);
	int right = n-1;
	arr = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Initial array:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Target element: %d\n", target);
	printf("Search history: ");
	/*Ядро программы. Начало*/
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) {
			printf("%d(%d)\n", arr[mid], mid);
			pos = mid;
			printf("Target is found at: %d", pos);
			break;
		}
		if (arr[mid] < target) {
			printf("%d(%d) ", arr[mid], mid);
			left = mid + 1;
		}
		if (arr[mid] > target) {
			printf("%d(%d) ", arr[mid], mid);
			right = mid - 1;
		}
	}
	/*Ядро программы. Конец*/
	if (pos == -1) {
		printf("\n");
		printf("No targets");
	}
	free(arr);
	return 0;
}