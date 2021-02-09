#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAX 65535
#define MIN 1

int PGCD(int A, int B)
{
	if(A ==0){
		return B;
	}
	if(B==0){
		return A;
	}
	if(B==0 && A ==0 ){
		A = 0;
	}

	while(A != B){
		if(A > B)
			A = A - B;
		else
			B = B - A;
	}
	return A;
}

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
	int cmpt = 0;
	int A;
	int B;
	int pgcd;
	for(int i =0; i<200; i++){
		A = RandA(A);
		B = RandB(B);
		pgcd = PGCD(A,B);
		printf("A = %d, B= %d ,PGCD = %d\n", A,B,pgcd);
		cmpt= cmpt +1 ; 
	}

	printf("(II) End of PGCD program\n");
  return 0;
}
