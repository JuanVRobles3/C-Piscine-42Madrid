#include <stdio.h>
#include <string.h>
char    *ft_strncpy(char *dest, char *src, unsigned int n);
int main(void)
{
    char    *dest;
    char    *src;
	unsigned int n;

	n=7;

    src = "h";
    printf("src: %s\n", src);
    ft_strncpy(dest, src, n);
    printf("dest: %s\n", dest);
    return (0);
}
