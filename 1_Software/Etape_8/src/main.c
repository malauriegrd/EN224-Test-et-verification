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
    
	printf("(II) Starting PGCD program\n");
	//Test semi automatisé
	int cmpt_OK = 0;
	FILE* fichA = fopen("ref_A.txt","r");
	FILE* fichB = fopen("ref_B.txt","r");
	FILE* fichC = fopen("resul_C.txt","w");
	if(fichA == NULL){
		printf("erreur ouverture fichierA\n");
		exit( EXIT_FAILURE);
	}
	if(fichB == NULL){
		printf("erreur ouverture fichierA\n");
		exit(EXIT_FAILURE);
	}

	int A;
	int B;
	int pgcd, pgcd2;
	int cmpt_err = 0;
	while((feof(fichA)==0) && (feof(fichB)==0)){
		char toto[128];
		fscanf(fichA,"%d",&A);
		fscanf(fichB,"%d",&B);

		pgcd = PGCD(A,B);
		/*if(rand()%128==0)
		{
			pgcd+=1;
		}*/
		fprintf(fichC,"%d\n",pgcd);
	}
	printf("(II) End of PGCD program\n");
  return 0;
}
