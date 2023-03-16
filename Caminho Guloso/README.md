# Caminho Guloso

<div style="display: inline-block;">
    <img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
    <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
    <a href="https://github.com/mpiress/midpy/issues">
    <img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
    <img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

## Introdução

<p style="text-align: justify">
	Este trabalho propõem uma solução para o seguinte problema: A partir de uma dada posição na matriz, qual o caminho para a última posição com a maior soma possível dos valores?
</p>

<p style="text-align: justify">
	Para o caminhamento na matriz foram propostas algumas regras:
</p>

>1. Não é permitido caminhar para cima. Ou seja, estando em uma linha n o algoritmo não verifica valores nas linhas acima;
>2. É permitido caminhar para esquerda e para as diagonais (quando possível);
>3. Não é permitido passar mais de uma vez pela mesma posição;
>4. Os valores nas posições da matriz sempre recebem inteiros positivos;
>5. É fim da execução é obrigatório mostrar a soma do caminho de cada matriz e a soma total;

<br>

## Solução


A resolução do problema apresenta  a construção de uma algoritmo guloso. Essa classe de algoritmos é caracterizada por sempre considerar o melhor decisão local, sem considerar o todo. Para esse caso, dado uma posição 
$a_{ij}$ da matriz, para decidir a próxima posição é verificado apenas as casas adjacentes.

Para a solução é importante definir um critério de decisão para casas de mesmo valor. Para isso vamos seguir uma ordem de prioridade que o algoritmo irá seguir. Assim, dentro das opção possíveis, após o verificar o valor da casa, iremos priorizar da seguinte forma:

>1. Diagonal Direita
>2. Direita
>3. Baixo
>4. Diagonal Esquerda
>5. Esquerda

Para implementação do algoritmo foi utilizada uma estrategia de substituição. Dada as possibilidades (validando as posições que existem) sempre comparamos uma posição com outra, seguindo a ordem de prioridade, e salvando a maior. As verificações são iniciadas a partir da posição menos prioritária.

Assim que mudados de posição, nossa posição anterior recebe “-1” para demarcar as posições que já foram verificadas.

As matrizes são lidas de um arquivo e é importante que este apresente o seguinte formato:

>1. Na primeira linhas apresentar o números de linhas e o número de colunas, separados por espaço.
>2. Uma matriz é separada da outra por um espaço em branco.

Obs: o número de matrizes não precisa ser informado, uma vez que o programa lê o arquivo até o final, buscando todas matrizes.

A posição inicial é lida a partir de um arquivo de configuração (config.va), que segue o seguindo formato:

>1. Na primeira linha, linha e coluna inicial separado por um espaço em branco.

Obs: As linhas e colunas são contadas a partir do 0. Por exemplo, a primeira possível da matriz é a posição $a_{00}$;

### Exemplo:
```
4 4
1 2 3 4
4 3 2 1
1 2 3 4
4 3 2 1

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

1 6 6 8
7 8 7 7
7 7 7 6
2 3 4 5
```

<br>
<br>

## Exemplos de Saída

matrizes.txt

```
4 4
1 2 3 4
4 3 2 1
1 2 3 4
4 3 2 1

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

1 6 6 8
7 8 7 7
7 7 7 6
2 3 4 5
```

config.va

```
0 0
```

Output:
```
Matriz 1: 1 + 4 + 3 + 3 + 4 + 2 + 1 = 18

Matriz 2: 1 + 1 + 1 + 1 = 4

Matriz 3: 1 + 8 + 7 + 7 + 7 + 3 + 4 + 5 = 42

Soma total: 64
```

<br> <br>

## Exemplo Explicado

Exemplo: Dada a matriz abaixo, qual o caminho percorrido?
| | | | |
| --- | --- | --- | --- |
| 1 | 6 | 6 | 8 |
| 7 | 8 | 7 | 7 |
| 7 | 7 | 7 | 6 |
| 2 | 3 | 4 | 5 |

Supondo que estamos na posição $a_{00}$. Nossas possibilidades são: $a_{10}$, $a_{11}$ e $a_{01}$.

Dentro das possibilidades, escolhemos aquele de maior valor e vamos para $a_{11}$.

Supondo que estamos na posição a11. Nossas possiblidades são: $a_{10}$, $a_{20}$, $a_{21}$, $a_{22}$, $a_{12}$;

Seguindo a ordem de prioridade, devemos ir para diagonal direita. Ou $a_{22}$;

Seguindo essa mesma lógica, o nosso caminho será:

$a_{00}$ $a_{11}$ $a_{22}$ $a_{21}$ $a_{20}$ $a_{31}$ $a_{32}$ $a_{33}$

E nossa matriz agora será:
| | | | |
| --- | --- | --- | --- |
| -1 | -1 | 6 | 8 |
| 3 | 4 | -1 | 7 |
| 1 | -1 | -1 | -1 |
| 2 | 3 | 4 | -1 |

Soma: 42



# Compilação e Execução

A estrutura árvore disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/vini_apereira">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/vinicius-alves-pereira-913254236/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>


<a style="color:black" href="mailto:vinicius.apereira04@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>vinicius.apereira04@gmail.com</i>
</a>
