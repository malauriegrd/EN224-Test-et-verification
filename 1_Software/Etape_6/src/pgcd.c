#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>

int PGCD2(int a, int b){
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
    return x;
}

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

int main(){
    
    assert(PGCD(0,0)==0);
    assert(PGCD(0,2010) == 2010);
    assert(PGCD(10032,0)==10032);
    assert(PGCD(1,65535)==1);
    assert(PGCD(655535,1)==1);
    assert(PGCD(65535,65535)==65535);
    assert(PGCD(10235,230)==115);
    
    assert(PGCD2(0,0)==0);
    assert(PGCD2(0,2010) == 2010);
    assert(PGCD2(10032,0)==10032);
    assert(PGCD2(1,65535)==1);
    assert(PGCD2(655535,1)==1);
    assert(PGCD2(65535,65535)==65535);
    assert(PGCD2(10235,230)==115);

    return 1;
}