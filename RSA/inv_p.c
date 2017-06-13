#include <stdio.h>
#include "gcd.h"

int main (int argc, char *argv[])
{
	int	p, i;

	scanf ("%d ", &p);
	for (i = 1; i < p; i++) {
		INT inv, trash;
		gcd (i, p, &inv, &trash);
		printf ("%d %d\n", (int)i, (int)inv);
		}
}
