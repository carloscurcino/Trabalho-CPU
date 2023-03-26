#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
//  SETANDO AS VARIÁVEIS GLOBAIS
unsigned short int PC = 0x0000;        // program counter
unsigned int MBR = 0x0000000000000000; // memory buffer register
unsigned short int MAR = 0x0000;       // memory address register
unsigned char IR = 0x00;               // instruction register
unsigned short int IMM = 0x0000;
unsigned short int IBR = 0x0000; // instruction buffer register
unsigned short int AC = 0x0000;
unsigned char E, L, G;         // accumulator register
unsigned char LR = 0x00;       // Flag Left/Right
unsigned char MEM[154];        // memory
unsigned short int A = 0x0000; // Registe A
unsigned short int B = 0x0000; // Registe B
unsigned short int T;

void busca()
{
    if (LR == 0)
    {
        MAR = PC;
        MBR = MEM[MAR]; // RESULTADO 98
        MAR++;          // MAR = 41
        MBR = MBR << 8;
        MBR = MBR | MEM[MAR]; // RESULTADO 9880
        MAR++;                // MAR = 42
        MBR = MBR << 8;
        MBR = MBR | MEM[MAR]; // RESULTADO 9880A0
        MAR++;                // MAR = 43
        MBR = MBR << 8;
        MBR = MBR | MEM[MAR]; // RESULTADO 9880A082
        // printf("\n MBR na busca e %x \n", MBR);
    }
}
void decodifica()
{
    if (LR == 0)
    {
        printf("\n decodificando uma tarefa left \n");
        IBR = MBR & 0xFFFF;
        MBR = MBR >> 16;
        MAR = MBR & 0X7FF;
        IR = MBR >> 11;
    }
    else
    {
        printf("\n decodificando uma tarefa right \n");
        MAR = IBR & 0X7FF;
        IR = IBR >> 11;
        if (IR != hlt)
            PC += 4;
    }
}
void executa()
{
    if (IR == hlt)
    {
        // Faz nada
    }
    else if (IR == nop)
    {
        PC += 4;
        mudaLR();
    }
    else if (IR == add)
    {
        A = A + B;
        mudaLR();
    }
    else if (IR == sub)
    {
        A = A - B;
        mudaLR();
    }
    else if (IR == mul)
    { // mul
        A = A * B;
        printf("\n mul registradores, valor = %d \n", A);
        mudaLR();
    }
    else if (IR == div)
    {
        A = A / B;
        mudaLR();
    }
    else if (IR == lda)
    { // LDA
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        A = MBR & 0xFFFF;
        printf("\n usando o registrador A = %d \n", A);
        mudaLR();
    }
    else if (IR == ldb)
    { // LDB
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        B = MBR & 0xFFFF;
        printf("\n usando o registrador B = %d \n", B);
        mudaLR();
    }
    else if (IR == cmp)
    {
        if (A == B)
        {
            E = 1;
        }
        else
            E = 0;
        if (A < B)
        {
            L = 1;
        }
        else
            L = 0;
        if (A > B)
        {
            G = 1;
        }
        else
            G = 0;
        mudaLR();
    }
    else if (IR == je)
    {
        if (E == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jne)
    {
        if (E == 0)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jl)
    {
        if (L == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jle)
    {
        if (L == 1 || E == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jg)
    {
        if (G == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jge)
    {
        if (G == 1 || E == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jmp)
    {
        PC = MAR;
        mudaLR();
    }
    if (IR == sta)
    {
        MEM[MAR] = A >> 8;
        printf("%o", MAR);
        MEM[MAR] = A & 0xFF;
        printf("%u", MAR);
        mudaLR();
    } // M[X] 0b10101 STORE A: armazena em uma palavra de 16 bits que começa a partir do endereço de memória X o conteúdo do registrador A.
    if (IR == stb)
    {
        MEM[MAR] = B >> 8;
        MEM[MAR++] = B & 0xFF;
        mudaLR();
    } // M[X] 0b10110 STORE B: armazena em uma palavra de 16 bits que começa a partir do endereço de memória X o conteúdo do registrador B.
}
void setMemoria()
{ // inicializa a memoria
    for (int i = 0; i < 154; i++)
        MEM[i] = hlt;
}
void prtMemoria()
{ // printa a memoria
    printf("\nMEMORIA:\n");
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
    printf("PC:\t%d \tIR:\t0x%X \tLR:\t0x%X \n", PC, IR, LR);
    printf("E:\t0x%X \tL:\t0x%X \tG:\t0x%X \n", E, L, G);

    prtMemoria();
}
void mudaLR()
{
    LR = !LR;
}
int main()
{
    setMemoria();
    PC = 40;
    MEM[40] = 0x98;
    MEM[41] = 0x80; // lda
    MEM[42] = 0xA0;
    MEM[43] = 0x82; // ldb
    MEM[44] = 0xA8;
    MEM[45] = 0x88; // mul
    MEM[46] = 0x30;
    MEM[47] = 0x00; // cmp
    MEM[48] = 0x60;
    MEM[49] = 0x92; // je
    MEM[50] = 0x00;
    MEM[51] = 0x00;
    MEM[52] = 0x00;
    MEM[128] = 0x00;
    MEM[129] = 0x02;
    MEM[130] = 0X00;
    MEM[131] = 0x05;
    // prtMemoria();
    while (1)
    { // Ciclo da CPU
        mostraStatus();
        // Enquanto não pressionar enter fica pausado
        busca();
        decodifica();
        executa();
        printf("\nPressione Enter para prosseguir!\n");
        getchar();
    }
    return 0;
}
