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
unsigned char MEM[154];

void prtMemoria()
{ // printa a memoria
    for (int i = 0; i < 154; i++)
    {
        printf("%02d: \t0x%X\t", i, MEM[i]); // MOSTRA A POSIÇÃO E O VALOR ARMAZENADO NESSA POSIÇÃO EM HEX
        if (i > 0 && (i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
}
void mostraStatus()
{
    printf("CPU:\n");
    printf("A:\t0x%X \tB:\t0x%X \tT:\t0x%X \n", A, B, T);
    printf("MBR:\t0x%X \tMAR:\t0x%X \tIMM:\t0x%X \n", MBR, MAR, IMM);
    printf("PC:\t0x%X \tIR:\t0x%X \tLR:\t0x%X \n", PC, IR, LR);
    printf("E:\t0x%X \tL:\t0x%X \tG:\t0x%X \n", E, L, G);

    printf("\nMEMORIA:\n");
    prtMemoria();
}

int main()
{

    // Seta tudas posições da memoria para iniciarem com 0
    for (int i = 0; i < 154; i++)
    {
        MEM[i] = hlt;
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
    mostraStatus();
    // while (1)
    // {
    //     Busca();
    //     Decodifica();
    //     Executa();

    //     /*Sempre que o código roda os três ciclos é um ciclo de maquina*/
    //     /*Deve imprimir as informações de registradores tem o exemplo de como deve ser feito esse output*/
    // }

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