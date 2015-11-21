#include <stdio.h>
#include <locale.h>

int main (){
    setlocale (LC_ALL, "Portuguese");
    int n, aux = 0;

    printf("Insira um número: ");
    scanf("%d", &n);

    if (n > 0){
        for (int i = 2; i < n / 2; i++)
            if (n % i == 0)
                aux = 1;

        if (n == 1)
            printf("Não primo");
        else
            (aux == 0) ? printf("Primo") : printf("Não primo");

    }else{
        printf ("Informe um número natural");
    }

    return 0;
}