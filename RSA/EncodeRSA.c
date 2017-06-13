#include <stdio.h>
#define UL 32 /* 8 * sizeof (int) */

int main (int argc, char *argv[])
{
	unsigned int	exp, base, t, ans, a, i;

	if (argc != 3) {
		fprintf (stderr, "usage: %s exp base\n", argv[0]);
		exit (0);
		}
	exp = atoi (argv[1]); base = atoi (argv[2]);
// printf ("%d %d\n", exp, base);

	scanf ("%d", &a); 
printf (" [%d]\n", a);

	t = a; ans = 1;
	for (i = 0; i < UL; i++ ) {
		if (((exp >> i) & 1) == 1) ans = ((long long int)ans * t) % base;
		t = (t * t) % base;
// printf ("[%d %d]\n", t, ans);
		}

	printf ("ans: %d\n", ans);
}
