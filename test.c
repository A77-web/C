#include<stdio.h>
void getsushu(int a) {
	int num = 2;
		for (; num < a; num++) {
		if (a % num == 0)
			break;
	}
	if (num==a)
		printf("���������%d������\n", a);
	else
		printf("���������%d��������\n", a);

}




int main() {
	for (int n = 100; n <= 200; n++) {
		getsushu(n);
	 }
	return 0;
}