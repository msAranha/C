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

void
quickSort(int *vetor, int left, int rigth, int *c, int *t){

   int i, j, ax, pivot;

   i = left, j = rigth;
   pivot = vetor[(int) ((i + j) / 2)];

   while(i <= j){
      (*c)++;

      while (vetor[i] < pivot)
            i++;

      while (vetor[j] > pivot)
            j--;

      if(i <= j){
         ax = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = ax;
         i++;
         j--;
         (*t)++;
      }
   };

   if(left < j)
        quickSort(vetor, left, j, c, t);
   if(i < rigth)
        quickSort(vetor, i, rigth, c, t);
}

void
inicQuickSort(){
    int comp, troc;
    float t1 = 0.0, t2 = 0.0;

    printf("\n\nQuikSort - 1.000 posições [DESORDENADO]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v1.vet, 0, ( sizeof(v1.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 1.000 posições [ORDENADO CRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v1.cVet, 0, ( sizeof(v1.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 1.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v1.dVet, 0, ( sizeof(v1.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);


    printf("\n\nQuikSort - 10.000 posições [DESORDENADO]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v2.vet, 0, ( sizeof(v2.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 10.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v2.cVet, 0, ( sizeof(v2.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 10.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v2.dVet, 0, ( sizeof(v2.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);


    printf("\n\nQuikSort - 100.000 posições [DESORDENADO]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v3.vet, 0, ( sizeof(v3.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 100.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v3.cVet, 0, ( sizeof(v3.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 100.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v3.dVet, 0, ( sizeof(v3.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);


    printf("\n\nQuikSort - 1.000.000 posições [DESORDENADO]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v4.vet, 0, ( sizeof(v4.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 1.000.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v4.cVet, 0, ( sizeof(v4.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

    printf("QuikSort - 1.000.000 posições [ORDENADO DECRESCENTE]:\n");
    comp = 0, troc = 0;
    t1 = clock();
    quickSort(v4.dVet, 0, ( sizeof(v4.vet) / sizeof(int)) - 1, &comp, &troc );
    t2 = clock();
    printf("Comparações: %d\nTrocas: %d\nTempo: %f ms\n", comp, troc, (t2 - t1) *1000 / CLOCKS_PER_SEC);

}

int
main(){

    functVetor(v1.vet, v1.cVet, v1.dVet, sizeof(v1.vet) / sizeof(int));
    functVetor(v2.vet, v2.cVet, v2.dVet, sizeof(v2.vet) / sizeof(int));
    functVetor(v3.vet, v3.cVet, v3.dVet, sizeof(v3.vet) / sizeof(int));
    functVetor(v4.vet, v4.cVet, v4.dVet, sizeof(v4.vet) / sizeof(int));

    inicQuickSort();

    return 0;
}
