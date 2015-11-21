/*
    Exercicio Programação I - Ciência da Computação UESPI 07/04/2014
    Matheus Aranha Silva
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define hPreco 2.50
#define mPreco 0.04166


int main(){

    int h, min,
        hmEntrada, hmSaida,
        hTotal;
    float hFinal, mFinal,
          hValor, mValor, vTotal;


    printf("[Entrada]\nHora: ");
    scanf("%d", &h);
    printf("Minutos: ");
    scanf("%d", &min);
    hmEntrada = h * 60 + min;  //Transforma toda em entrada em minutos

    printf("\n[Saida]\nHora: ");
    scanf("%d", &h);
    printf("Minutos: ");
    scanf("%d", &min);
    hmSaida = h * 60 + min;   //Transforma toda em entrada em minutos

    if (hmSaida > 720)
        hmSaida -= 720;    //Transforma formato de hora em formato Americano caso passe de 12h; Mesmo digitando 22:00 ele transforma em 10:00
    if (hmEntrada > 720)
        hmEntrada -= 720;  //Transforma formato de hora em formato Americano caso passe de 12h; Mesmo digitando 22:00 ele transforma em 10:00

    if (hmEntrada >= hmSaida){
        hmSaida += 720;
        hTotal = hmSaida - hmEntrada;  //Se a hora de entrada for maior ou igual a hora de saida ele acrescenta mais 12horas no horário de saida e subtrai do horário de entrada, trantando o erro apresentado em sala de aparecer um valor diferente
    }else{
        hTotal = hmSaida - hmEntrada;
    }



    //Calculos - Tempo, Valor a pagar
    hFinal = hTotal / 60;
    mFinal = hTotal % 60;

    hValor = hFinal * hPreco;
    if(mFinal < 15){
        mValor = 0;   //Se o cliente passar menos de quinze minutos no estacionamento não é cobrado nada.
    }else{
        mValor = mFinal * mPreco;
    }
    vTotal = hValor + mValor;



    system("cls");



    //Saida de dados
    printf("|-----------------------------------------------|\n|\t\tRECIBO ESTACIONAMENTO\t\t|\n|\t\t E  M  P  R  E  S  A\t\t|\n|-----------------------------------------------|\n|\t\t\t\t\t\t|\n|"); //Layout Recibo
    if(mFinal == 0){
        printf(" Tempo total: %.0fH\t\t\t\t|", hFinal);
    }else {
        printf(" Tempo total: %.0f:%.0fmin\t\t\t\t|", hFinal, mFinal);
    }

    printf("\n| Total: R$%.2f\t\t\t\t\t|", vTotal);

    if(hTotal > 240){
        printf("\n| Lavagem gratis: [X]SIM  [ ]NAO\t\t|");
    }else{
        printf("\n| Lavagem gratis: [ ]SIM  [X]NAO\t\t|");
    }
    printf("\n|\t\t\t\t\t\t|\n|\t\t\t\t\t\t|\n|-----------------------------------------------|\n|\t   Obrigado pela preferencia\t\t|\n|\t\t Volte Sempre\t\t\t|\n|-----------------------------------------------|\n"); //Layout Recibo



    getch();
    return 0;
}