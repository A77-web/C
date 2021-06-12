#include<stdio.h>
#include<assert.h>
int myStrcmp(char* dest, char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	//*如果字符串全部相等，那么循环结束两个字符串都到达'\0',相减为0，如果开始循环到中间发现某个位置的字符不一样，
	  // 那么就将该位置的两个字符ASCII值相减
	while (*dest == *src && *dest != '/0') {
		dest++;
		src++;
	}
	return *dest - *src;
}
int main() {
	char* dest = "abf";
	char* src = "abc";
	int ret = 0;
	ret = myStrcmp(dest, src);
	printf("%d", ret);
	return 0;
}