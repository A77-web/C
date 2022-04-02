#include<stdio.h>
#include<assert.h>
int myStrlen(const char* str) {
	assert(str != NULL);
	int count = 0;
	while (*str++) {
		count++;
	}
	return count;
}

int main() {
	char arr[] = "qqqwwweee";
	printf("%d\n", myStrlen(arr));
	return 0;
}