#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

// 1 - Entender a codificação do programa
// 2 - Botar a cpu para rodar
// 3 - Ler o texto e decodifiacar em bin

// Definindo as váriaveis necessárias
unsigned int MBR;
unsigned short int MAR;
unsigned short int IBR; // 16 bits //2 Bytes
unsigned char IR;
unsigned short int IMM;
unsigned short int PC; // Ele anda de 32 em 32 bits //4 bytes
unsigned char E, L, G;
unsigned char LR;
unsigned short int A;
unsigned short int B;
unsigned short int T;
unsigned char memoria[154];
int main()
{

    // Seta tudas posições da memoria para iniciarem com 0
    for (int i = 0; i < 154; i++)
    {
        memoria[i] = hlt;
        printf("HELLO WORLD\n");
    }

    /* OPCode tem 5 bits e o resto da instrução tem o endereço de memória

    MBR recebe a palavra de 32 bits
    IBR = MBR && 0xFFFF;
    MBR  = MBR >> 16;
    MAR = MBR && 0x7FF;(mascara para os 11 bits menos significativos) //Não entendi bem essa parte de mascara
    IR = MBR >> 11; //IR recebe o MBR deslocado em 11 bits

    IF's de checagem do OP CODE ex: IF(IR == 0b10011(LDA))

     MBR está ligado diretamente a mémoria ele que pega o endereço/instrução */
    IR = 0b00001;
    while (1)
    {
        // Busca();
        //  Decodifica();
        Executa();

        /*Sempre que o código roda os três ciclos é um ciclo de maquina*/
    }

    return 0;
}
void Busca()
{
    printf("Buscando\n");
    /*Se LR = 0, deve-se buscar uma palavra de instrução de 32 bits, que contém duas instruções de 16 bits cada.*/
}

void Decodifica()
{
    printf("Decodificando\n");
    /*Dessa forma, quando LR = 0, a instrução
da esquerda terá os seus campos divididos em IR, MAR e IMM abaixo durante o estágio de decodificação, seguindo
para a execução, enquanto a instrução à direita apenas é armazenada em IBR.*/
}

void Executa()
{
    printf("Executando\n");
    if (IR == hlt)
    {
        /**/
    }
    else if (IR == nop)
    {
        /**/
        printf("Nao estou fazendo nada\n");
    }
    else if (IR == add)
    {
        A = A + B;
    }
    else if (IR == sub)
    {
        A = A - B;
    }
    else if (IR == mul)
    {
        A = A * B;
    }
    else if (IR == div)
    {
        A = A / B;
    }
    else if (IR == cmp)
    {
        /**/
    }
    else if (IR == xchg)
    {
        /**/
    }
    else if (IR == and)
    {
        A = A && B;
    }
    else if (IR == or)
    {
        A = A || B;
    }
    else if (IR == xor)
    {
        A = A ^ B;
    }
    else if (IR == not )
    {
        A = !A;
    }
    else if (IR == je)
    {
        /**/
    }
    else if (IR == jne)
    {
        /**/
    }
    else if (IR == jl)
    {
        /**/
    }
    else if (IR == jle)
    {
        /**/
    }
    else if (IR == jg)
    {
        /**/
    }
    else if (IR == jge)
    {
        /**/
    }
    else if (IR == jmp)
    {
        /**/
    }
    else if (IR == lda)
    {
        /**/
    }
    else if (IR == ldb)
    {
        /**/
    }
    else if (IR == sta)
    {
        /**/
    }
    else if (IR == stb)
    {
        /**/
    }
    else if (IR == ldrb)
    {
        /**/
    }
    else if (IR == moviaLimm)
    {
        /**/
    }
    else if (IR == moviaHimm)
    {
        /**/
    }
    else if (IR == addiaimm)
    {
        /**/
    }
    else if (IR == subiaimm)
    {
        /**/
    }
    else if (IR == muliaimm)
    {
        /**/
    }
    else if (IR == diviaimm)
    {
    }
    else if (IR == lshimm)
    {
    }
    else if (IR == rshimm)
    {
        /**/
    }
}