#include <stdio.h>
#include <stdlib.h>
void quick_sort(int* arr, int left, int right, const int n) {
	if (left < right) {
		int mid = partition(arr, left, right, n);
		quick_sort(arr, left, mid - 1, n);
		quick_sort(arr, mid + 1, right, n);
	}
}
int partition(int* arr, int left, int right, const int n) {
	int pivot_index = (left + right) / 2;
	int pivot = arr[pivot_index];
	printf("\nPivot index: %d , pivot element: %d", pivot_index, pivot);
	int* other_arr = calloc((right - left + 1), sizeof(int)); /*Создание дополнительного массива*/
	int j = 0; /*Новый индикатор для допмассива*/
	for (int i = left; i <= right; i++) {
		if (i == pivot_index) {
			continue;
		}
		if (arr[i] <= pivot) {
			other_arr[j] = arr[i]; /*Записывание элементов меньших или равных опорному в допмассив*/
			j = j + 1;
		}
	}
	other_arr[j] = pivot;
	int k = right - left; /*Новый обратный индикатор для допмассива*/
	for (int i = right; i >= left; i--) {
		if (arr[i] > pivot) {
			other_arr[k] = arr[i]; /*Записывание элементов больших, чем опорный, в допмассив*/
			k = k - 1;
		}
	}
	for (int l = left; l <= right; l++) {
		arr[l] = other_arr[l-left]; /*Переписывание данных из допмассива в исходный*/
	}
	printf("\nArray after partition: ");
	for (int q = 0; q < n; q++) {
		printf("%d ", arr[q]);
	}
	printf("\n");
	return j + left;
	free(other_arr);
}
int main() {
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
	quick_sort(arr, 0, n - 1, n);
	free(arr);
	return 0;
}