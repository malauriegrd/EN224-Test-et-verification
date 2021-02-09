#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

int PGCD2(int a, int b){
    int val_A_init = a;
	int val_B_init = b;

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

int PGCD(int A, int B){
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
