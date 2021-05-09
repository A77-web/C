#include<stdio.h>
void init(int arr[], int b) {
	for (int i = 0; i <= b; i++) {
		arr[i] = 0;
	}
}
void print(int arr[], int b) {
	for (int i = 0; i <= b; i++) {
		printf("%d\t", arr[i]);
	}
}
void reverse(int arr[], int b) {
	for (int i = 0, tmp = 0; i <= b; i++) {
		tmp = arr[i];
		arr[i] = arr[b];
		arr[b] = tmp;
	}
}
int main() {
	int arr[] = { 9,8,7,6,5,4 };
	int b = sizeof(arr) / sizeof(arr[0]) - 1;
	print(arr, b);
	reverse(arr, b);
	printf("\n");
	for (int i = 0; i <= b; i++) {
		printf("%d\t", arr[i]);
	}
}