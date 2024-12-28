#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* arr;
	int n, i, j, target = 0;
	scanf("%d %d", &n, &target);
	arr = malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Initial array:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Target element: %d\n", target);
	/*Ядро программы. Начало*/
	int k = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == target) {
			k += 1;
			if (k > 0) {
				printf("Target is found at: ");
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (arr[i] == target) {
			printf("%d ", i);
		}
	}
	if (k == 0) {
		printf("No targets");
	}
	/*Ядро программы. Конец*/
	free(arr);
	return 0;
}