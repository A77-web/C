#include<stdio.h>
int main() {
	int menoy = 20;
	int space = menoy;
	int total = menoy;
	while (space > 1) {
		total = total + space / 2;
		space = space / 2 + space % 2;
	}
	printf("您一共喝了%d瓶饮料", total);
	return 0;
}