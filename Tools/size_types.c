#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *out = fopen ("size_types.h", "w");

	fprintf (out, "/* signed and unsigned 8-bit numbers */\n");
	fprintf (out, "typedef signed char S8;\n");
	fprintf (out, "typedef unsigned char U8;\n");

	fprintf (out, "/* signed and unsigned 16-bit numbers */\n");
	if (sizeof (short int) == 2) {
		fprintf (out, "typedef signed short int S16;\n");
		fprintf (out, "typedef unsigned short int U16;\n");
		}
	else if (sizeof (int) == 2) {
		fprintf (out, "typedef signed int S16;\n");
		fprintf (out, "typedef unsigned int U16;\n");
		}

	fprintf (out, "/* signed and unsigned 32-bit numbers */\n");
	if (sizeof (int) == 4) {
		fprintf (out, "typedef signed int S32;\n");
		fprintf (out, "typedef unsigned int U32;\n");
		}
	else if (sizeof (long int) == 4) {
		fprintf (out, "typedef signed long int S32;\n");
		fprintf (out, "typedef unsigned long int U32;\n");
		}

	fprintf (out, "/* signed and unsigned 64-bit numbers */\n");
	if (sizeof (long int) == 8) {
		fprintf (out, "typedef signed long int S64;\n");
		fprintf (out, "typedef unsigned long int U64;\n");
		}
	else if (sizeof (long long int) == 8) {
		fprintf (out, "typedef signed long long int S64;\n");
		fprintf (out, "typedef unsigned long long int U64;\n");
		}

	return 0;
}
