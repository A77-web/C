#include<stdio.h>
void swap(int a[], int b[]) {
	for (int i = 0, t = 0; i <= 4; i++) {
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 9,8,7,6,5 };
	swap(a, b);
	printf("数组a的元素为:\n");
	for (int i = 0; i <= 4; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	for (int i = 0; i <= 4; i++) {
		printf("%d\t", b[i]);
	}

}