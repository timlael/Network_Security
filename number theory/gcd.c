/* find the GCD of a and b through the use of Euclid's division algorithm */

#include "gcd.h"

INT gcd (INT a, INT b, INT *l, INT *m)
	/* returns GCD (a, b); ensure GCD = l*a + m*b */
{
	if (b == 0) {
		*l = 1; *m = 0; return a;
		}

	{
	INT	q = a/b, r = a%b;
				/* a = q*b + r */
	if (r == 0) {
		*l = 0; *m = 1; 
		return b;
		}
	else {
		INT c, d;
		INT t = gcd (b, r, &c, &d);
				/*	t = c*b + d*r
					r = a - q*b
					--- eliminate r ---
					t = d*a + (c-d*q)*b
				*/
		*l = d; *m = c - d*q;
		return t;
		}
	}
}
