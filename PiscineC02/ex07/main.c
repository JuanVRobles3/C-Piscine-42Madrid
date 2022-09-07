#include <stdio.h>

char *ft_strupcase(char *str);

int	main()
{
	char example[] = "asdfgasSDTfdgRTEfgfgsE$ert%&/(t";
	char *a;
	a = example;
	
	printf("Resultado: %s\n", ft_strupcase(a));
	return (0);
}
