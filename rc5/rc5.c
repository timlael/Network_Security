#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int WORD;     /*32-bit/ 4 byte word*/
#define RC5_WORD     unsigned int
#define KEY_BYTES 8
#define ROUNDS 12
#define WORD_LENGTH 32
#define Pw 0xb7e15163
#define Qw 0x9e3779b9
#define ROTL(x,y) (((x)<<(y&(WORD_LENGTH-1))) | ((x)>>(WORD_LENGTH-(y&(WORD_LENGTH-1)))))
#define ROTR(x,y) (((x)>>(y&(WORD_LENGTH-1))) | ((x)<<(WORD_LENGTH-(y&(WORD_LENGTH-1)))))
#define WW 4
#define LL 11/4
#define c 2

typedef unsigned char uchar;
typedef unsigned long ulong;



void encryption(ulong A, ulong B, ulong *C, ulong *D, ulong *S){
  	int i, i2;
    A += S[0];
  	B += S[1];
  	for (i = 1; i <= ROUNDS; i++) {
    	i2 = i * 2;
   	A = ROTL(A^B, B)+S[2*i];
		B = ROTL(B^A, A)+S[2*i+1];
  	}
  	*C = A, *D = B;
}



void decryption(ulong A, ulong B, ulong *C, ulong *D, ulong *S){
  	int i, i2;
    for (i = ROUNDS; i >= 1; i--) {
    	i2 = i * 2;
		B = ROTR(B - S[2*i+1], A) ^A;
		A = ROTR(A - S[2*i], B) ^B;
  	}
  	*C = A - S[0], *D = B - S[1];
}

void setup(uchar *key, ulong *S){
  int i, j, m, s, t;
  RC5_WORD    L[256/WW];
  RC5_WORD    A, B;

  for (i = 0; i < LL; i++)
		L[i] = 0;
  	for (i = 0 ; i < 8 ; i++)  {
        t = (S[i] & 0xFF) << (8*(i%4));
        L[i/WW] = L[i/WW] + t;
    }
  	S[0] = Pw;
  	for (i = 1; i <= 2 * ROUNDS + 1; i++)
    	S[i] = S[i - 1] + Qw;
  	i = j = 0, A = B = 0, m = 2 * ROUNDS + 2, t;
  	for (s = 1; s <= 3 * t; s++) {
    		S[i] = ROTL(S[i]+(A+B), 3);
    		A = S[i];
    		i = (i + 1) % m;
    		L[j] = ROTL(L[j]+(A+B), (A+B));
    		B = L[j];
    		j = (j + 1) % c;
  	}
}

int main(int argc, char *argv[]){
  	uchar key[KEY_BYTES], text[8];
  	ulong A, B, C, D, E, F;
  	ulong S[2 * ROUNDS + 2];
  	const char *keyin, *textin;
	  size_t count = 0;


    if(argc !=3){
  		printf("usage: %s key plaintext\n", argv[0]);
  	}
    else{
        keyin = argv[1];
		    for(count = 0; count < sizeof(key)/sizeof(key[0]); count++) {
        	sscanf(keyin, "%2hhX", &key[count]);
        	keyin += 2 * sizeof(char);
    	   }
	      textin = argv[2];
		    for(count = 0; count < sizeof(text)/sizeof(text[0]); count++) {
        	sscanf(textin, "%s", &text[count]);
        	textin += 2 * sizeof(char);
    	   }
         A = (unsigned long)text[3]<<24|(unsigned long)text[2]<<16|(unsigned long)text[1]<<8|(unsigned long)text[0];
         B = (unsigned long)text[7]<<24|(unsigned long)text[6]<<16|(unsigned long)text[5]<<8|(unsigned long)text[4];

    setup(key, S);
  	encryption(A, B, &C, &D, S);
  	printf("%8x %8x\n", C, D);
  	decryption(C, D, &E, &F, S);
  	printf("%8x %8x\n", E, F);
    }
  	return 0;
}
