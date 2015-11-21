#include <stdio.h>
#include <conio.h>
#include <locale.h>

#define INI 0
#define FIM 10

/* QuickSort, ordenar vetor*/
void Quick(int vet[FIM], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vet[meio];

   do{
      while (vet[i] < pivo) i = i + 1;
      while (vet[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) Quick(vet, inicio, j);
   if(i < fim) Quick(vet, i, fim);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int vet[FIM],
        x,
        ini, meio, fim;

    //Inserir dados no vetor
    for (int i=0;i<FIM;++i){
        printf("Insira um numero: ");
        scanf("%d", &vet[i]);
    }

    //Ordena o vetor
    Quick(vet, INI, FIM - 1);

    //Mostra vetor Ordenado
    printf("\n\nVetor Ordenado: \n");
    for(int i=0;i<FIM;++i){
        printf("%d ", vet[i]);
    }

    //Solicita ao usuário para inserir um número
    printf("\n\nInforme um numero para achar a posicao: ");
    scanf("%d", &x);

    ini = 0;
    fim = FIM-1;

    //Inicio do método de busca binária
    do{
        if(ini > fim){
            printf("Número não encontrado.");
            break;
        }
        meio = (ini + fim)/2;
        if(x == vet[meio]){
            printf("Número encontrado na posição: %d", meio + 1);
            break;
        }
        else if(x < vet[meio])
            fim = meio-1;
        else
            ini = meio+1;
    }while(1);

    return 0;
}