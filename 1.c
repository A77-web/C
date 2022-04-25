#include <stdio.h>
int main() {
	int n = 1999;
	int m = 2299;
	int count = 0;
	int tmp = n ^ m;
	while (tmp) {
		tmp &= (tmp - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}
