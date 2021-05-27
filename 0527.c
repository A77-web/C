#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*Cmp)(int x, int y);
void bubbleSort(int arr[], int len, Cmp cmp) {
	for (int bound = 0; bound < len; bound++) {
		for (int cur = len - 1; cur > bound; cur--) {
			if (cmp(arr[cur - 1], arr[cur]) != 1){
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
}
		}
	}
}

int less(int x, int y) {
	return x < y ? 1 : 0;
}

int greater(int x, int y) {
	return x > y ? 1 : 0;
}


int main() {
	int arr[] = { 9, 5, 2, 7, 3, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size, less);
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

	printf("================\n");

	bubbleSort(arr, size, greater);
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
		return 0;
	}
}