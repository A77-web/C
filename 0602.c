#include<stdio.h>
#include <assert.h>
int compare(const void* a, const void* b) {
	return(*(int*)a - *(int* )b);
}
void swap(int* a, int* b) {
	int tmp = 0;
	 tmp = *a;
	*a = *b;
	*b = tmp;
}
void qsort(void* arr, int num, int size, int(*compare)(const* p1, const* p2)) {
	int bound = 0;
	int cur = num - 1;
	for (cur = num - 1; cur >= 0; cur--) {
		for (bound = 0; bound < cur; bound++) {
			if (compare((int*)arr + bound, (int* )arr + bound + 1)>0) {
				swap((int*)arr + bound, (int*)arr + bound + 1);
			}
		}
	}
}
int main() {
	int arr[] = { 2,4,35,65,7,8,9,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, size, sizeof(arr[0]), compare);
	for (int i = 0; i < size; i++) {
		printf("%d	", arr[i]);
	}
	return 0;
}