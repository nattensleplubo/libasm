#include "libasm.h"

# define CCOLOR   "\033[0m"
# define CRED     "\033[1;31m"
# define CGREEN   "\033[1;32m"
# define CTRUC   "\033[1;33m"

#define BUFFER_SIZE 2040

static void	ft_strlen_tests(const char *s)
{
	size_t res_1;
	size_t res_2;

	res_1 = strlen(s);
	printf("strlen(\"%s\"): %s%ld%s\n", s, CGREEN, res_1, CCOLOR);
	res_2 = ft_strlen(s);
	if (res_1 == res_2)
		printf("ft_strlen(\"%s\"): %s%ld%s\n", s, CGREEN, res_2, CCOLOR);
	else
		printf("ERROR\nft_strlen(\"%s\"): %s%ld%s\n", s, CRED, res_2, CCOLOR);
	printf("\n");
}

static void	ft_strcpy_tests(char *dest, const char *src)
{
	char	*res_1;
	char	*res_2;
	char	inital_dest_str[100000];

	strcpy(inital_dest_str, dest);
	res_1 = strcpy(dest, src);
	printf("strcpy(\"%s\", \"%s\"WRITE): %s%s%s\n", inital_dest_str, src, CGREEN, res_1, CCOLOR);
	res_2 = ft_strcpy(dest, src);
	if (!strcmp(res_1, res_2))
		printf("ft_strcpy(\"%s\", \"%s\"): %s%s%s\n", inital_dest_str, src, CGREEN, res_2, CCOLOR);
	else
		printf("ERROR\nft_strcpy(\"%s\", \"%s\"): %s%s%s\n", inital_dest_str, src, CRED, res_2, CCOLOR);
	printf("\n");
}

static void	ft_strcmp_tests(const char *s1, const char *s2)
{
	size_t res_1;
	size_t res_2;

	res_1 = strcmp(s1, s2);
	printf("strcmp(\"%s\", \"%s\"): %s%ld%s\n", s1, s2, CGREEN, res_1, CCOLOR);
	res_2 = ft_strcmp(s1, s2);
	if (res_1 == res_2)
		printf("ft_strcmp(\"%s\", \"%s\"): %s%ld%s\n", s1, s2, CGREEN, res_2, CCOLOR);
	else
		printf("ERROR\nft_strcmp(\"%s\", \"%s\"): %s%ld%s\t\t resultat attendu: %ld\n", s1, s2, CRED, res_2, CCOLOR, res_1);
	printf("\n");
}

static void	ft_write_tests(char *str, int fd)
{
	ssize_t res_1;
	ssize_t res_2;
	int		errno_1;
	int		errno_2;

	errno = 0;
	res_1 = write(fd, str, strlen(str));
	errno_1 = errno;
	res_2 = ft_write(fd, str, strlen(str));
	errno_2 = errno;
	if (!(res_1 ^ res_2))
		printf("Ft_write of str = \"%s\" with fd = %d return value is %s%ld%s", str, fd, CGREEN, res_2, CCOLOR);
	else
		printf("ERROR\nFt_write of str = \"%s\" with fd = %d return value is %s%ld%s", str, fd, CRED, res_2, CCOLOR);
	if (errno_1 == errno_2)
		printf("\nerrno: %s%d%s\n", CGREEN, errno_2, CCOLOR);
	else
		printf("\nerrno: %s%d%s\n", CRED, errno_2, CCOLOR);
	printf("\n");
}

static void	ft_read_tests(int fd, int read_limit)
{
	ssize_t res_1;
	ssize_t res_2;
	int		errno_1;
	int		errno_2;
	char	buff1[BUFFER_SIZE];
	char	buff2[BUFFER_SIZE];

	errno = 0;
	bzero(buff1, BUFFER_SIZE);
	bzero(buff2, BUFFER_SIZE);
	if (fd >= 0 && fd < 3)
		printf("Please write 2 times the same string to see the comparaison of results between the true read function and ft_read :\nFor the true read function :\n");
	res_1 = read(fd, buff1, read_limit);
	errno_1 = errno;
	if (fd > 2)
	{
		if (lseek(fd, 0, SEEK_SET) == -1)
		{
			close(fd);
			return ;
		}
	}
	else
		printf("For the ft_read function :\n");
	res_2 = ft_read(fd, buff2, read_limit);
	errno_2 = errno;
	if (res_1 == res_2 && strcmp(buff1, buff2) == 0 && res_1 != -1 && res_2 != -1)
	{
        printf("What was readen by ft_read at fd = %d: %s\"%s\"%s\n", fd, CGREEN, buff2, CCOLOR);
	}
    else
	{
        printf("ERROR\nWhat was readen by ft_read at fd = %d: %s\"%s\"%s\n", fd, CRED, buff2, CCOLOR);
	}
	if (errno_1 == errno_2)
	{
		printf("errno: %s%d%s\n", CGREEN, errno_2, CCOLOR);
	}
	else
	{
		printf("errno: %s%d%s\n", CRED, errno_2, CCOLOR);
	}
	printf("\n");
}

static void	ft_strdup_tests(const char *src)
{
	char	*str_1;
	char	*str_2;

	str_1 = ft_strdup(src);
	str_2 = strdup(src);
	if (!strcmp(str_1, str_2))
		printf("Return of ft_strdup with \"%s\" as arg : %s\"%s\"%s\n", src, CGREEN, str_2, CCOLOR);
	else
		printf("ERROR\nReturn of ft_strdup with \"%s\" as arg : %s\"%s\"%s\n", src, CRED, str_2, CCOLOR);
	free(str_1);
	free(str_2);
}

int main(void) 
{
	int fd;

	fd = 0; 
	printf(CTRUC "------------------------STRLEN TESTS------------------------\n" CCOLOR);
	ft_strlen_tests("test");
	ft_strlen_tests("");
	ft_strlen_tests("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	printf(CTRUC "------------------------STRCPY TESTS------------------------\n" CCOLOR);
	char dest[100];
	bzero(dest, 100);
	ft_strcpy_tests(dest, "nounou");
	ft_strcpy_tests(dest, "nanan");

	printf(CTRUC "------------------------STRCMP TESTS------------------------\n" CCOLOR);
	ft_strcmp_tests("bonjour", "bonjour");
	ft_strcmp_tests("", "oui");
	ft_strcmp_tests("oui", "");
	ft_strcmp_tests("", "");

	printf(CTRUC "-------------------------WRITE TESTS------------------------\n" CCOLOR);
	fd = open("test_file", O_CREAT | O_RDWR, 0644); //__O_TMPFILE
	if (fd == -1)
		return (close(fd), 1);
	ft_write_tests("coucou terminal\n", 1);
	ft_write_tests("coucou entree standard\n", 0);
	ft_write_tests("coucou test_file\n", fd);
	ft_write_tests("je suis la suite\n", fd);
	ft_write_tests("bonjour\n", 5);
	if (lseek(fd, 0, SEEK_SET) == -1)
        return (close(fd), 2);

	printf(CTRUC "-------------------------READ TESTS------------------------\n" CCOLOR);
	ft_read_tests(0, INT_MAX);
	ft_read_tests(2, INT_MAX);
	ft_read_tests(fd, 42);
	close(fd);
	
	printf(CTRUC "-------------------------STRDUP TESTS------------------------\n" CCOLOR);
	ft_strdup_tests("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	ft_strdup_tests("");
	return (0);
}