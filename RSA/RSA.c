#include <stdio.h>
#include "gcd.h"

int main ()
{
	INT	p, q, n;
	INT	e, d;
	INT	phi;

	do {
		printf ("Enter primes p and q :  ");
		scanf (" %lld %lld", &p, &q);
	} while ( !isprime (p) || !isprime (q));

	n = p * q;
	phi = (p - 1) * (q - 1);

	printf ("n = %lld\t\tphi = %lld\n", n, phi);
	printf ("%7s%c%16s%c\n", "", 'e', "", 'd');
	for (e = 2; e < phi; e ++) {
		INT m;
		if (gcd (e, phi, &d, &m) == 1) 
			printf ("%15lld %15lld\n", e, d<0 ? d+phi : d);
		}
}
