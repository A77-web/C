#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
void leftTurn(char* str, int length, int k) {
	//ʹ����ʱ���������һ���ַ�
	for (int i = 0; i < k; i++) {
		char tmp = str[0];
		//�������齫��һλ��ֵ��ǰһλ
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
	printf("�����������ĸ���;");
	scanf("%d", &k);
	leftTurn(str, length, k);
	printf("%s\n", str);
}