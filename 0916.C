#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
void leftTurn(char* str, int length, int k) {
	//使用临时变量储存第一个字符
	for (int i = 0; i < k; i++) {
		char tmp = str[0];
		//遍历数组将后一位赋值给前一位
		for (int n = 0; n < length - 1; n++) {
			str[n] = str[n + 1];
		}
		str[length - 1] = tmp;
	}
}
int main() {
	char str[] = "abcd";
	int length = strlen(str);
	int k = 0;
	printf("请输入左旋的个数;");
	scanf("%d", &k);
	leftTurn(str, length, k);
	printf("%s\n", str);
}