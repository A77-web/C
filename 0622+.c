#include <stdio.h>
#include<assert.h>
char* myStrstr(const char* dest, const char* src) {

	char* start = (char*)dest;//��������Ҫǿ������ת����char*
	char* substart = (char*)src;
	char* cp = (char*)dest;//cp�������������׵�ַ��
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
	
		cp++;//cp++���Եõ�ԭ��ʼλ�õ���һ��λ��
	}
	return NULL;
}
int main() {
	char a[20] = "accddjj";
	char b[20] = "ccdd";
	printf("%s\n", myStrstr(a, b));
	return 0;
}