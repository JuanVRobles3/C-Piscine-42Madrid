#include <stdio.h>

char *ft_strlowcase (char *str);

int main ()
{
	char example [] = "ASasdf!$546ASGasdrEWl";
	char *a;
	a = example;

	printf("Resultado: %s\n", ft_strlowcase(a));
	return (0);
}
