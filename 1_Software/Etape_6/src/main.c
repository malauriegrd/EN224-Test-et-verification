#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

#include "pgcd.h"

#define MAX 65535

int RandA ( int A){
	A = rand() % (MAX + 1);
	return A;
}

int RandB (int B){
	B = rand() % (MAX + 1 );
	return B;
}


int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");
	//Test semi automatisé
	int cmpt_OK = 0;
	int A;
	int B;
	int pgcd, pgcd2;
	int cmpt_err = 0;
	for(int i =0; i<65536; i++){
		A = RandA(A);
		assert(A>=0);
		assert(A<=65535);
		
		B = RandB(B);
		assert(B>=0);
		assert(B<=65535);

		pgcd = PGCD(A,B);
		pgcd2 = PGCD2(A,B);
		
		if(pgcd!=pgcd2){
			printf("A = %d, B= %d ,PGCD1 = %d,  PGCD2 = %d \n", A,B,pgcd,pgcd2);
			cmpt_err = cmpt_err +1;
		}else
			cmpt_OK= cmpt_OK +1 ; 
	}
	printf("couple pgcd OK = %d, couple pgcd KO = %d\n", cmpt_OK, cmpt_err);
	printf("(II) End of PGCD program\n");
  return 0;
}
