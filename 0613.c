#include<stdio.h>
#include<assert.h>
void* myMemmove(char* dest, const char* src,int n) {
	char* pdest = (char*)dest;
	const char*psrc = (const char*)src;
	assert(dest != NULL);
	assert(src != NULL);
	if (pdest <= psrc && pdest >= psrc + n) {
		while (n--) {
			*pdest = *psrc;
		}
	}
	else
	{
		while (n--) {
			*(pdest + n) = *(psrc + n);
		}
	}
	return dest;
}
int main() {
	char arr[10] = "abcdefg";
	char arr0[10] = "abcdefg";
	char arr1[10] = { 0 };
	myMemmove(arr + 2, arr, 4);
	myMemmove(arr1, arr0, 4);
	printf("内存覆盖情况:%s", arr + 2);
	printf("正常情况:%s", arr1);
	return 0;
}