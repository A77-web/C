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
			//�������̣������г�ʼ��
			//�����е����̶���ӡ�ɿո�
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
//��ӡ���� 
//�����̱߿��÷��Ŵ�ӡ
void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("������\n");
	int row = 0;
	int col = 0;
	//�Ϸ����ж�
	while (1) {
		printf("������Ҫ���ӵ�λ�ã�row����col����\n");
		scanf("%d %d", &row, &col);
		//����Խ��
		if (row<0 || row>MAX_ROW||col<0||col>MAX_COL) {
			printf("�������λ�÷Ƿ�����������\n");
			continue;

		}
		if (chessBoard[row][col] != ' ') {
			printf("���λ���Ѿ�������������������\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;

	}
}
//������ӽ���
//��������
void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("��������\n");
	//�Ϸ����ж�
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//���λ���Ѿ���������
		if (chessBoard[row][col] != ' ') {
			continue;
		}
		chessBoard[row][col] = 'o';
		break;


	}
}

int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// �������̣���' '��˵��û��������0�����򷵻�1
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
	// ɨ�������С��С������Խ���
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
	// ����
	if (isFull(chessBoard)) {
		return chessBoard[0][2];
	}
	// ʤ��δ��
	return ' ';
}
int main() {
	char winner = ' ';
	srand(time((unsigned int)0));
	// 1. �������̡���ʼ������
	char chessBoard[MAX_ROW][MAX_COL];
	init(chessBoard);
	while (1) {
		// 2. ��ӡ����
		print(chessBoard);
		// 3. �������
		playerMove(chessBoard);
		// 4. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// ��Ϸ����
			break;
		}
		print(chessBoard);
		// 5. ��������
		computerMove(chessBoard);
		// 6. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	print(chessBoard);
	if (winner == 'x') {
		printf("��ϲ��Ӯ��~");
	}
	if (winner == 'o') {
		printf("̫���ˣ����˹����϶��²�����");
	}
	if (winner == 'H') {
		printf("����˹����ϲ��~");
	}
	return 0;
}
