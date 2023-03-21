#include <stdio.h>
#include <stdlib.h>

unsigned short int PC = 0x0000;        // program counter
unsigned int MBR = 0x0000000000000000; // memory buffer register
unsigned short int MAR = 0x00000000;   // memory address register
unsigned char IR = 0x00;               // instruction register
unsigned short int IBR = 0x0000;       // instruction buffer register
unsigned short int AC = 0x0000;        // accumulator register
unsigned char LR = 0x00;               // Flag Left/Right
unsigned char MEM[154];                // memory
unsigned short int A = 0x0000;         // Registe A
unsigned short int B = 0x0000;         // Registe B

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
        printf("\n MBR na busca e %x \n", MBR);
        decodifica();
    }
    else
    {
        printf("\n executando uma tarefa right \n");
        PC += 4;
        decodifica();
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
        LR = 1;
        printf("\n %d OPC left \n", IR);
        executa();
    }
    else
    {
        LR = 0;
        MAR = IBR & 0X7FF;
        IR = IBR >> 11;
        printf("\n %x OPC right \n", IR);

        executa();
    }
}
void executa()
{
    if (IR == 0b00100)
    { // ADD
        A = A * B;
        printf("\n somando registradores, valor = %d \n", A);
    }
    else if (IR == 0b10011)
    { // LDA
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        A = MBR & 0xFFFF;
        printf("\n usando o registrador A = %d \n", A);
    }
    else if (IR == 0b10100)
    { // LDB
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        B = MBR & 0xFFFF;
        printf("\n usando o registrador B = %d \n", B);
    }
    else
    {
        return 0;
    }
}
void setMemoria()
{ // inicializa a memoria
    for (int i = 40; i < 84; i++)
    {
        MEM[i] = 0;
    }
}
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
    prtMemoria();
    while (1)
    {
        int a = 0;
        printf("Se vc quer continuar tecle 1\n");
        scanf("%d", &a);

        if (a == 1)
            busca();
    }
    return 0;
}
