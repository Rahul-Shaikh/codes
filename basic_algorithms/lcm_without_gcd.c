#include <stdio.h>

int lcm(int x, int y)
{
	int large = (x > y) ? x : y;
	int small = (x < y) ? x : y;

	for (int i = large; ; i += large)
	{
		if (i % small == 0) return i;
	}
}

int main(void)
{
	int x = 12, y = 18;
	printf("%d\n", lcm(x,y));
}