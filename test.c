#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void leapYear(int year) {
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0)

		printf("�������%d��Ϊ����\n", year);
	else {
		printf("�������%d�겻������\n", year);
	}

}
int main() {
	int year = 0;

	leapYear(year);

	return 0;
}