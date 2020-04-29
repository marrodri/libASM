
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int tst;
	int ans;
	extern int ft_strlen(char *str);
	extern char *ft_strcpy(char *dest, char *src);
	extern int ft_strcmp(char *str1, char *str2);
	extern ssize_t ft_write(int fd, const char *buff, size_t nbytes);
	extern ssize_t ft_read(int fd, const char *buff, size_t nbytes);
	extern char *ft_strdup(char *str);


/* ft_strlen test------------------------ */

	char *len_str = "hello world!!!\n";
	tst = ft_strlen(len_str);
	ans = strlen(len_str);

	printf("====ft_strlen tests========\n");
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

	printf("====ft_strcpy tests========\n");
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

	printf("====ft_strcmp tests========\n");
	tst = ft_strcmp("hello world!!!\n","hello world!!!\n");
	ans = strcmp("hello world!!!\n","hello world!!!\n");

	printf("strcmp tst|%d|\n", tst);
	printf("strcmp ans|%d|\n", ans);

	tst = ft_strcmp("abc","ab");
	ans = strcmp("abc","ab");

	printf("strcmp tst|%d|\n", tst);
	printf("strcmp ans|%d|\n", ans);
	
	tst = ft_strcmp("abc","abd");
	ans = strcmp("abc","abd");

	printf("strcmp tst|%d|\n", tst);
	printf("strcmp ans|%d|\n", ans);
	
	tst = ft_strcmp("","");
	ans = strcmp("","");

	printf("strcmp tst|%d|\n", tst);
	printf("strcmp ans|%d|\n", ans);


/*ft_write-----------------*/

	int fd_tst;
	int fd_ans;
	fd_ans = open("write_ans.txt", O_RDWR);
	fd_tst = open("write_tst.txt", O_RDWR);
	size_t write_ans_out;
	size_t write_tst_out;

	printf("====ft_write tests========\n");
	write_ans_out = write(1, "hello_world from sc_write\n", 26);
	printf("write_ans_out |%ld|\n", write_ans_out);

	write_tst_out = ft_write(1, "hello_world from ft_write\n", 26);
	printf("write_tst_out |%ld|\n", write_tst_out);

	write_ans_out = write(fd_ans, "hello_world file from sc_write\n", 31);
	printf("write_tst_out file|%ld|\n", write_ans_out);

	write_tst_out = ft_write(fd_tst, "hello_world file from ft_write\n", 31);
	printf("write_tst_out file|%ld|\n", write_tst_out);


	close(fd_ans);
	close(fd_tst);
	
	fd_ans = open("write_answ.txt", O_RDWR);
	fd_tst = open("write_tstw.txt", O_RDWR);

	write_ans_out = write(fd_ans, "hello_world from syscall\n", 25);
	printf("write_ans_out no file |%ld|\n", write_ans_out);
	write_tst_out = ft_write(fd_tst, "hello_world from syscall\n", 25);
	printf("write_ans_out no file |%ld|\n", write_tst_out);

	write_ans_out = write(-1, "hello_world from syscall\n", 25);
	printf("write_ans_out error|%ld|\n", write_ans_out);
	write_tst_out = ft_write(-1, "hello_world from syscall\n", 25);
	printf("write_tst_out error|%ld|\n", write_tst_out);

	write_ans_out = write(1, "hello_world from syscall\n", 0);
	printf("write_ans_out nobytes|%ld|\n", write_ans_out);
	write_tst_out = ft_write(1, "hello_world from syscall\n", 0);
	printf("write_tst_out nobytes|%ld|\n", write_tst_out);
	close(fd_ans);
	close(fd_tst);

/*ft_read---------------*/

	int tst_bytes;
	int ans_bytes;
	char buff[255];

	printf("====ft_read tests========\n");
	printf("read from normal STDIN with sc_read:\n ");
	while((ans_bytes = read(0, buff, 255)) > 0)
	{
		if (buff[ans_bytes - 1] == '\n')
		{
			break;
		}
	}
	buff[ans_bytes - 1] = '\0';

	printf("ans_bytes after sc_read |%d|\n", ans_bytes);
	printf("STDIN from read is |%s|\n", buff);

	printf("read from normal STDIN with ft_read:\n ");
	while((tst_bytes = ft_read(0, buff, 255)) > 0)
	{
		if (buff[tst_bytes - 1] == '\n')
		{
			break;
		}
	}
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes after ft_read |%d|\n", tst_bytes);
	printf("STDIN from ft_read is |%s|\n", buff);
	
	fd_ans = open("read_ans.txt",O_RDONLY);
	fd_tst = open("read_tst.txt",O_RDONLY);
	
	ans_bytes = ft_read(fd_ans, buff, 255);
	buff[ans_bytes - 1] = '\0';
	printf("reading files:\n");
	printf("ans_bytes|%d|\n", ans_bytes);
	printf("sc_read |%s|\n", buff);
	
	tst_bytes = ft_read(fd_tst, buff, 255);
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes|%d|\n", tst_bytes);
	printf("ft_read |%s|\n", buff);

	close(fd_ans);
	close(fd_tst);
	
	fd_ans = open("read_answ.txt", O_RDWR);
	fd_tst = open("read_tstw.txt", O_RDWR);

	ans_bytes = ft_read(fd_ans, buff, 255);
	buff[ans_bytes - 1] = '\0';
	printf("reading ERROR files:\n");
	printf("ans_bytes|%d|\n", ans_bytes);
	printf("sc_read |%s|\n", buff);
	
	tst_bytes = ft_read(fd_tst, buff, 255);
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes|%d|\n", tst_bytes);
	printf("ft_read |%s|\n", buff);


	close(fd_ans);
	close(fd_tst);

/*ft_strdup---------------*/

	char *strdup_tst;
	char *strdup_ans;
	char  empty_string[50] = "";
	char  normal_string[50] = "hello wolrd!";
	char  long_string[60] = "HELLO WORLD, TODAY IM THE LONGEST STRING EVAHHHH!!!!!!";

	printf("====ft_strdup tests========\n");
	strdup_ans = strdup(empty_string);
	printf("strdup empty ans |%s|\n", strdup_ans);
	strdup_tst = ft_strdup(empty_string);
	printf("strdup empty tst |%s|\n", strdup_tst);
	free(strdup_ans);
	free(strdup_tst);

	strdup_ans = strdup(normal_string);
	printf("strdup normal ans |%s|\n", strdup_ans);
	strdup_tst = ft_strdup(normal_string);
	printf("strdup normal tst |%s|\n", strdup_tst);
	free(strdup_ans);
	free(strdup_tst);
	
	
	strdup_ans = strdup(long_string);
	printf("strdup long ans |%s|\n", long_string);
	strdup_tst = ft_strdup(normal_string);
	printf("strdup long tst |%s|\n", long_string);
	free(strdup_ans);
	free(strdup_tst);
	return (0);

}