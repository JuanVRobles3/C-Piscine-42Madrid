#include <stdio.h>

int ft_str_is_uppercase(char *str);

int main ()
{
	char letters[]="AAAA";
	char *a;
	a = letters;

	char numbers[]="12343235234";
	char *b;
	b = numbers;

	char null[] = "";
	char *c;
	c = null;

	printf("letters: %s = %d \n", letters, ft_str_is_uppercase(a));
	printf("numbers: %s = %d \n", numbers, ft_str_is_uppercase(b));
	printf("null: %s = %d \n", null, ft_str_is_uppercase(c));

	return (0);
}
