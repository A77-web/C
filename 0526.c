#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char a[1024];
char b[1024];
int xuanzhuan(char newa[], char newb, char zancunyi[], char zancuner[], int length, int k) {
	char olda[1024];
	strcpy(olda, a);
	for (int i = 1; i < k; i++) {
		*(zancunyi + i) = *(newa + i);
	}
	for (int i = k, j = 0; i <= length; i++, j++) {
		*(newa + j) = *(newa + i);
	}
	for (int i = length - k + 1, j = 0; i <= length; i++, j++) {
		*(newa + i) = *(zancunyi + j);
	}
	if (strcmp(newa, b) == 0) {
		return 1;
	}
	for (int i = length - k + 1, j = 0; i <= length; i++, j++) {
		*(zancuner + j) = *(olda + i);
	}
	for (int i = length - k, j = length; i >= 0; i--, j--) {
		*(olda + j) = *(olda + i);
	}
	for (int i = 0; i < k; i++) {
		*(olda + i) = *(zancuner + i);
	}
	if (strcmp(olda, b) == 0) {
		return 1;
	}
	else
		return 0;
}
int main() {
	char zancunyi[1024];
	char zancuner[1024];
	printf("��������Ҫ�жϵ��ַ���\n");
	gets(a);
	gets(b);
	char newa[1024];
	char newb[1024];
	strcpy(newa, a);
	strcpy(newb, b);
	int n = 0;
	for (; n < 1024; n++) {
		if (a[n] == '/0')
			break;
	}
	int length = n - 1;
	int k = 1;
	for (; k < n; k++) {
		if (xuanzhuan(newa, newb, zancunyi,zancuner, length, k) == 1) {
			printf("�������ַ�������ת��");
			break;
		}
	}
	if (k == n)
		printf("�������ֲ����໥��ת��");
}