#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Input(int* num) {
	printf("����������Ҫ�ҵ���;");
	scanf("%d", num);
}
int findNumber(int arr[3][3], int num) {
	int i = 2;
	int j = 0;//�����½ǿ�ʼ��
	while (i >= 0 && j < 3) {
		if (arr[i][j] > num) {
			--i;
		}
		if (arr[i][j] < num) {
			++j;
		}
		if (arr[i][j] ==num) {
			printf("�ҵ���%d\n", arr[i][j]);
			return 1;
		}
	}
	printf("��Ǹû���ҵ�����Ҫ������");
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