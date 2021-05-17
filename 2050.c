#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a = 0, i = 0, n = 0, sum = 0;
	printf("请输入一个值:");
	scanf("%d", &n);
	for (i = 0; i < 5; i++) {
		a = n + a * 10;
		sum += a;
	}
	printf("%d=", sum);
	return 0;
}