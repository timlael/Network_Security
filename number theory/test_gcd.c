#include "gcd.h"

main()
{
	int a, b;
	INT g, l, m;

	scanf (" %d %d", &a, &b);
printf ("%d %d\n", a, b);
	g = gcd ((INT)a, (INT)b, &l, &m);
	printf ("%lld * %d + %lld * %d = %lld\n", l, a, m, b, g);
}
