#include <stdio.h>
void displayBits (unsigned value); //protótipo da função
int main(void) {
    unsigned x;
    printf("Digite um inteiro sem sinal: ");
    scanf("%u", &x);
    displayBits(x); //chama a função
    return 0;
}
//função: mostra bits de um valor inteiro sem sinal
void displayBits(unsigned value) {
    unsigned c; //contador
//declara displayMask e desloca 31 bits à esquerda
    unsigned displayMask = 1 << 31;
    printf("%10u = ", value);
    //percorre os bits
    for(c=1; c<=32; c++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; //desloca valor à esquerda em 1
        if( c%8 == 0) { //gera espaço após 8 bits
            putchar(' ');
        }
    }
    putchar('\n');
}