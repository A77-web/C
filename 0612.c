#include<stdio.h>
#include<assert.h>
int myStrcmp(char* dest, char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	//*����ַ���ȫ����ȣ���ôѭ�����������ַ���������'\0',���Ϊ0�������ʼѭ�����м䷢��ĳ��λ�õ��ַ���һ����
	  // ��ô�ͽ���λ�õ������ַ�ASCIIֵ���
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