#include <stdio.h>

#define DIAMETRE 24

int main()
{
	int y;
	int x;
	int res;

	y = 0;
	while (y < DIAMETRE / 2)
	{
		x = 0;
		while (x < DIAMETRE / 2 - y / 2)
		{
			printf(" ");
			x++;
		}
		x = 0;
		while (x < y)
		{
			printf("x");
			x++;
		}
		printf("\n");
		y += 2;
	}
	return (0);
}