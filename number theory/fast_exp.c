#include "functs.h"
#define UL 32 /* 8 * sizeof (int) */

int fast_exp (int a, int exp, int mod)
{
	unsigned int	i;
	unsigned long long	t, ans;

	t = a; ans = 1;
	for (i = 0; i < UL; i++ ) {
		if ((exp >> i) & 1 == 1) ans = (ans * t) % mod;
		t = (t * t) % mod;
		}
	return (int)ans;
}
