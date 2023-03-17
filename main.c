#include <stdio.h>
#include <stdlib.h>

unsigned short int PC  = 0x0000; //program counter
unsigned int MBR = 0x0000000000000000; //memory buffer register
unsigned short int MAR = 0x00000000; //memory address register
unsigned char IR  = 0x00; //instruction register
unsigned short int IBR = 0x0000; //instruction buffer register
unsigned short int AC  = 0x0000; //accumulator register
unsigned char LR  = 0x00; //link register
unsigned char MEM[154]; //memory
unsigned short int A = 0x0000;
unsigned short int B = 0x0000;


void busca(){

    if(LR==0){
        MAR=PC;
        MBR=MEM[MAR]; //98
        MAR++;	//41
        MBR=MBR<<8;
        MBR=MBR|MEM[MAR]; //9880
        MAR++;	//41
        MBR=MBR<<8;
        MBR=MBR|MEM[MAR]; //9880
        MAR++;	//41
        MBR=MBR<<8;
        MBR=MBR|MEM[MAR]; //9880
        printf("\n MBR na busca e %x \n", MBR);
        decodifica();
    }
    else{
        printf("\n executando uma tarefa right \n");
        PC+=4;
        decodifica();
    }
}
void decodifica(){
    if(LR==0){
    printf("\n executando uma tarefa left \n");
    IBR = MBR&0xFFFF;
    MBR=MBR>>16;
    MAR = MBR&0X7FF;
    IR = MBR >> 11;
    LR=1;
    printf("\n %d OPC left \n", IR);
    executa();
    }else{
        LR=0;
        MAR=IBR&0X7FF;
        IR=IBR>>11;
        printf("\n %x OPC right \n", IR);

        executa();

    }
}
void executa(){
    if(IR==0b00100){
        A=A*B;
        printf("\n somando registradores, valor = %d \n", A);

    }
    else if(IR==0b10011){//LDA
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR|MEM[MAR];
        A = MBR & 0xFFFF;
        printf("\n usando o registrador A = %d \n", A);

    }
    else if(IR==0b10100){ //LDB
        MBR = MEM[MAR];
        MBR = MBR << 8;
        MAR++;
        MBR = MBR|MEM[MAR];
        B = MBR & 0xFFFF;
        printf("\n usando o registrador B = %d \n",B);
    }
    else{
        return 0;
    }
    busca();
}
void setMemoria(){
    for(int i=40; i<84; i++){
        MEM[i]=0;
    }
}
void prtMemoria(){
    for(int i=40; i<84; i++){
        printf("%d",MEM[i]);
    }
}
int main(){
    setMemoria();
    PC=40;
    MEM[40]=0x98;
    MEM[41]=0x80;
    MEM[42]=0xA0;
    MEM[43]=0x82;
    MEM[44]=0x20;
    MEM[45]=0x00;
    MEM[46]=0x00;
    MEM[47]=0x00;
    MEM[48]=0x00;
    MEM[49]=0x00;
    MEM[50]=0x00;
    MEM[51]=0x00;
    MEM[52]=0x00;
    MEM[128]=0x00;
    MEM[129]=0x02;
    MEM[130]=0X00;
    MEM[131]=0x05;
    prtMemoria();
    busca();

    return 0;
}
