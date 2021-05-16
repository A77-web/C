#include<stdio.h>
#include<string.h>
#include <windows.h>

void reverse(char* arr) {
	char* left = arr;
	char* right = arr + strlen(arr) - 1;
	while (left < right) {
		char tmp = *left;
		*left =*right;
		*right = tmp;
		left++, right--;
	}

}


int main() {
	char arr[] = "helleworld";
	printf("%s\n", arr);
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}