#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <math.h>

int main()
{
	int n;
	scanf(" %d", &n);

	int i = -n / 2;
	int j;
	while (i <= n / 2)
	{
		for (j = 1; j <= 2 * abs(i); ++j)
			printf(" ");

		for (j = 1; j <= n - 2 * abs(i); ++j)
			printf("* ");

		printf("\n");
		++i;

	}

	return 0;
}
