#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vetor1{
 int vet[1000];
 int cVet[1000];
 int dVet[1000];
}v1;

struct vetor2{
    int vet[10000];
    int cVet[10000];
    int dVet[10000];
}v2;

struct vetor3{
    int vet[100000];
    int cVet[100000];
    int dVet[100000];
}v3;

struct vetor4{
    int vet[1000000];
    int cVet[1000000];
    int dVet[1000000];
}v4;

int
cres(const int *a, const int *b){
    return *a - *b;
}

int
decres(const int *a, const int *b){
    return *b - *a;
}

void
functVetor(int *vetor, int *cVetor, int *dVetor, int tam){
    int i;

    for(i = 0; i < tam; i++)
        vetor[i] = cVetor[i] = dVetor[i] = rand() % 10000;

    qsort(cVetor, tam, sizeof(int), cres);
    qsort(dVetor, tam, sizeof(int), decres);
}


//BubbleSort
void
bubbleSort(int *vet, int tam){
    int i, j, ax;
    unsigned int atrb = 0, comp = 0;

    for (i = tam - 1; i > 1; i--){
        for (j = 0; j < i; j++){
            comp++;
            if(vet[j] > vet[j+1]){
                ax = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = ax;
                atrb++;
            }
        }
    }

    printf("Comparações: %d\nAtribuições: %d\n", comp, atrb);
}

void
inicBubbleSort(){
    double t1 = 0.0, t2 = 0.0;

    printf("BubbleSort 1.000 posições desordenado: \n");
    t1 = clock();
    bubbleSort(v1.vet, sizeof(v1.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 1.000 posições ordenado crescente: \n");
    t1 = clock();
    bubbleSort(v1.cVet, sizeof(v1.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 1.000 posições ordenado decrescente: \n");
    t1 = clock();
    bubbleSort(v1.dVet, sizeof(v1.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);


    printf("\n\nBubbleSort 10.000 posições desordenado: \n");
    t1 = clock();
    bubbleSort(v2.vet, sizeof(v2.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 10.000 posições ordenado crescente: \n");
    t1 = clock();
    bubbleSort(v2.cVet, sizeof(v2.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 10.000 posições ordenado decrescente: \n");
    t1 = clock();
    bubbleSort(v2.dVet, sizeof(v2.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);


    printf("\n\nBubbleSort 100.000 posições desordenado: \n");
    t1 = clock();
    bubbleSort(v3.vet, sizeof(v3.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 100.000 posições ordenado crescente: \n");
    t1 = clock();
    bubbleSort(v3.cVet, sizeof(v3.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 100.000 posições ordenado decrescente: \n");
    t1 = clock();
    bubbleSort(v3.dVet, sizeof(v3.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);


    printf("BubbleSort 1.000.000 posições desordenado: \n");
    t1 = clock();
    bubbleSort(v4.vet, sizeof(v4.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 1.000.000 posições ordenado crescente: \n");
    t1 = clock();
    bubbleSort(v4.cVet, sizeof(v4.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

    printf("BubbleSort 1.000.000 posições ordenado decrescente: \n");
    t1 = clock();
    bubbleSort(v4.dVet, sizeof(v4.vet) / sizeof(int));
    t2 = clock();
    printf("Tempo: %f\n", (t2 - t1) / CLOCKS_PER_SEC);

}

int
main(){

    functVetor(v1.vet, v1.cVet, v1.dVet, sizeof(v1.vet) / sizeof(int));
    functVetor(v2.vet, v2.cVet, v2.dVet, sizeof(v2.vet) / sizeof(int));
    functVetor(v3.vet, v3.cVet, v3.dVet, sizeof(v3.vet) / sizeof(int));
    functVetor(v4.vet, v4.cVet, v4.dVet, sizeof(v4.vet) / sizeof(int));

    inicBubbleSort();

    return 0;
}
