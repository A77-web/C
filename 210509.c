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
	// mem => memory 内存
    // memset：把一段内存上的每个字节都设置成一个具体的值
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	//随机产生十个雷
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
//打印地图
void print(char theMap[MAX_ROW][MAX_COL]) {
	system("cls");
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}

}
//合法性判定
void update(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r == row&& c == col) {
				continue;
			}
			//这个位置不需要判断
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
	//1.创建地图并初始化
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;
	while (1) {
     //2.打印地图
		print(showMap);
     //3.玩家输入坐标
		int row = 0;
		int col = 0;
		printf("请输入坐标(row,col)\n");
		scanf("%d %d", &row, &col);
	//4,合法性判定
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL) {
			printf("您输入的位置有误,请重新输入\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("您输入的位置重复,请重新输入\n");
			continue;

		}
	//5,判定是否踩雷
		if (mineMap[row][col] == '1') {
			printf("您踩雷了,游戏结束\n");
			break;
		}
	//6,更新showMap,显示雷的个数
		update(showMap, mineMap, row, col);
	//7.判定游戏胜利
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("恭喜你,游戏胜利\n");
			break;
		}


	}
	return 0;
}