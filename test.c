#include<stdio.h>
void getsushu(int a) {
	int num = 2;
		for (; num < a; num++) {
		if (a % num == 0)
			break;
	}
	if (num==a)
		printf("您输入的数%d是素数\n", a);
	else
		printf("您输入的数%d不是素数\n", a);

}




int main() {
	for (int n = 100; n <= 200; n++) {
		getsushu(n);
	 }
	return 0;
}