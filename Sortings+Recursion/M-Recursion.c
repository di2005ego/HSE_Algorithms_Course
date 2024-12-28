#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void binary_form(n, prevBit, print) {
	if (!n) {
		return;
	}
	int currBit = n % 2;
	print = (currBit != prevBit || !print);
	binary_form(n / 2, currBit, print);
	if (print) {
		printf("%d", currBit);
	}
}
void reverse_binary_form(n, prevBit, print) {
	if (!n) {
		return;
	}
	int currBit = n % 2;
	print = (currBit != prevBit || !print);
	if (print) {
		printf("%d", currBit);
	}
	reverse_binary_form(n / 2, currBit, print);
}
int main() {
	unsigned long long int n;
	int prevBit = -1;
	bool print = false;
	scanf("%llu", &n);
	binary_form(n, prevBit, print);
	printf("\n");
	reverse_binary_form(n, prevBit, print);
	return 0;
}