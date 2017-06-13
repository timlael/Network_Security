#define INT long long int

INT fast_exp (INT a, INT exp, INT base);
		/* computes a^exp mod base */
INT gcd (INT a, INT b, INT *l, INT *m);
		/* returns gcd (a, b) and l, m s.t. l*a + m*b = gcd */
int isprime (INT n);
		/* returns TRUE if p is prime, FALSE otherwise */
int legendre (INT a, INT n);
		/* computes the Legendre symbol (a | n) */
INT sqrt_mod (INT a, INT p);
		/* returns x s.t. x*x = a mod p, for prime p */
