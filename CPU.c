#include <stdio.h>
#include <stdlib.h>
#include <defines.h>

// 1 - Entender a codificação do programa
// 2 - Botar a cpu para rodar
// 3 - Ler o texto e decodifiacar em bin

int main()
{
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

    // Seta tudas posições da memoria para iniciarem com 0
    for (int i = 0; i < 154; i++)
    {
        memoria[i] = hlt;
        printf("HELLO WORLD\n");
    }
    // OPCode tem 5 bits e o resto da instrução tem o endereço de memória

    // MBR recebe a palavra de 32 bits
    // IBR = MBR && 0xFFFF;
    // MBR  = MBR >> 16;
    // MAR = MBR && 0x7FF;(mascara para os 11 bits menos significativos) //Não entendi bem essa parte de mascara
    // IR = MBR >> 11; //IR recebe o MBR deslocado em 11 bits

    // IF's de checagem do OP CODE ex: IF(IR == 0b10011(LDA))

    // MBR está ligado diretamente a mémoria ele que pega o endereço/instrução

    while (1)
    {
        Busca();
        Decodifica();
        Executa();
    }

    return 0;
}

void Busca()
{
    printf("Buscando");
}

void Decodifica()
{
    printf("Decodificando");
}

void Executa()
{
    printf("Executando");
}