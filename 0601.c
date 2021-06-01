#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Input(int* num) {
	printf("请输入您需要找的数;");
	scanf("%d", num);
}
int findNumber(int arr[3][3], int num) {
	int i = 2;
	int j = 0;//从左下角开始找
	while (i >= 0 && j < 3) {
		if (arr[i][j] > num) {
			--i;
		}
		if (arr[i][j] < num) {
			++j;
		}
		if (arr[i][j] ==num) {
			printf("找到了%d\n", arr[i][j]);
			return 1;
		}
	}
	printf("抱歉没有找到您需要的数字");
	return 0;
}
int main() {
	int num;
	int arr[3][3] = {
	 {1,2,3},
	 {4,5,6},
	 {7,8,9}
	};
	Input(&num);
	findNumber(arr, num);
	return 0;
}