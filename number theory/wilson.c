/* A primacy test based on Wilson's Theorem */

#include "gcd.h"
#define TRUE -1
#define FALSE 0

int isprime (INT n)
{
	INT	prod = 1, i;
	
	if (n == 1)
		return FALSE;
	for (i = 2; i < n-1; i++) {
		prod = (prod * i) % n;
		}
	return (prod == 1 ? TRUE : FALSE);
}
