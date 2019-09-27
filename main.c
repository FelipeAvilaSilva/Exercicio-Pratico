#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

/*Implemente a seguinte função. A função deve imprimir os valores que estão no buffer passado por parâmetro.
Os valores estão intercalados na seguinte ordem: int, float, double.
A variável nTotal indica o total de trios (int, float e double) no buffer.*/

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
    int *aux, prox = 0;
    float *aux2;
    double *aux3;
    srand(time(NULL));

        for(int i=0; i<nTotal; i++){

            aux = (int*)pBuffer + prox;
            printf("int:%d\n", *aux);

            aux2 = (float*)aux + 1;
            printf("float:%f\n", *aux2);

            aux3 = (double*) aux2 + 1;
            printf("double:%lf\n", *aux3);

            prox = prox + nTotal + 1;

            printf("\n\n");
        }
}

int main(){

    int nTotal;
    void *pBuffer;
    int *a, prox = 0;
    float *b;
    double *c;

    printf("Digite o valor de nTotal:\n");
    scanf("%d", &nTotal);

    pBuffer = realloc(NULL, sizeof(int)) + (sizeof(float)) + (sizeof(double));

    for(int i=0; i<nTotal; i++){
        a = (int*)pBuffer + prox;
        *a = rand()%10;

        b = (float*)a + 1;
        *b = rand()%10*10;

        c = (double*)b + 1;
        *c = rand()%10*20;

        prox = prox + nTotal + 1;
    }
    imprimeBuffer(pBuffer, nTotal);
}
