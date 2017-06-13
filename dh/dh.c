#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>



unsigned long dh(unsigned long generator, unsigned int exponent, unsigned long prime);
int isPrime (unsigned long n);

int main(int argc, char *argv[]){
      FILE *out_file = fopen("dh_out.txt", "a");
      freopen( "stderr.log", "a", stderr );

      unsigned long p;         	//prime
      unsigned long g;          	//generator
      unsigned long pr;			//partial result
      unsigned long B;         	//shared secret
      unsigned long A;         	//generated partial secret
      unsigned int a;           		//exponent

	  /*to calculate shared public keys we need A=(g^a)%p and B=(g^b)%p */
	  /*to calculate shared private keys we need Keya = (B^a)%p and Keyb = (A^b)%p */



      if(argc <2){
    		printf("usage: %s exponent input_file\n", argv[0]);
    	}
      else{
        a = atoi(argv[1]);

          fscanf(stdin,"%lu %lu %lu [^ \t \n]%*c", &p, &g, &pr);		//read in prime, generator and partial result from stdin
            /*fprintf(out_file, "Exponent passed: %i \n", a);           //initial input tests
            fprintf(out_file, "Prime passed: %lu \n", p);               //initial input tests
            fprintf(out_file, "Generator passed: %lu \n", g);*/         //initial input tests

		 if (isPrime(p) != 1){                                          //check to see if prime is indeed prime
		 printf("Prime %lu is not prime\n", p);                        	//since testing/piping input passes non-prime numbers
		 }                                                              // no action is taken when detected

		 if (isPrime(g) != 1){                                          //check to see if generator is prime
		 printf("Generator %lu is not prime\n", g);                    	//since testing/piping input passes non-prime numbers
		 }                                                              // no action is taken when detected


      		A = dh(g, a, p);                                            //generate partial secret to exchange
			B = dh(pr, a, p);                                           //calculate shared secret using partial result from other side
			pr = A;                                           			//store partial secret to partial result to be passed

			fprintf(out_file, "%lu %lu %lu\n", p, g, pr);         		//prime, generator and generated partial secret to standard output
   			fprintf(stderr, "%lu \n", B);                        		//output shared secret to standard error

            return 0;
          }
}

unsigned long dh(unsigned long generator, unsigned int exponent, unsigned long prime){    //meat and potatoes
  unsigned long temp;
  if ( exponent == 0){                                                                //no zero exponents allowed
    printf("Error. Zero is a silly exponent to pick.\n");
    return 0;
  }
  if ( exponent == 1){
    return generator%prime;                                                           //exponent 1 is simple case
  }
  // using modulus math rules... (a*b)%c == ((a%c)*(b%c))%c
  temp=((generator%prime)*(dh( generator, exponent-1, prime)))%prime;                 //recursively iterate through using distributive laws
  return temp;
}

int isPrime(unsigned long n){                                   // Function to check if number is prime
	 int t;
	 for(t=2; t < n; t++){
        if(n%t!=0)
           return 1;
        else
           return 0;
     }
}
