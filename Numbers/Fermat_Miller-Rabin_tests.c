#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned long long modularExponent(unsigned long long x, unsigned long long d, unsigned long long n) {
	unsigned long long z, z2;
	if (d == 0) {
		return 1;
	}
	if (d == 1) {
		return x;
	}
	else {
		if (d % 2 == 0) {
			z = modularExponent(x, d / 2, n) % n;
			z2 = pow(z, 2);
			return z2 % n;
		}
		else {
			z = modularExponent(x, d / 2, n) % n;
			z2 = pow(z, 2);
			return (z2 * x) % n;
		}
	}
}

unsigned long long millerRabin(unsigned long long n) {
	unsigned long long d = n - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	unsigned long long s = log2((n - 1) / d);
	unsigned long long firstTest = 0;
	unsigned long long secondTest = 0;
	unsigned long long candsMR = 0;
	for (unsigned long long a = 1; a <= n - 1; a++) {
		bool answer1 = 0;
		if (modularExponent(a, d, n) == 1) {
			firstTest += 1;
			answer1 = 1;
		}
		bool answer2 = 0;
		for (unsigned long long r = 0; r < s; r++) {
			if (modularExponent(a, pow(2, r) * d, n) == n-1) {
				secondTest += 1;
				answer2 = 1;
				break;
			}
		}
		if (answer1 == 0 && answer2 == 0) {
			candsMR += 1;
		}
	}
	printf("Miller-Rabin test: ");
	if (candsMR > 0) {
		printf("False ");
	}
	if (candsMR == 0) {
		printf("True ");
	}
	printf("%llu %llu %llu", candsMR, firstTest, secondTest);
}

int main() {
	unsigned long long n = 0;
	unsigned long long candsFermat = 0;
	unsigned long long testsFermat = 0;
	scanf("%llu", &n);

	/*Miller-Rabin*/
	millerRabin(n);

	/*Fermat*/
	unsigned long long a = 0;
	for (a = 1; a <= n - 1; a++) {
		if (modularExponent(a, n-1, n) != 1) {
			candsFermat += 1;
		}
		else {
			testsFermat += 1;
		}
	}
	printf("\nFermat test: ");
	if (candsFermat == 0) {
		printf("True ");
	}
	if (candsFermat > 0) {
		printf("False ");
	}
	printf("%llu %llu", candsFermat, testsFermat);
	return 0;
}