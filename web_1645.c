#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b;
	a = 5;
	b = 7;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}