# Trabalho-CPU
Anotações/Manual de uso
Para utilizar o programa, siga os passos abaixo:

- Compile o arquivo "main.c" usando um compilador C. Navegue até o diretório onde está o arquivo "main.c" e digite o seguinte comando:
   gcc main.c -o main

- Execute o programa compilado com o comando abaixo:
   ./main

O programa simulará a execução de um conjunto de instruções pré-definidas na função "main". As instruções são armazenadas na memória do simulador e executadas em sequência. Antes de ser feita a leitura do arquivo é exibido as informações do que há na memória e nos registradores, depois da leitura é exibido de novo e então inicia-se a execução ao pressionar enter. Durante a execução, o simulador exibirá na tela informações sobre as operações que estão sendo realizadas.

Após a execução das instruções, o programa encerrará automaticamente. Para proseguir com o programa deve se pressionar enter, e assim ele entra no próximo ciclo de máquina.

Observações:

É possível modificar as instruções a serem executadas editando a váriavel "nomeArquivo" na função "main" no arquivo "main.c".
