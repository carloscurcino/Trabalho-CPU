#define hlt 0b00000
#define nop 0b00001
#define add 0b00010
#define sub 0b00011
#define mul 0b00100
#define div 0b00101
#define cmp 0b00110
#define xchg 0b00111
#define and 0b01000
#define or 0b01001
#define xor 0b01010
#define not 0b01011
#define je 0b01100 //JUMP IF EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1.
#define jne 0b01101 //JUMP IF NOT EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 0.
#define jl 0b01110 //JUMP IF LOWER THAN: muda o registrador PC para o endereço de memória X caso L = 1.
#define jle 0b01111 //JUMP IF LOWER THAN OR EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1 ou L = 1.
#define jg 0b10000 //JUMP IF GREATER THAN: muda o registrador PC para o endereço de memória X caso G = 1.
#define jge 0b10001 //JUMP IF GREATER THAN OR EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1 ou G = 1.
#define jmp 0b10010 //JUMP: muda o registrador PC para o endereço de memória X
#define lda 0b10011 
#define ldb 0b10100
#define sta 0b10101
#define stb 0b10110
#define ldrb 0b10111
#define movialImm 0b11000
#define moviahImm 0b11001
#define addiaImm 0b11010
#define subiaImm 0b11011
#define muliaImm 0b11100
#define diviaImm 0b11101
#define lshImm 0b11110
#define rshImm 0b11111
#define tamanhoMemoria 0x9A