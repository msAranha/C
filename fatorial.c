/*
 * File:   newCSimpleTest.c
 * Author: Matheus
 *
 * Created on 27 de Agosto de 2014, 10:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define MEDIA 2

/*
 * Simple C Test Suite
 */

struct data_nascimento {
    int dia, mes, ano;
};

struct tipo_ficha_cadastral {
    char nome[50];
    struct data_nascimento data;
    float notas[MEDIA];
} aluno[N];

struct tempo {
    int tm_sec; /* Segundos, 0-59*/
    int tm_min; /* Minutos, 0-59*/
    int tm_hour; /*Horas 0-23 */
    int tm_mday; /*dia do mês, 1-31 */
    int tm_mon; /* mês a partir de janeiro, 0-11 */
    int tm_year; /* anos a partir de 1900 */

};

int main() {
    struct tempo *local;
    int dia, mes, ano, i, j;

    /*Calculo de data Atual*/
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    ano = local->tm_year + 1900;

    for (i = 0; i < N; i++) {
        setbuf(stdin, NULL);
        puts("Informe nome do aluno: ");
        gets(aluno[i].nome);
        puts("Informe data de nascimento[DD/MM/AAAA]: ");
        scanf("%d%d%d", &aluno[i].data.dia, &aluno[i].data.mes, &aluno[i].data.ano);
        for (j = 0; j < MEDIA; j++) {
            printf("Informe %d° nota: ", j + 1);
            scanf("%f", &aluno[i].notas[j]);
        }//endfor
        system("cls");
    }//endfor

    /*Idade Aluno*/
    printf("##### IDADE ALUNOS #####\n");
    for (i = 0; i < N; i++) {
        printf("Aluno: %s\nIdade: %d\n", aluno[i].nome, ano - aluno[i].data.ano);
    }//endfor

    /*Média Aluno*/
    printf("\n\n##### MÉDIA ALUNOS #####\n");
    for (i = 0; i < N; i++) {
        printf("Aluno: %s\nMédia: %.2f\n", aluno[i].nome, (aluno[i].notas[0] + aluno[i].notas[1]) / MEDIA);
    }//endfor

    /*Alunos final*/
    printf("\n\n##### ALUNOS FINAL #####\n");
    for (i = 0; i < N; i++) {
        if (((aluno[i].notas[0] + aluno[i].notas[1]) / MEDIA) >= 4.00 && ((aluno[i].notas[0] + aluno[i].notas[1]) / MEDIA) <= 7) {
            printf("Nome: %s", aluno[i].nome);
        }//endif
    }//endfor

    system("pause");
    return 0;
}