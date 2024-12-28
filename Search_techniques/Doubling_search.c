#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int* arr;
	int n, i, target, mid, left = 0;
	int pos = -1;
	int bound = 0;
	scanf("%d %d", &n, &target);
	int right = n - 1;
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
	if (target < arr[0]) {
		printf("Bounds history: %d(%d)", arr[0], 0);
		printf("\nNo targets");
		free(arr);
		exit(0);
	}
	printf("Bounds history: ");
	printf("%d(%d) ", arr[bound], bound);
	if (arr[bound] == target) {
		printf("\nTarget is found at: %d", bound);
		free(arr);
		exit(0);
	}
	if (n == 1) {
		printf("\nNo targets");
		free(arr);
		exit(0);
	}
	bound += 1;
	printf("%d(%d) ", arr[bound], bound);
	if (arr[bound] == target) {
		printf("\nTarget is found at: %d", bound);
		free(arr);
		exit(0);
	}
	if (arr[bound] > target) {
		printf("\nNo targets");
		free(arr);
		exit(0);
	}
	int fixed_bound = -1;
	while (bound < n) {
		bound *= 2;
		if (bound >= n) {
			fixed_bound = bound / 2;
			break;
		}
		printf("%d(%d) ", arr[bound], bound);
		if (arr[bound] > target) {
			right = bound - 1;
			fixed_bound = bound / 2;
			break;
		}
		if (arr[bound] == target) {
			printf("\nTarget is found at: %d", bound);
			free(arr);
			exit(0);
		}
	}
	if (fixed_bound == -1) {
		fixed_bound = bound;
	}
	if (fixed_bound == n - 1 && arr[fixed_bound] < target) {
		printf("\nNo targets");
		free(arr);
		exit(0);
	}
	if (target<arr[2]) {
		printf("\nNo targets");
		free(arr);
		exit(0);
	}
	left = fixed_bound + 1;
	printf("\nSearch history: ");
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) {
			printf("%d(%d)\n", arr[mid], mid);
			printf("Target is found at: %d", mid);
			free(arr);
			exit(0);
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
	if (pos == -1) {
		printf("\nNo targets");
	}
	free(arr);
	return 0;
}