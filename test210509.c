#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3

void init(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessBoard[row][col] = ' ';
			//创建棋盘，并进行初始化
			//将所有的棋盘都打印成空格
		}
	}

}

void print(char chessBoard[MAX_ROW][MAX_COL]){
	system("cls");
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c |",chessBoard[row][col]);
		}
		printf("\n+---+---+---+\n");
	}

}
//打印棋盘 
//将棋盘边框用符号打印
void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("请落子\n");
	int row = 0;
	int col = 0;
	//合法性判定
	while (1) {
		printf("请输入要落子的位置（row）（col）；\n");
		scanf("%d %d", &row, &col);
		//棋子越界
		if (row<0 || row>MAX_ROW||col<0||col>MAX_COL) {
			printf("您输入的位置非法请重新输入\n");
			continue;

		}
		if (chessBoard[row][col] != ' ') {
			printf("这个位置已经有棋子了请重新输入\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;

	}
}
//玩家落子结束
//电脑落子
void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("电脑落子\n");
	//合法性判定
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//这个位置已经有棋子了
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'o';
		break;


	}
}

int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// 遍历棋盘，有' '就说明没满，返回0，否则返回1
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char isGameOver(char chessBoard[MAX_ROW][MAX_COL]) {
	// 扫描所有行、列、两个对角线
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	// 和棋
	if (isFull(chessBoard)) {
		return chessBoard[0][2];
	}
	// 胜负未分
	return ' ';
}
int main() {
	char winner = ' ';
	srand(time((unsigned int)0));
	// 1. 创建棋盘、初始化棋盘
	char chessBoard[MAX_ROW][MAX_COL];
	init(chessBoard);
	while (1) {
		// 2. 打印棋盘
		print(chessBoard);
		// 3. 玩家落子
		playerMove(chessBoard);
		// 4. 判定胜负
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// 游戏结束
			break;
		}
		print(chessBoard);
		// 5. 电脑落子
		computerMove(chessBoard);
		// 6. 判定胜负
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	print(chessBoard);
	if (winner == 'x') {
		printf("恭喜你赢啦~");
	}
	if (winner == 'o') {
		printf("太菜了，连人工智障都下不过！");
	}
	if (winner == 'H') {
		printf("你和人工智障差不多~");
	}
	return 0;
}
