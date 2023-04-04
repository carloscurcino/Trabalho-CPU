#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
unsigned char MEM[0x99];       // memory
unsigned short int A = 0x0000; // Registe A
unsigned short int B = 0x0000; // Registe B
unsigned short int T;

void mudaLR()
{
    LR = !LR;
}
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
        printf("busca/mbr=mar : %x, %x ",MAR, MBR);
    }
}
void decodifica()
{
    if (LR == 0)
    {
        printf("\n decodificando uma tarefa left \n");
        IBR = MBR & 0xFFFF;
        MBR = MBR >> 16;
        IR = MBR >> 11;
        if (IR >= 0b11000 && IR <= 0b11111)
        { // VERIFICA SE É IMEDIATO
            IMM = MBR & 0x7FF;
        }
        else
        {
            MAR = MBR & 0x7FF;
        }
    }
    else
    {
        printf("\n decodificando uma tarefa right \n");
        IR = IBR >> 11;
        if (IR >= 0b11000 && IR <= 0b11111)
        { // VERIFICA SE É IMEDIATO
            IMM = IBR & 0X7FF;
        }
        else
        {
            MAR = IBR & 0X7FF;
        }
        if (IR != hlt)
            PC += 4;
    }
}
void executa()
{
    if (IR == nop)
    {
        if (LR == 1)
        {
            PC += 4;
            mudaLR();
        }
        else
        {
            mudaLR();
        }
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
    else if(IR == mul){ // mul
        A = A * B;
        printf("\n mul registradores, valor = %d \n", A);
        mudaLR();
    }
    else if (IR == div){
        A = A / B;
        mudaLR();
    }
    else if (IR == lda){ // LDA
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        A = MBR & 0xFFFF;
        printf("\n usando o registrador A = %d \n", A);
        mudaLR();
    }
    else if (IR == ldb){ // LDB
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
    else if (IR == xchg)
    {
        T = A;
        A = B;
        B = T;
        mudaLR();
    }
    else if (IR == and)
    {
        A = A & B;
    }
    else if (IR == or)
    {
        A = A | B;
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
    else if (IR == jge){
        if (G == 1 || E == 1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jmp){
        PC = MAR;
        mudaLR();
    }
    else if(IR==sta){ //STORE A
        MEM[MAR]=A>>8;
        MEM[MAR+1]=A & 0xFF;
        mudaLR();
    }
    else if (IR == stb)
    { // STORE B
        MEM[MAR] = B >> 8;
        MEM[MAR + 1] = B & 0xFF;
        mudaLR();
    }
    else if (IR == movialImm)
    { // MOVE IMMEDIATE TO LOWER A
        A = 0x0000;
        A = IMM & 0xFF;
        mudaLR();
    }
    else if (IR == moviahImm)
    { // MOVE IMMEDIATE TO HIGHER A
        A = A | IMM << 8;
        mudaLR();
        printf("EXECUTEI AQUI %X", A);
    }
    else if (IR == addiaImm)
    {
        A = A + IMM;
    }
    else if (IR == subiaImm)
    {
        A = A - IMM;
    }
    else if (IR == muliaImm)
    {
        A = A * IMM;
    }
    else if (IR == diviaImm)
    {
        A = A / IMM;
    }
    else if (IR == lshImm)
    {
        A = A << IMM;
    }
    else
    {
        A = A >> IMM;
    }
}
void setMemoria()
{ // inicializa a memoria
    for (int i = 0x00; i < 0x9A; i++)
        MEM[i] = hlt;
}
void prtMemoria()
{ // printa a memoria
    printf("\nMEMORIA:\n");
    for (int i = 0x00; i < 0x9A; i++)
    {
        printf("%X: \t0x%X\t", i, MEM[i]); // MOSTRA A POSIÇÃO E O VALOR ARMAZENADO NESSA POSIÇÃO EM HEX
        if (i > 0 && (i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}
void mostraStatus()
{
    printf("\n\nCPU:\n");
    printf("A:\t0x%X \tB:\t0x%X \tT:\t0x%X \n", A, B, T);
    printf("MBR:\t0x%X \tMAR:\t0x%X \tIMM:\t0x%X \n", MBR, MAR, IMM);
    printf("PC:\t%d \tIR:\t0x%X \tLR:\t0x%X \n", PC, IR, LR);
    printf("E:\t0x%X \tL:\t0x%X \tG:\t0x%X \n", E, L, G);
}

int encontraInicio(char *nomeArquivo){

    FILE *arquivo;
    int num;
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    num = fgetc(arquivo) - '0';
 
    fclose(arquivo);
    return num;
}

void armazemaIntrucao(unsigned short int palavraInstrucao, int flagRightleft, int enderecoInstrucao, int palavraEndereco ){

    if (flagRightleft==0)
    {
        MEM[enderecoInstrucao] = palavraInstrucao;
        MEM[enderecoInstrucao+1] = palavraEndereco & 0xff;
    }
    else if (flagRightleft==1)
    {
        MEM[enderecoInstrucao+2] = palavraInstrucao;
        MEM[enderecoInstrucao+3] = palavraEndereco & 0xff;
    }
    else
    {
        printf("Programa deu erro ao armazena instrucao em memoria!");
        exit(1);
    }
    
}

void armazenaDado(char *palavraDado,int enderecoInstrucao){
    int *pointAuxiliar;

    unsigned short int dado = strtol(palavraDado, &pointAuxiliar,16);
    MEM[enderecoInstrucao]=dado>>8;
    MEM[enderecoInstrucao+1]=dado & 0xff;

}

void lerArquivo(char *nomeArquivo){
    FILE *arquivo;
    char linha[50];
    unsigned int enderecoInstrucao=0;

    arquivo=fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\nOcorreu um erro ao abrir o arquivo!\n");
        exit(1);
    } 

    //Necessário encontrar o inicio do programa em memória
    PC=encontraInicio(nomeArquivo);

    while(fgets(linha, sizeof(linha), arquivo)) {
        char palavraCompacta[20], tipoInstrucao;
        int cont=0;
        sscanf(linha, "%x;%c;%[^\n]s", &enderecoInstrucao, &tipoInstrucao, palavraCompacta);
        printf("%x;%c;%s\n", enderecoInstrucao, tipoInstrucao, palavraCompacta);
        
        if (tipoInstrucao=='i')
        {   
            // Dividir a string em duas partes usando o delimitador "/"
            char* instrucao1_endereco1_str = strtok(palavraCompacta, "/");
            char* instrucao2_endereco2_str = strtok(NULL, "/");

            // Dividir a primeira parte em instrução e endereço usando o espaço como delimitador
            char* instrucao1_str = strtok(instrucao1_endereco1_str, " ");
            int endereco1 = strtol(strtok(NULL, " "), NULL, 16);

            // Dividir a segunda parte em instrução e endereço usando o espaço como delimitador
            char* instrucao2_str = strtok(instrucao2_endereco2_str, " ");
            int endereco2 = strtol(strtok(NULL, " "), NULL, 16);

            unsigned short int palavraInstrucaoLeft =  decodificaInstrucao(instrucao1_str);
            palavraInstrucaoLeft = palavraInstrucaoLeft<<3;
            palavraInstrucaoLeft = palavraInstrucaoLeft | (endereco1 & 0x700);

            armazemaIntrucao(palavraInstrucaoLeft,0,enderecoInstrucao,endereco1);

            unsigned short int palavraInstrucaoRight =  decodificaInstrucao(instrucao2_str);
            palavraInstrucaoRight = palavraInstrucaoRight<<3;
            palavraInstrucaoRight = palavraInstrucaoRight | (endereco2 & 0x700);
            armazemaIntrucao(palavraInstrucaoRight,1,enderecoInstrucao,endereco2);
        }
        else if(tipoInstrucao=='d')
        {
            armazenaDado(palavraCompacta, enderecoInstrucao);
        }
        else
        {
            printf("Erro ao definir tipo de intrucao 'i' ou 'd' ");
            exit(1);
        }
        
    }
    fclose(arquivo);
}

int decodificaInstrucao(char *str) {
    if (strcmp(str, "hlt") == 0) {
        return 0b00000;
    }else if (strcmp(str, "nop") == 0){
        return 0b00001;
    }else if (strcmp(str, "add") == 0){
        return 0b00010;
    }else if (strcmp(str, "sub") == 0){
        return 0b00011;
    }else if (strcmp(str, "mul") == 0){
        return 0b00100;
    } else if (strcmp(str, "div") == 0) {
        return 0b00101;
    } else if (strcmp(str, "cmp") == 0) {
        return 0b00110;
    } else if (strcmp(str, "xchg") == 0) {
        return 0b00111;
    } else if (strcmp(str, "and") == 0) {
        return 0b01000;
    } else if (strcmp(str, "or") == 0) {
        return 0b01001;
    } else if (strcmp(str, "xor") == 0) {
        return 0b01010;
    } else if (strcmp(str, "not") == 0) {
        return 0b01011;
    } else if(strcmp(str, "je") == 0) {
        return 0b01100;
    } else if (strcmp(str,"jne")==0) {
        return 0b01101;
    }
    else if (strcmp(str,"jl")==0) {
        return 0b01110;
    }
    else if (strcmp(str,"jle")==0) {
        return 0b01111;
    }
    else if (strcmp(str,"jg")==0) {
        return 0b10000;
    }
    else if (strcmp(str,"jge")==0)
    {
        return 0b10001;
    }
    else if (strcmp(str,"jmp")==0)
    {
        return 0b10010;
    }
    else if (strcmp(str,"lda")==0)
    {
        return 0b10011;
    }
    else if (strcmp(str,"ldb")==0)
    {
        return 0b10100;
    }
    else if (strcmp(str,"sta")==0)
    {
        return 0b10101;
    }
    else if (strcmp(str,"stb")==0)
    {
        return 0b10110;
    }
    else if (strcmp(str,"ldrb")==0)
    {
        return 0b10111;
    }
    else if (strcmp(str,"movial")==0)
    {
        return 0b11000;
    }
    else if (strcmp(str,"moviah")==0)
    {
        return 0b11001;
    }
    else if (strcmp(str,"addia")==0)
    {
        return 0b11010;
    }
    else if (strcmp(str,"subia")==0)
    {
        return 0b11011;
    }
    else if (strcmp(str,"mulia")==0)
    {
        return 0b11100;
    }
    else if (strcmp(str,"divia")==0)
    {
        return 0b11101;
    }
    else if (strcmp(str,"lsh")==0)
    {
        return 0b11110;
    }
    else if (strcmp(str,"rsh")==0)
    {
        return 0b11111;
    }
    else
    {
        printf("Erro ao decodificar instrucao!!");
        exit(1);
    }
    
}

int main()
{
    char nomeArquivo1[]="instrucoes.txt";
    setMemoria();
    mostraStatus();
    prtMemoria();
    printf("\nPressione Enter para LER o arquivo!\n");
    getchar();
    lerArquivo(nomeArquivo1);
    mostraStatus();
    prtMemoria();
    printf("\nPressione Enter para prosseguir!\n");
    getchar();
    while (1)
    { // Ciclo da CPU
        // Enquanto não pressionar enter fica pausado
        busca();
        decodifica();
        executa();
        mostraStatus();
        prtMemoria();
        printf("\nPressione Enter para prosseguir!\n");
        getchar();
    }
    
    return 0;
}
