#include <stdio.h>

int main (void)
{
	static char	*statik;

	statik = "hello world";
	printf("%s\n", statik);
	return (0);
}
