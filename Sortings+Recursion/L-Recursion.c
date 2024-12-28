#include <stdio.h>
#include <stdlib.h>
int array[21][21][21] = { 0 };
int function(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return function(20, 20, 20);
	}
	if (array[a][b][c] == 0) {
		if (a < b && b < c) {
			array[a][b][c] = function(a, b, c - 1) + function(a, b - 1, c - 1) - function(a, b - 1, c);
		}
		else {
			array[a][b][c] = function(a - 1, b, c) + function(a - 1, b - 1, c) + function(a - 1, b, c - 1) - function(a - 1, b - 1, c - 1);
		}
	}
	return array[a][b][c];
}
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int print = function(a, b, c);
	printf("%d", print);
	return 0;
}