#include<stdio.h>
#include<assert.h>
char* myStrcat(char* dest, char* src) {
	char* cp = dest;
	assert(src && dest);
	while (*dest != '\0') {
		dest++;
	}
	while (*dest++ = *src++) {
		;
	}
	return cp;
}
int main() {
	char str[1024] = "abcd";
	char buf[1024] = "efgh";
	printf("%s\n", myStrcat(str, buf));
	return 0;
}