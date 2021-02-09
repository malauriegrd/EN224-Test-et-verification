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
	//test unitaire    
    assert(PGCD(0,0)==0);
    assert(PGCD(0,2010) == 2010);
    assert(PGCD(10032,0)==10032);
    assert(PGCD(1,65535)==1);
    assert(PGCD(65535,1)==1);
    assert(PGCD(65535,65535)==65535);
    assert(PGCD(10235,230)==115);
	assert(PGCD(303, 693)==3);
	assert(PGCD(36,4)==4);
	assert(PGCD(1035, 1931)==1);
	assert(PGCD(4950, 340)==10);
	assert(PGCD(3425, 210)==5);
	assert(PGCD(2032, 3454)==2);
    
    assert(PGCD2(0,0)==0);
    assert(PGCD2(0,2010) == 2010);
    assert(PGCD2(10032,0)==10032);
    assert(PGCD2(1,65535)==1);
    assert(PGCD2(65535,1)==1);
    assert(PGCD2(65535,65535)==65535);
    assert(PGCD2(10235,230)==115);
	assert(PGCD2(303, 693)==3);
	assert(PGCD2(36,4)==4);
	assert(PGCD2(1035, 1931)==1);
	assert(PGCD2(4950, 340)==10);
	assert(PGCD2(3425, 210)==5);
	assert(PGCD2(2032, 3454)==2);
    
	printf("(II) Starting PGCD program\n");
	//Test semi automatisé
	int cmpt_OK = 0;
	int A;
	int B;
	int pgcd, pgcd2;
	int cmpt_err = 0;
	for(int i =0; i<65536; i++){
		A = RandA(A);
		B = RandB(B);
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
