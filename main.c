#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
//  SETANDO AS VARIÁVEIS GLOBAIS
unsigned short int PC = 0x0000;        // program counter
unsigned int MBR = 0x0000000000000000; // memory buffer register
unsigned short int MAR = 0x0000;   // memory address register
unsigned char IR = 0x00;               // instruction register
unsigned short int IMM = 0x0000;
unsigned short int IBR = 0x0000; // instruction buffer register
unsigned short int AC = 0x0000;
unsigned char E, L, G;         // accumulator register
unsigned char LR = 0x00;       // Flag Left/Right
unsigned char MEM[0x99];        // memory
unsigned short int A = 0x0000; // Registe A
unsigned short int B = 0x0000; // Registe B
unsigned short int T;

void mudaLR(){
    LR = !LR;
}
void busca(){
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
    }
}
void decodifica(){
    if (LR == 0 ){
        printf("\n decodificando uma tarefa left \n");
        IBR = MBR & 0xFFFF;
        MBR = MBR >> 16; 
        IR = MBR >> 11;
        if (IR >= 0b11000 && IR <= 0b11111){ // VERIFICA SE É IMEDIATO
            IMM=MBR & 0x7FF;
        }else{
            MAR = MBR & 0x7FF;
        }
    }
    else{
        printf("\n decodificando uma tarefa right \n");
        IR = IBR >> 11;
        if (IR >= 0b11000 && IR <= 0b11111){ // VERIFICA SE É IMEDIATO
            IMM = IBR & 0X7FF;
        }else{
            MAR = IBR & 0X7FF;
        }
        if (IR!=hlt)
            PC += 4;
    }
}
void executa(){
    if (IR==nop)
    {
        if (LR==1){
            PC+=4;
            mudaLR();
        }else{
            mudaLR();
        }
    }
    else if (IR==add)
    {
        A=A+B;
        mudaLR();
    }
    else if (IR==sub)
    {
        A=A-B;
        mudaLR();
    }
    else if (IR==div)
    {
        A=A/B;
        mudaLR();
    } 
    else if(IR == mul){ // mul
        A = A * B;
        printf("\n mul registradores, valor = %d \n", A);
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
    else if (IR == ldb) { // LDB
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR | MEM[MAR];
        B = MBR & 0xFFFF;
        printf("\n usando o registrador B = %d \n", B);
        mudaLR();
    }
    else if (IR==cmp) {
        if (A==B){
            E=1;
        }else
            E=0;
        if (A<B){
            L=1;
        }else
            L=0;
        if (A>B){
            G=1;
        }else
             G=0;
        mudaLR();
    }
    else if(IR==xchg){
        T=A;
        A=B;
        B=T;
        mudaLR();
    }
    else if (IR==and)
    {
        A=A&B;
    }
    else if(IR==or){
        A=A|B;
    }
    else if (IR==xor)
    {
        A=A^B;
    }
    else if (IR==not)
    {
        A=!A;
    }
    else if (IR == je){
        if(E==1)
            PC = MAR;
        mudaLR();
    }
    else if (IR == jne) {
        if (E==0)
            PC = MAR;
        mudaLR();
    }
    else if (IR==jl){
        if (L==1)
            PC = MAR;
        mudaLR();
    }
    else if (IR==jle){
        if (L==1 || E==1)
            PC = MAR;
        mudaLR();
    }
    else if (IR==jg){
        if (G==1)
            PC = MAR;
        mudaLR();
    }
    else if (IR==jge){
        if (G==1 || E==1)
            PC = MAR;
        mudaLR();
    }
    else if (IR==jmp){
            PC = MAR;
        mudaLR();
    }
    else if(IR==sta){ //STORE A

        MEM[MAR]=A>>8;
        MEM[MAR+1]=A & 0xFF;
        mudaLR();
    }
    else if(IR==stb){  //STORE B
        MEM[MAR]=B>>8;
        MEM[MAR+1]=B & 0xFF;
        mudaLR();
    }
    else if(IR==movialImm){ //MOVE IMMEDIATE TO LOWER A
        A = 0x0000;
        A = IMM & 0xFF;
        mudaLR();
    }
    else if (IR==moviahImm){ // MOVE IMMEDIATE TO HIGHER A
        A = A | IMM<<8;
        mudaLR();
        printf("EXECUTEI AQUI %X", A);
    }
    else if (IR==addiaImm){
        A=A+IMM;
    }
    else if (IR==subiaImm){
        A=A-IMM;
    }
    else if (IR==muliaImm){
        A=A*IMM;
    }
    else if (IR==diviaImm){
        A=A/IMM;
    }
    else if (IR==lshImm){
        A=A<<IMM;       
    }
    else{
        A=A>>IMM;
    }
}
void setMemoria(){ // inicializa a memoria
    for (int i = 0x00; i < 0x9A; i++)
        MEM[i] = hlt;
}
void prtMemoria(){ // printa a memoria
    printf("\nMEMORIA:\n");
    for (int i = 0x00; i < 0x9A; i++){
        printf("%X: \t0x%X\t", i, MEM[i]); // MOSTRA A POSIÇÃO E O VALOR ARMAZENADO NESSA POSIÇÃO EM HEX
        if (i > 0 && (i + 1) % 4 == 0){
            printf("\n");
        }
    }
}
void mostraStatus(){
    printf("\n\nCPU:\n");
    printf("A:\t0x%X \tB:\t0x%X \tT:\t0x%X \n", A, B, T);
    printf("MBR:\t0x%X \tMAR:\t0x%X \tIMM:\t0x%X \n", MBR, MAR, IMM);
    printf("PC:\t%d \tIR:\t0x%X \tLR:\t0x%X \n", PC, IR, LR);
    printf("E:\t0x%X \tL:\t0x%X \tG:\t0x%X \n", E, L, G);
}

int main(){
    setMemoria();
    PC = 0;
    MEM[0] = 0x98; MEM[1] = 0x14; //lda OK 
    MEM[2] = 0xA0; MEM[3] = 0x16; //ldb OK
    MEM[4] = 0x20; MEM[5] = 0x00; //MUL
    //MEM[6] = 0xC8; MEM[7] = 0x99; //moviahImm OK
    //MEM[6] = 0xC0; MEM[7] = 0x09; //movialImm OK
    MEM[20] = 0x00; MEM[21] = 0x02;
    MEM[22] = 0X00; MEM[23] = 0x05;
    mostraStatus();
    prtMemoria();
    printf("\nPressione Enter para INICIAR!\n");
    getchar();
    while (1){// Ciclo da CPU
        // Enquanto não pressionar enter fica pausado
        busca();
        decodifica();
        executa();
        system("cls");
        mostraStatus();
        prtMemoria();
        printf("\nPressione Enter para prosseguir!\n");
        getchar();
        
    }
    return 0;
}
