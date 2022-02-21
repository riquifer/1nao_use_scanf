Este programa simples pede para que o usuário digite um nome, o mesmo imprime na tela o nome digitado e conta a quantidade de letras do nome inserido, tomando o cuidado em não contar os espaços. O desafio consistia em criar essa funcionalidade sem utilizar a função scanf, já que o mesmo não é recomendado por questões de boas práticas, principalmente para iniciantes.
O desafio original era criar no mais baixo nível possível, porém percebi que o meu nível de conhecimento não é o suficiente para tal, mas ainda assim considero-me satisfeito com o resultado pois consegui usar outras funções alcançando o máximo possível de boas práticas, considerando o meu nível de conhecimento em programação.
A próxima etapa do desafio consiste em modularizar e simplificar este programa em funções e bibliotecas personalizadas.

```c

#define PULAR_LINHA putchar('\n')

```
**(Linha 5)** Define macro para pular linha de forma mais fácil, em outra palavras, toda vez que eu escrever "PULAR_LINHA", antes do processo de compilação todos os trechos escritos são trocados pelo código "putchar('\n')

```c

char nome[50] = {};

```
**(Linha 8)** Define array onde será armazenado o nome inserido pelo usuário. Importante não deixar vazio o número dentro do colchete, pois dará erro na hora de criar o algoritmo de contagem de letras (acho que tem algo a ver com estouro de buffer, sei lá, to aprendendo ainda. Fiquei um tempão quebrando a cabeça do porquê de não funcionar por um bom tempo, até descobrir isso).

```c

int count = 0;

```
**(Linha 9)** Esta variável será usada no algoritmo de contagem de letras mais pro final (o laço for). Importante ressaltar que é preciso definir ela como 0 em qualquer momento antes de usar no laço for, senão pode ocorrer contagem errada por lixo gravado nela. Descobri isso depois de executar esse programa em outro computador, que, por coincidência, estava armazenando lixo no espaço de memória da variável, o que dava problema na hora de contar os caracteres. Particularmente, me sinto orgulhoso por ter descoberto esse problema sozinho, usando apenas lógica e o pouco de conhecimento que tenho sobre esse negócio de lixo na memória.

```c

fgets(nome, 50, stdin);

```
**(Linha 14)** Core da questão desse desafio, utilizar a função fgets() ao invés de scanf(). Vale ressaltar que o segundo argumento define o limite da quantidade de caracteres, desconfio ser um dos motivos pelas quais é recomendado o uso de fgets ao invés do scanf, sei lá.

```c

/*puts(nome);*/

```
**(Linha 15)** Não utilizo mais essa linha, porém optei por deixar comentada para fins didáticos, pois foi a partir dela que aprendi o problema da linha 8 e 9. Acontece que toda vez que eu usava o puts para mostrar na tela o nome inserido no fgets, aparecia corretamente, sem nenhum problema, somente na hora de contar que acontecia o bug de mostrar um número gigante aleatório. Se eu não tivesse utilizado a função puts nesta linha, provavelmente, acharia que o problema estava em outro lugar, como por exemplo na função fgets, sei lá.

```c

nome[strcspn(nome, "\n")] = 0;

```
**(Linha 16)** A função strcspn retorna quantidade de índices até chegar no elemento passado no segundo argumento, neste caso, ele vai pegar a array "nome" e contar quantos elementos tem até chegar no elemento "\n" (que significa quebra de linha). A lógica é a seguinte, neste caso, é preciso eliminar a quebra de linha para não ser contada no algoritmo de contagem de letras mais abaixo. Como a string passada pelo usuário é de tamanho aleatório (até no máximo 50 caracteres) o índice do elemento "\n" também será aleatório, sempre obedecendo o padrão de estar no fim da string, obviamente. Como a função strcspn segue o padrão de contar até o elemento que passamos no segundo argumento, e o segundo argumento é "\n", isso significa que o retorno da função sempre vai coincidir com o índice do elemento "\n". Sendo assim, podemos anular a quebra da linha através de uma atribuição simples que vai mudar array[x] = "\n" para array[x] = 0 e isso vai anular o último elemento, que não será contabilizado no algoritmo de contagem abaixo.

```c

int len = strlen(nome);

```
**(Linha 17)** Variável para usarmos como limite para o laço for abaixo. strlen() retorna tamanho da string. Importante lembar que na **linha 16** anulamos o caractere de quebra de linha "\n".

```c

for (int i = 0; i < len; ++i) {
  if (isspace(nome[i]) == 0) {
    count++;
  }
}

```
**(Linha 17)** Cada vez que i for menor que len, executa condicional e verifica se nome[i] é caractere através da função isspace() que retorna 0 se for caractere. Em caso de retornar 0 (é caractere) a condicional adiciona 1 à variável count, caso contrário, não faz nada e pula para o próximo carcatere, adicionando 1 ao índice i do laço for.)
