typedef unsigned char byte;

#define GF_MOD 0x11b
		/* default GF modulus of  x^8 + x^4 + x^3 + x + 1 */
 
byte addGF (byte b1, byte b2);
#define subGF(b1,b2) (addGF (b1, b2))
byte mulGF (byte b1, byte b2);
byte mulGF_m (byte b1, byte b2, int gf_mod);
