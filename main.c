#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

/*Implemente a seguinte função. A função deve imprimir os valores que estão no buffer passado por parâmetro.
Os valores estão intercalados na seguinte ordem: int, float, double.
A variável nTotal indica o total de trios (int, float e double) no buffer.*/

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
int *aux;
float *aux2;
double *aux3;
srand(time(NULL));

 for(int i=0; i<nTotal; i++){
int a =0;
    aux = (int*)pBuffer;
    printf("int:%d\n", *aux);

    aux2 = (float*)pBuffer + 1;
    printf("float:%f\n", *aux2);

    aux3 = (double*) aux2 + 1;
    printf("double:%lf\n", *aux3);

    printf("\n\n");

    //if(a>0){
    pBuffer = pBuffer + sizeof(int) + sizeof(float) + sizeof(double);
    //} a++;
 }
}


int main(){

int nTotal;
void *pBuffer;
int *a;
float *b;
double *c;

printf("Digite o valor de nTotal:\n");
scanf("%d", &nTotal);

pBuffer = realloc(NULL, sizeof(int)) + (sizeof(float)) + (sizeof(double));

for(int i=0; i<nTotal; i++){

    a = (int*)pBuffer;
    *a = rand()%99;

    b = (float*)a + 1;
    *b = rand()%99;

    c = (double*)b + 1;
    *c = rand()%99;

   // pBuffer = pBuffer + sizeof(int) + sizeof(float) + sizeof(double);
   pBuffer = pBuffer + (sizeof(int) + sizeof(float) + sizeof(double));

}

imprimeBuffer(pBuffer, nTotal);



return 0;
}
