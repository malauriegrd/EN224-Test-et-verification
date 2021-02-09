#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
TEST_CASE("PGCD cas general","[PGCD]"){
	SECTION ("A>B"){
		REQUIRE(PGCD(65535,1)==1);
		REQUIRE(PGCD(10235,230)==115);
		REQUIRE(PGCD(36,4)==4);
		REQUIRE(PGCD(3425, 210)==5);
		REQUIRE(PGCD(4950, 340)==10);
	}
	SECTION("A<B"){
		REQUIRE(PGCD(1,65535)==1);
		REQUIRE(PGCD(303, 693)==3);
		REQUIRE(PGCD(1035, 1931)==1);
		REQUIRE(PGCD(2032, 3454)==2);
	}
	SECTION("A=B"){
		REQUIRE(PGCD(65535,65535)==65535);
    	REQUIRE(PGCD(4022,4022)==4022);
    	REQUIRE(PGCD(5,5)==5);
	}
	SECTION ("A>B"){
		REQUIRE(PGCD2(65535,1)==1);
		REQUIRE(PGCD2(10235,230)==115);
		REQUIRE(PGCD2(36,4)==4);
		REQUIRE(PGCD2(3425, 210)==5);
		REQUIRE(PGCD2(4950, 340)==10);
	}

	SECTION ("A<B"){
		REQUIRE(PGCD2(1,65535)==1);
		REQUIRE(PGCD2(303, 693)==3);
		REQUIRE(PGCD2(1035, 1931)==1);
		REQUIRE(PGCD2(2032, 3454)==2);
	}

	SECTION ("A=B"){
		REQUIRE(PGCD2(65535,65535)==65535);
		REQUIRE(PGCD2(4022,4022)==4022);
		REQUIRE(PGCD2(5,5)==5);
	}
}

TEST_CASE("PGCD cas particulier","[PGCD]"){
	SECTION ("A>B"){
		REQUIRE(PGCD(10032,0)==10032);
		REQUIRE(PGCD(0,2010) == 2010);
		REQUIRE(PGCD(0,0)==0);
	}
	SECTION ("A<B"){
    	REQUIRE(PGCD2(10032,0)==10032);
		REQUIRE(PGCD2(0,2010) == 2010);
	}
	SECTION ("A=B"){
		REQUIRE(PGCD2(0,0)==0);
	}
}
//#define _usefull_
#ifdef _usefull_
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
#endif
