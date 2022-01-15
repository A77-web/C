#include<stdio.h>
int jiecheng(int n) {
	if (n == 1)
		return 1;
	else
		return n *jiecheng(n - 1);

}
int main() {
	printf("%d", jiecheng(4));
	return 0;
}