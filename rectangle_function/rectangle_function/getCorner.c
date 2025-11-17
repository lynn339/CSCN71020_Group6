#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"rectangle.h"
// オà(y程 x程) à(y程 x程) オà(y程 x程) à(y程 x程)
void getCorner(int x[4], int y[4])
{
	int leftTop = 0, rightTop = 0, leftBottom = 0, rightBottom = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		// leftTop
		if(y[i] > y[leftTop] || (y[i] == leftTop && x[i] < x[leftTop]))
		{
			leftTop = i;
		}
		// rightTop
		if (y[i] > y[rightTop] || (y[i] == rightTop && x[i] > x[rightTop]))
		{
			rightTop = i;
		}
		// leftBottom
		if (y[i] < y[leftBottom] || (y[i] == y[leftBottom] && x[i] < x[leftBottom]))
		{
			leftBottom = i;
		}
		// rightBottom
		if (y[i] < y[rightBottom] || (y[i] == y[rightBottom] && x[i] > x[rightBottom]))
		{
			rightBottom = i;
		}
	}
	printf("Left Top Corner: (%d %d)\n", x[leftTop], y[leftTop]);
	printf("Right Top Corner: (%d %d)\n", x[rightTop], y[rightTop]);
	printf("Left Bottom Corner: (%d %d)\n", x[leftBottom], y[rightBottom]);
	printf("Right Bottom Corner: (%d %d)\n", x[rightBottom], y[rightBottom]);
}
