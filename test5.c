#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int DigitSum(int n) {
	if (n == 0)
		return 0;
	else if (n < 10)
		return n % 10;
	else
		return n % 10 + DigitSum(n / 10);
}
int main() {
	int n = 0;
	printf("请输入一个数\n");
	scanf("%d", &n);
	printf("和为%d", DigitSum(n));

	return 0;
	system("pause");
}
