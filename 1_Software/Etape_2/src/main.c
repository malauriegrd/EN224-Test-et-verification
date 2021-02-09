#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAX 65535
#define MIN 1

int PGCD(int A, int B)
{
	while(A != B){
		if(A > B)
			A = A - B;
		else
			B = B - A;
	}
	return A;
}

int RandA ( int A){
	A = MIN + rand() % (MAX + 1 - MIN);
	return A;
}

int RandB (int B){
	B = MIN + rand() % (MAX + 1 - MIN);
	return B;
}

int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");
	//Test semi automatisé
	int cmpt = 0;
	int A;
	int B;
	int pgcd;
	while(cmpt != 20){
		A = RandA(A);
		B = RandB(B);
		pgcd = PGCD(A,B);
		printf("A = %d, B= %d ,PGCD = %d\n", A,B,pgcd);
		cmpt= cmpt +1 ; 
	}

	printf("(II) End of PGCD program\n");
  return 0;
}
