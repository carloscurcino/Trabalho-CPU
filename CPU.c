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
    }

    return 0;
}
void Busca()
{
    printf("Buscando\n");
}

void Decodifica()
{
    printf("Decodificando\n");
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
        /**/
    }
    else if (IR == div)
    {
        /**/
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
        /**/
    }
    else if (IR == or)
    {
        /**/
    }
    else if (IR == xor)
    {
        /**/
    }
    else if (IR == not )
    {
        /**/
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