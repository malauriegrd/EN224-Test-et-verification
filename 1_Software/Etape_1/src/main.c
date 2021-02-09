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


int main (int argc, char * argv []){
	printf("(II) Starting PGCD program\n");
	//test manuel
	int pgcd1 = PGCD(1,1);
	int pgcd2 = PGCD(65535,65535);
	int pgcd3 = PGCD(1, 65535);
	int pgcd4 = PGCD(65535,1);
	int pgcd5 = PGCD(303, 693);
	int pgcd6 = PGCD(36,4);
	int pgcd7 = PGCD(1035, 1931);
	int pgcd8 = PGCD(4950, 340);
	int pgcd9 = PGCD(3425, 210);
	int pgcd10 = PGCD(2032, 3454);
	printf("PGCD1 = %d , PGCD2 = %d , PGCD3 = %d , PGCD4 = %d ,PGCD5 = %d , PGCD6 = %d , PGCD7 = %d , PGCD8 = %d, PGCD9 = %d , PGCD10 = %d \n",pgcd1, pgcd2, pgcd3, pgcd4, pgcd5, pgcd6, pgcd7,pgcd8,pgcd9,pgcd10);
	printf("(II) End of PGCD program\n");
  return 0;
}
