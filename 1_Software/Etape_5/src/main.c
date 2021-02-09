#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

#define MAX 65535

int PGCD2(int a, int b){
	int val_A_init = a;
	int val_B_init = a;

	assert(val_A_init>=0);
	assert(val_A_init<=65535);
	assert(val_B_init>=0);
	assert(val_B_init<=65535);

    int r,x,y;
	if(a ==0)
		return b;

	if(b==0)
		return a;
	
	if(b==0 && a ==0 )
		return 0;
	
    if (a>b){
        x=b;
        r=a%b;
    }else{
    	x=a;
        r=b%a;
    }
    while(r!=0){
		y=x;
        x=r;
        r=y%x;          
    }
	
	assert(x>=0);
	assert(x<=val_A_init);
	assert(x<=val_B_init);
	int restA = val_A_init%x;
	int restB = val_B_init %x;
	assert(restA==0);
	assert(restB==0);
    
	return x;
}

int PGCD(int A, int B)
{
	int val_A_init = A;
	int val_B_init = B;

	assert(val_A_init>=0);
	assert(val_A_init<=65535);
	assert(val_B_init>=0);
	assert(val_B_init<=65535);
	
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
	assert(A>=0);
	assert(A<=val_A_init);
	assert(B<=val_B_init);
	int restA = val_A_init%A;
	int restB = val_B_init %B;
	assert(restA==0);
	assert(restB==0);

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
