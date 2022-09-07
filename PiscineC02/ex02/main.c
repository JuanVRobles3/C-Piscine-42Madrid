#include <stdio.h>


int ft_str_is_alpha(char *src);

int	main(void)
{
	char letters[] = "hola";
	char *a;
	a = letters;

	char numbers[] = "12341234";
	char *b;
	b = numbers;

	char null[] = "";
	char *c;
	c = null;

	printf("letter: %s = %d \n", letters, ft_str_is_alpha(a));
	printf("numbers: %s = %d \n", numbers, ft_str_is_alpha(b));
	printf("null: %s = %d \n", null, ft_str_is_alpha(c));

	return (0);
}
