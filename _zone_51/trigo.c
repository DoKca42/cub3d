#include "stdio.h"
#include <math.h>

#define PI 3.14159265

double	deg_to_rad(int angle)
{
	double	rad;

	rad = ((double)angle * PI) / 180;
	return (rad);
}


int main()
{
	int angle = 95;
	double yn, xn;

	yn = -22.000000;
	xn = -yn / tan(deg_to_rad(angle));

	printf("xn: %f, yn: %f\n", xn, yn);
	return (0);
}