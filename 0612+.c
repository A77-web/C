#include<stdio.h>
#include<assert.h>
char*myStrcpy(char* dest,const char* src) {
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++) {
		;
	}
	return ret;
}
int main() {
	char src[5] = "adsa";
	char dest[100] = { 0 };
	printf("%s", myStrcpy(dest, src));
	return 0;
}