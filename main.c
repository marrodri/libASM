
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int tst;
	int ans;
	extern int ft_strlen(char *str);

	tst = ft_strlen("hello world!!!\n");
	ans = strlen("hello world!!!\n");

	printf("len tst|%d|\n", tst);
	printf("len ans|%d|\n", ans);
	return 0;
}