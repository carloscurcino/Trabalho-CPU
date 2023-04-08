# Trabalho-CPU

#### Este projeto é um simulador de CPU de Von Neumann com o conjunto de instruções ISA (Instruction Set Architecture) implementado em linguagem C para a disciplina de Arquitetura e Organização de Computadores I do Instituto Federal de Educação, Ciência e Tecnologia de Goiás - Campus Anápolis.

#### Autores:

##### Bruno R. da Silveira - https://github.com/eubrunors
##### Carlos D. Curcino - https://github.com/carloscurcino

## Instruções de USO

Este programa pode ser compilado no terminal do Windows usando o compilador GCC (GNU Compiler Collection).

- #### Pré-requisitos
Certifique-se de que o GCC está instalado no seu sistema. Para verificar, abra o terminal e digite o seguinte comando:

`gcc --version`

Se o GCC estiver instalado, você verá a versão instalada do compilador. Caso contrário, você precisará instalá-lo antes de continuar.

- #### Compilação
Abra o terminal e navegue até o diretório onde se encontra o arquivo main.c do programa.

Digite o seguinte comando para compilar o programa:

`gcc -o main main.c`

- #### Executavel 

Após a compilação, o programa estará pronto para ser executado no terminal Windons. Para executá-lo, digite o seguinte comando:

`main.exe` 

Certifique-se de que o arquivo de saída gerado na etapa anterior está no mesmo diretório em que você está executando este comando.

## Implementação

O simulador é implementado em linguagem C. A memória é um vetor de palavras de oito bits de 154 posições, e os registradores arquiteturais foram implementados de acordo com as especificações do professor.

Não foram utilizados conceitos de orientação a objetos, pois isso complicaria desnecessariamente o desenvolvimento do projeto em questão.

## Sobre 

A CPU a ser implementada processa palavras de 16 bits contendo apenas números inteiros e, portanto, não há
nenhuma operação com ponto-flutuante. Ademais, não é necessário implementar nenhuma representação de aritmética
sinalizada. Embora o formato de instrução permita endereçar até 2^11 = 2.048 palavras de oito bits na memória, a memória
possui apenas 154 endereços, como apresentado acima, abrangendo os endereços de 0 (0x0) a 153 (0x99).

O programa simulará a execução de um conjunto de instruções codificadas como `endereço;instrução/dado;palavra de instrução ou palavra de dado` definidas no arquivo "instrucoes.txt". As instruções são armazenadas na memória do simulador e após isso a CPU parte para o ciclo **Busca, Decofica e Executa**. Antes de ser feita a leitura do arquivo é exibido as informações do que há na memória e nos registradores, depois da leitura é exibido de novo e então inicia-se a execução ao pressionar **ENTER**. Durante a execução, o simulador exibirá na tela informações sobre os resgistradores e o estado atual da MEmória.

Assim como em uma CPU (que está em um clico infinito, mesmo que não esteja fazendo nada) mesmo que se encerre todas a instruções ela continuara ativa a não ser que mate o processo.

## Conjunto de Instruções:

![](https://github.com/carloscurcino/Trabalho-CPU/blob/main/imagens/conjuntoDeInstrucoes.png)

## Formato de Instruções:

![](https://github.com/carloscurcino/Trabalho-CPU/blob/main/imagens/formatoDeInstrucao.png)
![](https://github.com/carloscurcino/Trabalho-CPU/blob/main/imagens/formatoDeIntrucao2.png)

## Observações:

Deve-se verificar se o arquivo "instrucoes.txt" está no diretório raiz juntamente com o programa "main.c"

É possível modificar o programa a ser executado editando o arquivo instruções.txt do diretório.
Basta abrir o arquivo e modificar as instruções, de acordo com a codificação, que será executado por essa simulação da "CPU"
Conjunto de instruções ISA (Instruction Set Architecture)


## Bibliografia:

SOARES, Lages, Nicolaci. Arquitetura e Organização de Computadores - 8ª edição. Editora LTC, 2010.
