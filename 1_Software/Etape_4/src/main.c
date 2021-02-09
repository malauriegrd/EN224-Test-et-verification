#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

#define MAX 65535
#define MIN 1

int PGCD(int A, int B)
{
	assert(B != 0);
	assert(A !=0);
	while(A != B){
		if(A > B)
			A = A - B;
		else
			B = B - A;
	}
	return A;
}


int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");
	//test manuel
	assert(PGCD(1,1)==1);
	assert(PGCD(65535,65535)==65535);
	assert(PGCD(1, 65535)==1);
	assert(PGCD(65535,1)==1);
	assert(PGCD(303, 693)==3);
	assert(PGCD(36,4)==4);
	assert(PGCD(1035, 1931)==1);
	assert(PGCD(4950, 340)==10);
	assert(PGCD(3425, 210)==5);
	assert(PGCD(2032, 3454)==2);
	//printf("PGCD1 = %d , PGCD2 = %d , PGCD3 = %d , PGCD4 = %d ,PGCD5 = %d , PGCD6 = %d , PGCD7 = %d , PGCD8 = %d, PGCD9 = %d , PGCD10 = %d \n",pgcd1, pgcd2, pgcd3, pgcd4, pgcd5, pgcd6, pgcd7,pgcd8,pgcd9,pgcd10);
	printf("(II) End of PGCD program\n");
  return 0;
}
