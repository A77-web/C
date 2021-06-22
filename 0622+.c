#include <stdio.h>
#include<assert.h>
char* myStrstr(const char* dest, const char* src) {

	char* start = (char*)dest;//在这里需要强制类型转换成char*
	char* substart = (char*)src;
	char* cp = (char*)dest;//cp就是用来保存首地址的
	assert(dest != NULL);
	assert(src != NULL);
	while (*cp)
	{
		start = cp;
		while (*start != '\0' && *substart != '\0' && *start == *substart)
		{
			start++;
			substart++;
		}
		if (*substart == '\0')
		{
			return cp;
		}
	
		cp++;//cp++可以得到原起始位置的下一个位置
	}
	return NULL;
}
int main() {
	char a[20] = "accddjj";
	char b[20] = "ccdd";
	printf("%s\n", myStrstr(a, b));
	return 0;
}