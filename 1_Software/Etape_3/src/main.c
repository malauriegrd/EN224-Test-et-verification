#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAX 65535
#define MIN 0

int PGCD2(int a, int b){
      int r,x,y;
      if (a>b){
          x=b;
          r=a%b;
      }
      else{
          x=a;
          r=b%a;
      }
      while(r!=0){
        y=x;
        x=r;
        r=y%x;          
      }
      return x;
}

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
	int pgcd, pgcd2;
	while(cmpt != 65536){
		A = RandA(A);
		B = RandB(B);
		pgcd = PGCD(A,B);
		pgcd2 = PGCD2(A,B);
		if(pgcd!=pgcd2){
			EXIT_FAILURE;
		}
			//printf("A = %d, B= %d ,PGCD1 = PGCD2 = %d \n", A,B,pgcd2);
		cmpt= cmpt +1 ; 
	}
	printf("Tout est Ok \n");
	printf("(II) End of PGCD program\n");
  return 0;
}
