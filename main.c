
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, char **argv)
{
	int tst;
	int ans;
	extern int ft_strlen(char *str);
	extern char *ft_strcpy(char *dest, char *src);
	extern int ft_strcmp(char *str1, char *str2);
	extern char *ft_strdup(char *str);


/* ft_strlen test------------------------ */

	char *len_str = "hello world!!!\n";
	tst = ft_strlen(len_str);
	ans = strlen(len_str);

	printf("len tst|%d|\n", tst);
	printf("len ans|%d|\n", ans);
	printf("STR:|%s|\n", len_str);

	tst = ft_strlen("");
	ans = strlen("");

	printf("len tst|%d|\n", tst); //when empty, it counts anyway
	printf("len ans|%d|\n", ans);

	len_str = "jaskjdnhskjdhakjdnsalkjsdnlaskjdhalksjdlkdhsja";
	tst = ft_strlen(len_str);
	ans = strlen(len_str);

	printf("len tst|%d|\n", tst); //when empty, it counts anyway
	printf("len ans|%d|\n", ans);
	printf("STR:|%s|\n", len_str);


/* ft_strcpy test------------------------ */

	char dest_tst[50];
	char dest_ans[50];
	char src_tst[50] = "IM LOOOOOONG TST, TRYME!!!!";
	char src_ans[50] = "IM LOOOOOONG ANS, TRYME!!!!";
	char *str_tst ;
	char *str_ans ;

	str_tst = ft_strcpy(dest_tst,src_tst);
	str_ans = strcpy(dest_ans,src_ans);

	printf("strcpy tst |%s|\n", str_tst);
	printf("strcpy ans |%s|\n", str_ans);

	char src_tst1[50] = "SHTST...";
	char src_ans1[50] = "SHANS...";

	str_tst = ft_strcpy(dest_tst,src_tst1);
	str_ans = strcpy(dest_ans,src_ans1);

	printf("strcpy tst |%s|\n", str_tst);
	printf("strcpy ans |%s|\n", str_ans);

	char src_tst2[50] = "";
	char src_ans2[50] = "";

	str_tst = ft_strcpy(dest_tst,src_tst2);
	str_ans = strcpy(dest_ans,src_ans2);

	printf("strcpy tst |%s|\n", str_tst);
	printf("strcpy ans |%s|\n", str_ans);


/* ft_strcmp test------------------------ */

	tst = ft_strcmp("hello world!!!\n","hello world!!!\n");
	ans = strcmp("hello world!!!\n","hello world!!!\n");

	printf("strcmp tst|%d|\n", tst);
	printf("strcmp ans|%d|\n", ans);

	tst = ft_strcmp("abc","ab");
	ans = strcmp("abc","ab");

	printf("strcmp tst|%d|\n", tst); //when empty, it counts anyway
	printf("strcmp ans|%d|\n", ans);
	
	tst = ft_strcmp("abc","abd");
	ans = strcmp("abc","abd");

	printf("strcmp tst|%d|\n", tst); //when empty, it counts anyway
	printf("strcmp ans|%d|\n", ans);
	
	tst = ft_strcmp("","");
	ans = strcmp("","");

	printf("strcmp tst|%d|\n", tst); //when empty, it counts anyway
	printf("strcmp ans|%d|\n", ans);


/*ft_write-----------------*/

	int fd_tst;
	int fd_ans;
	fd_ans = open("write_ans.txt", O_RDWR);
	size_t write_ans_out;
	size_t write_tst_out;

	write_ans_out = write(1, "hello_world from syscall\n", 25);
	printf("write_ans_out |%ld|\n", write_ans_out);
	printf("errno from ans|%d|\n", errno);
	write_ans_out = write(fd_ans, "hello_world from syscall\n", 25);
	printf("write_ans_out |%ld|\n", write_ans_out);
	printf("errno from ans|%d|\n", errno);
	
	/*error handling*/
	
	fd_ans = open("write_answ.txt", O_RDWR);
	write_ans_out = write(-1, "hello_world from syscall\n", 25);
	printf("write_ans_out |%ld|\n", write_ans_out);
	printf("errno from ans|%d|\n", errno);
	write_ans_out = write(fd_ans, "hello_world from syscall\n", 25);
	printf("write_ans_out |%ld|\n", write_ans_out);
	printf("errno from ans|%d|\n", errno);
	// printf();
	// printf();


/*ft_read---------------*/


/*ft_strdup---------------*/

	char *strdup_tst;
	char *strdup_ans;
	char  empty_string[50] = "";
	char  normal_string[50] = "hello wolrd!";
	char  long_string[60] = "HELLO WORLD, TODAY IM THE LONGEST STRING EVAHHHH!!!!!!";

	strdup_ans = strdup(empty_string);
	printf("strdup empty ans |%s|\n", strdup_ans);
	strdup_ans = ft_strdup(empty_string);
	printf("strdup empty tst |%s|\n", strdup_tst);

	// strdup_ans = strdup(normal_string);
	// printf("strdup normal ans |%s|\n", strdup_ans);
	
	strdup_tst = ft_strdup(normal_string);
	printf("strdup normal tst |%s|\n", strdup_tst);
	

	//segfault inside my .s file

	return 0;
}