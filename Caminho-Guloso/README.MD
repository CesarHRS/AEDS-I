# O caminho do Guloso

<img height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/> 

# OBJETIVOS

Foi proposto pelo professor Michel Pires, na disciplina de Algoritmo e Estrutura de Dados I, a criação de um Algoritmo
Guloso. Esse algoritmo visa ler uma ou várias matrizes do arquivo de entrada, chamado input.data, perguntar
ao usuário qual seria a posição inicial e, a partir disso, seguir um percurso até a extremidade da diagonal direita,
realizando a soma dos valores encontrados.

Dessa forma, após a conclusão do projeto, temos um algoritmo capaz de:

<b>- [✔️] Ler o arquivo input.data, gerado automaticamente pelo programa
<a href= https://github.com/mpiress/GenerateDataToMatrix> GenerateDataToMatrix </a>;<br></b>
<b>- [✔️] Carregar as matrizes na memória;<br></b>
<b>- [✔️]  Comparar o valor das posições à leste, sudeste, sul, sudoeste e oeste da posição atual e "andar" para a
posição de maior valor;</br></b>
<b>- [✔️] Chegar até a última posição da última linha e da última coluna na matriz; <br></b>
<b>- [✔️] Imprimir a soma de cada posição que o programa "caminhou"; <br></b>

# INTRODUÇÃO

<b>O que é um algoritmo guloso?</b> Ziviani (2011, p. 58) "Algoritmos gulosos são tipicamente usados para
resolver
problemas de otimização. Um exemplo é o algoritmo para encontrar o caminho mais curto entre dos vértices de um grafo. Um
algoritmo guloso escolhe a aresta que parece mais promissora em qualquer instante, e nunca reconsidera essa decisão,
independentemente do que possa acontecer mais tarde. Não existe necessidade de avaliar alternativas, nem de empregar
algoritmos sofisticados que permitam desfazer decisões tomadas previamente. A razão de o algoritmo ser chamado guloso é
que o algoritmo escolhe, a cada passo, o candidato mais evidente que possa ser adicionado à solução."

# LÓGICA UTILIZADA

## Primeiros Passos:

* Abrir o arquivo "input.data", que contém 'n' matrizes de tamanho 'x' por 'y', onde 'n' é a quantidade de matrizes no
  arquivo, 'x' é o número de linhas e 'y' é o número de colunas em cada matriz.
* Ler a primeira linha do arquivo, que contém 'x' e 'y'.
    * A função read-size lê do arquivo e salva em size o tamanho da matriz. Já que a matriz sempre é quadrada, só foi
      necessário a criação de uma variável para armazenar sua quantidade de linhas.<br>
* A seguir, é alocado dinâmicamente uma matriz com "x" linhas e "y" colunas
* Em seguida, é carregado a primeira matriz do arquivo para a variável, trazendo o conteúdo do disco para a memória
  principal.
    * Isso é feito pela função load_matrix <br>
      https://github.com/CesarHRS/Caminho-Guloso/blob/6406d531025a7253c4c55be5768a89990a2c9b4a/src/file.cpp#L12-L32
* Ler a posição inicial na matriz.
    * A leitura é realizada pela função read_row_and_column, que pergunto ao usuário qual linha e colona será o ponto de
      partida do programa <br>
* Sempre que uma posição é percorrida, ela é marcada com o número 0 para evitar que o programa faça voltas.
    * Para cada movimento possível (geralmente para a direita, diagonal direita, para baixo, diagonal esquerda e
      esquerda), há uma função responsável para realizar esse movimento e atribuir o valor 0. <br>
      https://github.com/CesarHRS/Caminho-Guloso/blob/6406d531025a7253c4c55be5768a89990a2c9b4a/src/auxiliary.cpp#L19-L22

## Movimentação:

* O objetivo principal do programa é mover-se da posição inicial, definida pelo usuário, até o ponto mais extremo da
  diagonal direita da matriz, indo sempre em direção ao maior número possível que esteja a sudeste ou leste, ou sul, ou
  oeste, ou sudoeste da posição atual.
    * Em caso de desempate, o programa segue a seguinte lista de prioridade:
        1. Sudeste
        2. Leste
        3. Sul
        4. Oeste
        5. Sudoeste

            *   |     |     |     |     |
                |-----|-----|-----|-----|
                | 903 | 762 | 253 | 590 |
                | 707 | 0   | 87  | 351 |
                | 485 | 564 | 114 | 584 |
                | 388 | 307 | 545 | 585 |

                A matriz acima exemplifica o caso padrão. Nele seria possível o algoritmo se movimentar tanto para a 
                posição em que se encontra o número 114, quanto para as posição em que se encontram os números 87, 564 
                707 e 485. Nesse caso o programa escolherá ir para oeste por ser a posição com o maior número (707). 
                Após a movimentação, o resultado seria a seguinte matriz:

            *    |     |     |     |     |
                 |-----|-----|-----|-----|
                 | 903 | 762 | 253 | 590 |
                 | 0   | 0   | 87  | 351 |
                 | 485 | 564 | 114 | 584 |
                 | 388 | 307 | 545 | 585 |

            A parte do código responsável por realizar essa tomada de decisão pode ser encontrado abaixo:
            https://github.com/CesarHRS/Caminho-Guloso/blob/6406d531025a7253c4c55be5768a89990a2c9b4a/src/joystick.cpp#L32-L48

              * Casos especiais:
                   * No entanto, há alguns casos especiais que precisam ser considerados, como, por exemplo, se a 
                      posição atual estiver na última linha da matriz, neste caso o único movimento possível será ir 
                      para a leste; 
                
                        *    |     |     |     |     |
                             |-----|-----|-----|-----|
                             | 903 | 762 | 253 | 590 |
                             | 707 | 409 | 87  | 351 |
                             | 485 | 564 | 114 | 584 |
                             | 0   | 307 | 545 | 585 |
                         
                             Na matrix acima é possível ver o caso mostrado acima, onde a proxima posição será a leste 
                             da atual, sobre o número 307.
                         
                             O tratamento desse caso pode ser visto no código abaixo: 
                             https://github.com/CesarHRS/Caminho-Guloso/blob/e1eae6326a9a707efbb99abdd85b370c543367f4/src/joystick.cpp#L12-L13

                   * Se estiver na primeira coluna, o programa terá que decidir entre ir para sudeste, leste, ou sul; 

                       *    |     |     |     |     |
                             |-----|-----|-----|-----|
                             | 903 | 762 | 253 | 590 |
                             | 0   | 409 | 87  | 351 |
                             | 485 | 564 | 114 | 584 |
                             | 388 | 307 | 545 | 585 |

                             No caso acima, as escolhas seriam entre 564, 409 e 485 e o programa optaria por ir a sudeste (564)

                              Essa tomada de decisão é feita nas seguintes linhas do código:
                              https://github.com/CesarHRS/Caminho-Guloso/blob/e1eae6326a9a707efbb99abdd85b370c543367f4/src/joystick.cpp#L23-L31

                   * Por fim, se a posição atual for na última coluna, ele terá que escolher entre ir para sul,
                      sudoeste ou oeste. 

                        *    |     |     |     |     |
                             |-----|-----|-----|-----|
                             | 903 | 762 | 253 | 590 |
                             | 707 | 409 | 87  | 0   |
                             | 485 | 564 | 114 | 584 |
                             | 388 | 307 | 545 | 585 |
                         
                             A matriz acima exemplifica este caso, as escolhas seriam entre 584, 114 ou 87, onde o 
                             programa escolherá ir para sul (584). Esse caso é tratado nas seguintes linhas de código:     
                        https://github.com/CesarHRS/Caminho-Guloso/blob/e1eae6326a9a707efbb99abdd85b370c543367f4/src/joystick.cpp#L14-L22

												     
                        
## Imprimindo resultados:

* Ao chegar no ponto mais extremo da diagonal direita da matrix, o programa imprime a soma do número de cada posição em
  que passou.
* Ao fim desse processo toda a memória é liberada de volta para o Sistema Operacional.
* Caso ainda haja mais matrizes no arquivo input.data, o programa volta para a etapa da alocação da matriz, e fica em
  loop até que não haja mais matrizes no arquivo.
* No fim, toda a memória utilizada é devolvida de volta ao Sistema Operacional, o arquivo fechado e é mostrado no
  terminal o tempo (medido em milissegundos) que o programa demorou para rodar.

# BIBLIOTECAS

Para o funcionamento desejado, é necessário incluir as seguintes bibliotecas no programa:

<ul>
	<li><code>#include 'iostream'  </code></li>
	<li><code>#include 'fstream'</code></li>
    <li><code>#include 'chrono'</code></li>
</ul>

* A biblioteca <b>iostream</b> foi utilizada para realizar as operações de entrada e saída.
* Já a biblioteca <b>fstream</b> foi utilizada para a leitura do arquivo 'input.data'.
* Por fim, a biblioteca <b>chrono</b> foi utilizada para medir o tempo de execução do programa.

# EXEMPLO

O computador usado para a realização do teste foi o seguinte:

| SO                         | CPU               | RAM                |
|----------------------------|-------------------|--------------------|
| Debian GNU Linux (Testing) | i7 11800H (Stock) | 2x8GB 3200MTs CL22 |

Tendo a seguinte matriz como entrada:

|     |     |     |     |     |     |     |
|-----|-----|-----|-----|-----|-----|-----|
| 478 | 664 | 153 | 268 | 500 | 997 | 991 |
| 903 | 762 | 253 | 590 | 868 | 842 | 682 |
| 707 | 409 | 87  | 351 | 565 | 496 | 251 |
| 485 | 564 | 114 | 584 | 413 | 863 | 22  |
| 388 | 307 | 545 | 585 | 972 | 417 | 572 |
| 192 | 415 | 565 | 814 | 178 | 537 | 405 |
| 765 | 380 | 806 | 193 | 509 | 893 | 263 |

Entrada:

Caso seja dito para o programa comçar na linha zero e na coluna zero, a saída deve ser a seguinte:

Resultado:

|     |     |     |     |     |     |     |
|-----|-----|-----|-----|-----|-----|-----|
| 0   | 664 | 153 | 268 | 500 | 997 | 991 |
| 0   | 0   | 253 | 590 | 868 | 842 | 682 |
| 0   | 409 | 87  | 351 | 565 | 496 | 251 |
| 485 | 0   | 114 | 584 | 413 | 863 | 22  |
| 388 | 307 | 0   | 585 | 972 | 417 | 572 |
| 192 | 415 | 565 | 0   | 178 | 537 | 405 |
| 765 | 380 | 0   | 0   | 0   | 0   | 0   |

Além disso, contador será 7437 e o tempo de execução irá variar em função de seu **Hardware** e **Sistema Operacional**.

# COMPILAÇÃO, EXECUÇÃO E INSTRUÇÔES DE USO

Antes de compilar o programa, lembre-se de colocar o aruivo input.data dentro da pasta dataset.

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
* https://cplusplus.com/reference/fstream/
* https://cplusplus.com/reference/chrono/
* ZIVIANI, N. Projeto De Algoritmos Com Implementações Em Pascal E C. 3. ed. São Paulo: Cengage Learning, 2011

# AUTOR

Criado por César Henrique Resende Soares;

Aluno do 3° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
