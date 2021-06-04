#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
#define MAX_C 4	
//整型
int cmpInt(int* a, int* b) {
	return *a - *b;
}
//浮点型
int cmpDouble(int* a, int* b) {
 //在对浮点或者double型的一定要用三目运算符，因为要是使用像整型那样相减的话
//如果是两个很接近的数则可能返回一个很小的小数（大于-1，小于1），而cmp的返回值是int型
//因此会将这个小数返回0，系统认为是相等，失去了本来存在的大小关系
    return *a > *b ? 1 : -1;
}
//字符型
int cmpChar(char* a, char* b) {
	return *a - *b;
}
//字符串型
int cmpStr(char(*a), char(*b)) {
	return strcmp(a, b);
}
int main() {
    //整型
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

    //字符型
    char arrChar[MAX] = { 'c','d','g','y','u','i','e','z','h','l' };
    qsort(arrChar, MAX, sizeof(arrChar[0]), cmpChar);
    for (int i = 0; i < MAX; i++) {
        printf("%c ", arrChar[i]);
    }printf("\n");

    //字符串型
    char arrStr[MAX_C][MAX_C] = { "asd","abf","bde","mny" };
    qsort(arrStr, MAX_C, sizeof(arrStr[0]), cmpStr);
    for (int i = 0; i < MAX_C; i++) {
        printf("%s ", arrStr[i]);
    }printf("\n");
    return 0;
}