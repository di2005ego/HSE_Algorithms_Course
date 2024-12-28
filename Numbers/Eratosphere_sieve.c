#include <stdio.h>
#include <stdlib.h>

void sieve(unsigned long long s, unsigned long long f) {
	int* arr = calloc((f + 1), sizeof(int));
	int iter = 1;
	int k = 0;
	int primes = f - s + 1;
	for (unsigned long long i = 0; i <= f; i++) {
		arr[i] = 1;
	}
	for (unsigned long long p = 2; p * p <= f; p++) {
		if (arr[p] == 1) {
			for (int i = p*p; i <= f; i += p) {
				if (k == 0 && i>=s && arr[i]==1) {
					printf("\nIteration : %d\n", iter);
					k = 1;
				}
				if (i >= s && arr[i] == 1) {
					printf("%llu ", i);
					primes = primes - 1;
				}
				arr[i] = 0;
			}
			iter += 1;
		}
		/*iter += 1;*/
		k = 0;
	}
	printf("\nPrimes :\n");
	if (primes == 0) {
		printf("No primes");
	}
	else {
		for (int p = s; p <= f; p++) {
			if (arr[p] == 1) {
				printf("%d ", p);
			}
		}
	}
}

int main() {
	unsigned long long s, f;
	scanf("%llu %llu", &s, &f);
	printf("Start and finish: %llu %llu", s, f);
	sieve(s, f);
	return 0;
}