#include <stdio.h>
#include<assert.h>
void* myMemcpy(void* dest, const void* src, size_t len) {
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	while (len--) {
		*pdest++ = *psrc++;
	}
	return dest;
}
int main() {

	char arr[10] = "abcdefg";
	char arr0[10] = "abcdefg";
	char arr1[10] = { 0 };
	myMemcpy(arr + 2, arr, 4);
	myMemcpy(arr1, arr0, 4);
	printf("内存覆盖情况：%s\n", arr + 2);
	printf("正常情况：%s\n", arr1);
}