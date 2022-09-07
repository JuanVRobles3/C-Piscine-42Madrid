#include <stdio.h>

int ft_str_is_numeric(char *str);

int main ()
{
	char letters[]="hola";
	char *a;
	a = letters;

	char numbers[]="12343235234";
	char *b;
	b = numbers;

	char null[] = "";
	char *c;
	c = null;

	printf("letters: %s = %d \n", letters, ft_str_is_numeric(a));
	printf("numbers: %s = %d \n", numbers, ft_str_is_numeric(b));
	printf("null: %s = %d \n", null, ft_str_is_numeric(c));

	return (0);
}
