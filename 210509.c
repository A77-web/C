#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void init(char showMap[MAX_ROW][MAX_COL],char mineMap[MAX_ROW][MAX_COL]){
	// mem => memory �ڴ�
    // memset����һ���ڴ��ϵ�ÿ���ֽڶ����ó�һ�������ֵ
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	//�������ʮ����
	srand((unsigned int)time(0));
	int mineCount = 0;
	while (mineCount<MINE_COUNT) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] =='1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}
	}
//��ӡ��ͼ
void print(char theMap[MAX_ROW][MAX_COL]) {
	system("cls");
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}

}
//�Ϸ����ж�
void update(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r == row&& c == col) {
				continue;
			}
			//���λ�ò���Ҫ�ж�
			if (r<0 || r>MAX_ROW || c<0 || c>MAX_COL) {
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	showMap[row][col] = '0' + count;
}
int main() {
	//1.������ͼ����ʼ��
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;
	while (1) {
     //2.��ӡ��ͼ
		print(showMap);
     //3.�����������
		int row = 0;
		int col = 0;
		printf("����������(row,col)\n");
		scanf("%d %d", &row, &col);
	//4,�Ϸ����ж�
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL) {
			printf("�������λ������,����������\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("�������λ���ظ�,����������\n");
			continue;

		}
	//5,�ж��Ƿ����
		if (mineMap[row][col] == '1') {
			printf("��������,��Ϸ����\n");
			break;
		}
	//6,����showMap,��ʾ�׵ĸ���
		update(showMap, mineMap, row, col);
	//7.�ж���Ϸʤ��
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("��ϲ��,��Ϸʤ��\n");
			break;
		}


	}
	return 0;
}