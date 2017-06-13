#include <stdio.h>
#include "GF_functs.h"

byte addGF (byte b1, byte b2)
{
	return b1 ^ b2;
}

byte mulGF (byte b1, byte b2)
{
	byte	r = 0, i;
	unsigned	t = b2;

	for (i = 0; i < 8; i++) {
		if ((b1 & 0x01) == 1)
			r ^= (byte)t;
		b1 >>= 1; 
		t <<= 1;
		if ((t & 0x100) == 0x100)
			t ^= GF_MOD;
		}
	return r;
}
byte mulGF_m (byte b1, byte b2, int z)
{
	byte	r = 0, i;
	unsigned	t = b2;

	for (i = 0; i < 8; i++) {
		if ((b1 & 0x01) == 1)
			r ^= (byte)t;
		b1 >>= 1; 
		t <<= 1;
		if ((t & 0x100) == 0x100)
			t ^= z;
		}
	return r;
}



/* find the GCD of a and b through the use of Euclid's division algorithm */

byte GF_gcd (int a, int b, int *l, int *m)
	/* returns GCD (a, b); ensure GCD = l*a + m*b */
{
	if (b == 0) {
		*l = 1; *m = 0; return a;
		}

	//{
	//int	q = a/b, r = a%b;
int q, r;
				/* a = q*b + r */
	if (r == 0) {
		*l = 0; *m = 1; 
		return b;
		}
	//else {
		//INT c, d;
		//INT t = gcd (b, r, &c, &d);
				/*	t = c*b + d*r
					r = a - q*b
					--- eliminate r ---
					t = d*a + (c-d*q)*b
				*/
		//*l = d; *m = c - d*q;
		//return t;
		//}
	//}
}
