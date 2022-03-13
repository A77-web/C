#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int strlen(char* string) {
	if (*string != '\0') {
		return 1 + strlen(string + 1);
	}
	else
		return 0;
}
int main() {
	char string[] = "abcdefg";
	int ret = strlen(string);
	printf("%d\n", strlen(string));
	system("pause");
}
