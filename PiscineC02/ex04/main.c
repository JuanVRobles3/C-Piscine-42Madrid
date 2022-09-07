#include <stdio.h>

int fr_str_is_lowercase(char *str);

int main ()
{
	char letters[]="aaaa";
	char *a;
	a = letters;

	char numbers[]="12343235234";
	char *b;
	b = numbers;

	char null[] = "";
	char *c;
	c = null;

	printf("letters: %s = %d \n", letters, ft_str_is_lowercase(a));
	printf("numbers: %s = %d \n", numbers, ft_str_is_lowercase(b));
	printf("null: %s = %d \n", null, ft_str_is_lowercase(c));

	return (0);
}
