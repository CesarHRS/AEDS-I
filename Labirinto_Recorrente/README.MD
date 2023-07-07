# O Labirinto Recorrente

<img height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/> 

# OBJETIVOS

Foi proposto pelo professor Michel Pires, na disciplina de Algoritmo e Estrutura de Dados I, a criação de um jogo, onde 
o garoto que é o personagem principal está perdido num labirinto. Ele deve explorar esse labirinto em busca de uma saida,
podendo encontrar perigos no meio do caminho.

Para tanto, foi necessário cumprir os seguintes objetivos:

<b>- [✔️] Ler o arquivo input.data, gerado pelo programa
<a href= https://github.com/mpiress/GenerateDataToMaze> GenerateDataToMaze </a>;<br>
<b>- [✔️] Separar o arquivo input.data em vários arquivos; <br>
<b>- [✔️] Aloca a memória necessária para caber as matrizes; <br>
<b>- [✔️] Sortear a posição inicial do garoto; <br>
<b>- [✔️] Carregar a matriz em que o garoto se localiza; <br>
<b>- [✔️] Explorar o labirinto até a morte ou o fim; <br>
<b>- [✔️] Criar o arquivo output.data com o labirinto apos a exploracao; <br>
<b>- [✔️] Mostrar quantas casas foram percorridos, a soma dos itens consumidos pelo caminho, quantas casas ficaram
sem ser exploradas e por fim quantos perigos foram encontrados. <br>
</b>

# INTRODUÇÃO

Um garoto se encontra perdido em um labirinto e precisa explorá-lo de forma aleatória. No entanto, deve ter cuidado com as paredes que bloqueiam seu caminho (representadas pelo símbolo '#') e com os perigos que podem machucá-lo e retirar um ponto de vida (representados pelo símbolo '*').

A cada movimento do garoto, o número da posição diminui em 1 e, a cada 4 posições percorridas, ele irá descansar e recuperar um ponto de vida. No entanto, se o garoto cair de uma das bordas do labirinto, ele irá para uma posição aleatória em outro labirinto também aleatório. Nessa queda, ele perderá um ponto de vida e quebrará o chão, transformando o terreno em um perigo.

Para terminar o programa, o garoto deve voltar para a posição inicial tendo estado em todas as matrizes ou morrer tentando.

O programa foi desenvolvido seguindo o paradigma da orientação a objetos, e contém duas classes: Maze e Boy. A classe Maze armazena os dados e a matriz que está sendo operada, e um exemplar da classe Boy. Já a classe Boy armazena a posição do garoto, a posição inicial, seus pontos de vida, quantos passos ele já deu e um contador de quantos perigos ele já enfrentou, etc.

# LÓGICA UTILIZADA

## Primeiros Passos:

* O primeiro passo é abrir o arquivo "input.data", que contém 'n' matrizes de tamanho 'x' por 'y', onde 'n' é a quantidade de matrizes no arquivo, 'x' é o número de linhas e 'y' é o número de colunas em cada matriz.
* Em seguida, é necessário ler a primeira linha do arquivo para obter as dimensões das matrizes. Isso é feito pelo método readHeader da classe Maze, que extrai essas informações do arquivo e as armazena em um par ordenado (pair) chamado mazeDimensions. Como as matrizes sempre são quadradas, a primeira posição de mazeDimensions armazena a altura das matrizes e a segunda posição armazena a quantidade de matrizes no arquivo. Em seguida, uma variável é criada para armazenar a largura das matrizes.
* Depois de obter as dimensões, é preciso separar as matrizes do arquivo "input.data" para poder manipulá-las individualmente. O método separateMatrix da classe Maze é responsável por isso, criando matrizes booleanas com o mesmo tamanho e largura das matrizes originais, que serão utilizadas posteriormente para rastrear as posições por onde o garoto já passou.
* Em seguida, é preciso alocar na memória o espaço para a matriz que será operada. Isso é feito pelo método allocate da classe Maze.
Depois disso, é necessário ler a posição inicial do garoto no labirinto, o que é feito pelo método getInitialPosition da classe Maze.
* Com a posição inicial do garoto em mãos, é hora de carregar a matriz do labirinto que o garoto irá explorar na memória. Isso é feito pelo método loadMatrix da classe Maze.
* Agora é hora de começar a explorar o labirinto! A movimentação do garoto é feita pelo método joystick da classe Maze, que escolhe aleatoriamente a próxima posição a ser explorada. Antes de mover o garoto para essa posição, o método testa se ela é válida (ou seja, se não está bloqueada por uma parede ou se não contém um perigo). Se a posição for válida, o garoto se move para ela. Caso contrário, o método sorteia uma nova posição aleatória.
* Ao final do jogo, quando o garoto já tiver explorado todo o labirinto e voltado para a posição inicial, ou quando ele tiver perdido todos os pontos de vida, o programa imprime os resultados da exploração: a quantidade de casas andadas pelo garoto, a quantidade de casas não exploradas por ele e a quantidade de perigos encontrados. Essa tarefa é realizada pelo método endGame da classe Maze.

Observação: Casas contendo '#', serão computadas como casas não exploradas.

## Movimentação:

A movimentação no labirinto é realizada principalmente por meio de dois métodos pertencentes à classe Maze: joystick e tryPosition. O método joystick é responsável por realizar um loop que só termina quando o garoto ficar sem pontos de vida ou tiver explorado todo o labirinto. Em cada iteração desse loop, as seguintes operações são realizadas:

* Ver se o contador de passos do garoto é múltiplo de 4, caso positivo, curar um ponto de vida.
* Gerar um número aleatório entre 0 e 7, onde cada número representa uma posição tendo como base a tabela 1:

    | Número | Posição                    |
    |--------|----------------------------|
    | 0      | Diagonal Superior Direita  |
    | 1      | Direita                    |
    | 2      | Diagonal Inferior Direita  |
    | 3      | Baixo                      |
    | 4      | Diagonal Inferior Esquerda |
    | 5      | Esquerda                   |
    | 6      | Diagonal Superior Esquerda |
    | 7      | Cima                       |

Tabela 1: Cada número e a Posição que o mesmo representa.

Após gerado, o número, a posição que ele representa será testada por meio do método tryPosition, fará os seguintes
testes:

* Caso a posição escolhida aleatóriamente foge dos limites da matriz (linha ou coluna < 0 ou maior que a última linha
ou coluna)
  * Teletransportar o garoto para o centro de outra matriz.
* Caso a posição escolhida tiver um '*':
  * Se movimentar para a posição; 
  * Incrementar o contador de passos;
  * Remover um ponto de vida do garoto;
  * Incrementar o contador de perigos;
  * Salvar a posição como true, na matriz booleana;
  * Salvar as matrizes.
* Caso a posição escolhida tiver um '0':
  * Se movimentar para a posição;
  * Salvar a posição como true, na matriz booleana;
  * Salvar as matrizes.
* Caso a posição escolhida tiver um '#':
  * Não fazer nada e escolher outro número.
* Todos outros casos:
  * Se movimentar para a posição;
  * Incrementar o contador de passos;
  * Subtrair 1 do número presente naquela posição.
  * Salvar a posição como true, na matriz booleana;
  * Salvar as matrizes.
  
## Imprimindo resultados:

Quanto o garoto terminar de explorar o labirinto, ou morrer serão mostrados os seguintes resultados:
* Se o garoto conseguiu dar a volta, ou se ele morreu no caminho;
* O total de casas que o garoto andou;
* A quantidade de casas não exploradas pelo garoto;
* O total de perigos encontrados pelo garoto no seu percurso; 

Além disso, toda a memória principal utilizada é devolvida ao Sistema Operacional, os arquivos fechados e também é 
mostrado o tempo (medido em milissegundos) que o programa demorou para rodar.

# BIBLIOTECAS

Para o funcionamento desejado, é necessário incluir as seguintes bibliotecas no programa:

<ul>
	<li><code>#include 'iostream'</code></li>
	<li><code>#include 'chrono'</code></li>
    <li><code>#include 'fstream'</code></li>    
    <li><code>#include 'utility'</code></li>
</ul>

* A biblioteca <b>iostream</b> foi utilizada para realizar as operações de entrada e saída.
* A biblioteca <b>chrono</b> foi utilizada para medir o tempo de execução do programa.
* Já a biblioteca <b>fstream</b> foi utilizada para a leitura, escrita e criação de novos arquivos.
* Por fim a biblioteca <b>utility</b> foi utilizada para a criação de variáveis do tipo pair.

# EXEMPLO

O computador usado para a realização do teste foi o seguinte:

| SO                         | CPU               | RAM                |
|----------------------------|-------------------|--------------------|
| Debian GNU Linux (Testing) | i7 11800H (Stock) | 2x8GB 3200MTs CL22 |

Tendo o seguinte conteúdo dentro do arquivo "input.data":

## ENTRADA:

input.data:

| 3 | 4 | 5 |   |   |
|---|---|---|---|---|
|   |   |   |   |   |
| 3 | 4 | 5 | # | 2 |
| 1 | 2 | # | 3 | # |
| # | * | * | 1 | 3 |
| 4 | * | * | 2 | 1 |
| 5 | * | 5 | # | # |
|   |   |   |   |   |
| 1 | 1 | * | * | * |
| 1 | # | 3 | # | 3 |
| # | 3 | # | # | # |
| # | 1 | 2 | * | # |
| * | 3 | 1 | # | 4 |


Caso seja dito para o programa comçar na linha zero e na coluna zero, a saída deve ser a seguinte:

## Saída:

    O garoto deu um total de: 16 passos
    Ele consumiu um total de: 11 itens
    A quantidade de casas não exploradas foi de: 17
    Foram encontrados um total de: 12 perigos
    Tempo de execução: 97 milisegundos.

output.data:

| 3 | 4 | 5 | * | * |
|---|---|---|---|---|
| * | 2 | # | 3 | # |
| # | * | * | 1 | 3 |
| 4 | * | * | 2 | 1 |
| 5 | * | 5 | # | # |
|   |   |   |   |   |
| * | 0 | * | * | * |
| 1 | # | 2 | * | 3 |
| # | 3 | # | # | # |
| # | 1 | 2 | * | # |
| * | 3 | 1 | # | 4 |

Vale a pena ressaltar que o **Hardware** e **Sistema Operacional** iram afetar o tempo de execução.

# CONCLUSÃO

O programa funciona como o esperado, porém os resultados obtidos dificilmente serão comparáveis graças ao fator sorte, 
já que grande parte do algoritmo toma decisões de forma pseudoaleatória. Essa aleatóriedade do programa também torna
inviável definir o custo assintótico do mesmo.


# COMPILAÇÃO, EXECUÇÃO E INSTRUÇÔES DE USO

Antes de compilar o programa, lembre-se de colocar o aruivo input.data dentro da pasta dataset.
O output.data será criado dentra da pasta dataset, ao fim da execução do programa.	

A algorítmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para
tanto, temos as seguintes diretrizes de execução:

| Comando      | Função                                                                                   |
|--------------|------------------------------------------------------------------------------------------|
| `make clean` | Apaga a última compilação realizada contida na pasta build                               |
| `make`       | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build. |
| `make run`   | Executa o programa da pasta build após o programa já estar compilado                     |

Portanto, basta rodar o comando <code>make</code>, em um terminal, para compilar o programa e depois o comando <code>
make run</code> para o executar.

# REFERÊNCIAS

* https://cplusplus.com/reference/iostream/
* https://cplusplus.com/reference/chrono/
* https://cplusplus.com/reference/fstream/
* https://cplusplus.com/reference/utility/

# AUTOR

Criado por César Henrique Resende Soares;

Aluno do 3° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
