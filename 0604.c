#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
#define MAX_C 4	
//����
int cmpInt(int* a, int* b) {
	return *a - *b;
}
//������
int cmpDouble(int* a, int* b) {
 //�ڶԸ������double�͵�һ��Ҫ����Ŀ���������ΪҪ��ʹ����������������Ļ�
//����������ܽӽ���������ܷ���һ����С��С��������-1��С��1������cmp�ķ���ֵ��int��
//��˻Ὣ���С������0��ϵͳ��Ϊ����ȣ�ʧȥ�˱������ڵĴ�С��ϵ
    return *a > *b ? 1 : -1;
}
//�ַ���
int cmpChar(char* a, char* b) {
	return *a - *b;
}
//�ַ�����
int cmpStr(char(*a), char(*b)) {
	return strcmp(a, b);
}
int main() {
    //����
    int arrInt[MAX] = { 1,3,5,4,6,7,22,63,2,9 };
    qsort(arrInt, MAX, sizeof(arrInt[0]), cmpInt);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arrInt[i]);
    }
    printf("\n");
    double arrDouble[MAX] = { 1.0,8.0,6.0,9.0,7.0,3.0,2.0,10.0,4.0,5.0 };
    qsort(arrDouble, MAX, sizeof(arrDouble[0]), cmpDouble);
    for (int i = 0; i < MAX; i++) {
        printf("%f ", arrDouble[i]);
    }printf("\n");

    //�ַ���
    char arrChar[MAX] = { 'c','d','g','y','u','i','e','z','h','l' };
    qsort(arrChar, MAX, sizeof(arrChar[0]), cmpChar);
    for (int i = 0; i < MAX; i++) {
        printf("%c ", arrChar[i]);
    }printf("\n");

    //�ַ�����
    char arrStr[MAX_C][MAX_C] = { "asd","abf","bde","mny" };
    qsort(arrStr, MAX_C, sizeof(arrStr[0]), cmpStr);
    for (int i = 0; i < MAX_C; i++) {
        printf("%s ", arrStr[i]);
    }printf("\n");
    return 0;
}