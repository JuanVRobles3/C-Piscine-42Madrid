#include <stdio.h>

char *ft_strcapitalize (char *str);

int main()
{
	char example[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char example1[] = "Hola . , gerqgASDF, ASDF56, 665  ,   54asd, %$asfd, t%";
	char *z;
	char *x;

	z = example;
	x = example1;

	printf ("Resultado:%s\n", ft_strcapitalize(z));
	printf ("Resultado:%s\n", ft_strcapitalize(x));
	return (0);
}
