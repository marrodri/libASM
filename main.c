
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int tst;
	int ans;
	extern int ft_strlen(char *str);
	extern char *ft_strcpy(char *dest, char *src);


	tst = ft_strlen("hello world!!!\n");
	ans = strlen("hello world!!!\n");

	printf("len tst|%d|\n", tst);
	printf("len ans|%d|\n", ans);

	tst = ft_strlen("");
	ans = strlen("");

	printf("len tst|%d|\n", tst); //when empty, it counts anyway
	printf("len ans|%d|\n", ans);

	char dest_tst[50];
	char dest_ans[50];
	char *str_tst;
	char *str_ans;
	char src_tst[50] = "I AM THE TST, TRY ME!!";
	char src_ans[50] = "I AM THE ANS, TRY ME!!";
	str_tst = ft_strcpy(dest_tst,src_tst);
	str_ans = strcpy(dest_ans,src_ans);
	printf("strcpy tst |%s|\n", str_tst);
	printf("strcpy ans |%s|\n", str_ans);

	return 0;
}