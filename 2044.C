#include<stdio.h>
char findKiller() {
	char killer = 'a';
	for (; killer <= 'd'; killer++) {
		if (((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd'))==3)
			printf("������:%c", killer);

	}
}
int main() {
	findKiller();
	return 0;
}