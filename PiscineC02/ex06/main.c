#include <stdio.h>

int ft_str_is_printable(char *str);

int main ()
{
	char letters[]="|@#¢";
	char *a;
	a = letters;

	char numbers[]="12343235234";
	char *b;
	b = numbers;

	char null[] = "";
	char *c;
	c = null;

	printf("letters: %s = %d \n", letters, ft_str_is_printable(a));
	printf("numbers: %s = %d \n", numbers, ft_str_is_printable(b));
	printf("null: %s = %d \n", null, ft_str_is_printable(c));

	return (0);
}
