#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

unsigned short int PC = 0x0000;        // program counter
unsigned int MBR = 0x0000000000000000; // memory buffer register
unsigned short int MAR = 0x00000000;   // memory address register
unsigned char IR = 0x00;               // instruction register
unsigned short int IMM;
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
    else
    {
        // printf("\n executando uma tarefa right \n");
        PC += 4;
    }
}
void decodifica()
{
    if (LR == 0)
    {
        printf("\n executando uma tarefa left \n");
        IBR = MBR & 0xFFFF;
        MBR = MBR >> 16;
        MAR = MBR & 0X7FF;
        IR = MBR >> 11;
        // LR = 1; // LR MUDA AQUI OU NO EXEC
        //  printf("\n %d OPC left \n", IR);
    }
    else
    {
        printf("\n executando uma tarefa right \n");
        // LR = 0;
        MAR = IBR & 0X7FF;
        IR = IBR >> 11;
        // printf("\n %x OPC right \n", IR);
    }
}
void executa()
{
    if (IR == 0b00100)
    { // ADD
        A = A * B;
        // printf("\n somando registradores, valor = %d \n", A);
        mudaLR();
    }
    else if (IR == 0b10011)
    { // LDA
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        A = MBR & 0xFFFF;
        // printf("\n usando o registrador A = %d \n", A);
        mudaLR();
    }
    else if (IR == 0b10100)
    { // LDB
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        B = MBR & 0xFFFF;
        // printf("\n usando o registrador B = %d \n", B);
        mudaLR();
    }
    else
    {
    }
}
void setMemoria()
{ // inicializa a memoria
    for (int i = 0; i < 154; i++)
    {
        MEM[i] = hlt;
    }
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
    printf("PC:\t0x%X \tIR:\t0x%X \tLR:\t0x%X \n", PC, IR, LR);
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
    MEM[41] = 0x80;
    MEM[42] = 0xA0;
    MEM[43] = 0x82;
    MEM[44] = 0x20;
    MEM[45] = 0x00;
    MEM[46] = 0x00;
    MEM[47] = 0x00;
    MEM[48] = 0x00;
    MEM[49] = 0x00;
    MEM[50] = 0x00;
    MEM[51] = 0x00;
    MEM[52] = 0x00;
    MEM[128] = 0x00;
    MEM[129] = 0x02;
    MEM[130] = 0X00;
    MEM[131] = 0x05;
    // prtMemoria();
    while (1) // Ciclo da CPU
    {

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
