#include <stdio.h>
#include <stdlib.h>
void merge(int* arr, int left, int mid, int right) {
	int len_1 = mid - left;
	int len_2 = right - mid + 1;
	int signal = 2147483647;
	int* left_arr = malloc((len_1+1) * sizeof(int));
	int* right_arr = malloc((len_2+1) * sizeof(int));
	for (int i = 0; i < len_1; i++) {
		left_arr[i] = arr[left+i];
	}
	for (int j = 0; j < len_2; j++) {
		right_arr[j] = arr[mid+j];
	}
	printf("\nLeft part: ");
	for (int i = 0; i < len_1; i++) {
		printf("%d ", left_arr[i]);
	}
	printf("\nRight part: ");
	for (int j = 0; j < len_2; j++) {
		printf("%d ", right_arr[j]);
	}
	left_arr[len_1] = signal;
	right_arr[len_2] = signal;
	int i = 0;
	int j = 0;
	for (int k = left; k <= right; k++) {
		if (left_arr[i] < right_arr[j]) {
			arr[k] = left_arr[i];
			i = i + 1;
		}
		else {
			arr[k] = right_arr[j];
			j = j + 1;
		}
	}
	printf("\nMerged parts: ");
	for (int k = left; k <= right; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n");
	free(left_arr);
	free(right_arr);
}
void merge_sort(int* arr, int left, int right) {
	if (left < right) {
		int mid = (left + right + 1) / 2;
		merge_sort(arr, left, mid - 1);
		merge_sort(arr, mid, right);
		merge(arr, left, mid, right);
	}
}
int main()
{
	int* arr;
	int n, i = 0;
	scanf("%d", &n);
	arr = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Initial array:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	merge_sort(arr, 0, n - 1);
	free(arr);
	return 0;
}