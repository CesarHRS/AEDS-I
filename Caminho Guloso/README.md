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

| 1 | 6 | 6 | 8 |
| 7 | 8 | 7 | 7 |
| 7 | 7 | 7 | 6 |
| 2 | 3 | 4 | 5 |

Supondo que estamos na posição a00. Nossas possibilidades são: a10, a11 e a01.

Dentro das possibilidades, escolhemos aquele de maior valor e vamos para a11.

Supondo que estamos na posição a11. Nossas possiblidades são: a10, a20, a21, a22, a12;

Seguindo a ordem de prioridade, devemos ir para diagonal direita. Ou a22;

Seguindo essa mesma lógica, o nosso caminho será:

a00 → a01→ a12→a21→a22→a23→a33

E nossa matriz agora será:

| 1 | -1 | 6 | 8 |
| --- | --- | --- | --- |
| 3 | 4 | -1 | 7 |
| 1 | -1 | -1 | -1 |
| 2 | 3 | 4 | -1 |

Soma: 42

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br>
<br>

<p align="center">
  <img src="imgs/rb.png" /><br/>
  <caption>Fig 1. Exemplo de estrutura de uma árvore binária do tipo Red Black.</caption>
</p>

<p align="justify">
Considerando o exemplo da Fig. 1, a estrutura RB define uma série de regras para que a estrutura se mantenha balanceda, são elas: 
</p>

>
> 1. Todo nó é vermelho ou preto
> 2. A raiz é sempre preta, mesmo sendo o único nó
> 3. Todo nó folha define seus filhos em nulo e esses são considerados sendo pretos. 
> 4. Se um nó é vermelho, então ambos os vizinhos são pretos.
> 5. Para todo nó, todos os caminhos até as folhas apresentam o mesmo número de nós pretos. 
> 6. Para cada nova inserção, o novo nó começa com a cor vermelha.
>

<p align="justify">
	Para que a estrutura RB se mantenha em conformidade com as 6 diretrizes acima apresentadas, sua construção é realizada adotando-se 3 casos de análise para cada nova inserção e remoção. Além disso, diferente da AVL, essa estrutura se baseia apenas em rotações simples para corrigir a falta de balanceamento entre suas sub-árvores.
</p>

>
> **Caso 1**: A inserção de um novo nó vermelho deve 'GARANTIR' que seus vizinhos, i.e., nós próximos a um nível acima, considerados como pai e tio, devem ser pretos. 
>  

<p align="center">
  <img src="imgs/caso1.png" /><br/>
  <caption>Fig 2. Definição do caso 1 para uma estrutura em que a inserção do nó com valor 4 produz um desbalanceamento.</caption>
</p>

<p align="justify">
Considerando a Fig. 2, uma correção na estrutura deve ser realizada para deixá-la em conformidade com as regras apresentadas. Nesse contexto, considerando o caso 1, a solução é deixar o pai e tio pretos e avançar os ponteiros da estrutura sentido raiz, o que induzirá uma avaliação do caso 2. A Fig. 3 detalha o processo realizado no caso 1 que leva a estrutura para a análise do caso 2. 
</p>

>
> **Caso 2**: O tio de um nó (i.e., item) é preto, o item e seu pai são vermelhos e o item é o filho da direita.
> 


<p align="center">
  <img src="imgs/caso1c.png" /><br/>
  <caption>Fig 3. Correção da estrutura considerando o problema abordado no caso 1.</caption>
</p>

<p align="justify">
Uma vez feita a correção do caso 1, os ponteiros de análise são atualizados para um nível acima conforme detalhando na Fig 3, o que nos leva ao caso 2. Neste caso há necessidade de executar uma correção por rotação. Essa é realizada a partir do pai e é realizada para a esquerda conforme exemplo da Fig 4. 
</p>

<p align="center">
  <img src="imgs/caso2.png" /><br/>
  <caption>Fig 4. Correção da estrutura considerando o problema abordado no caso 2.</caption>
</p>


<p align="justify">
	Uma vez realizada a rotação, note que os ponteiros de pai e item são atualizados, bem como, a organização de filhos se compararmos com a estrutura da Fig 3 que detalha a RB antes da rotação. 
</p>

<p align="justify">
	Ao realizar a rotação programada pelo caso 2, chega-se a última etapa de análise e correção, o caso 3. 
</p>

>
> **Caso 3**: O tio do item é preto, o item e seu pai são vermelhos e o item é o filho da esquerda. 
> 

<p align="justify">
Como forma de atendimento ao caso 3, o pai do pai deve ser aplicado a uma troca de cor (e.g., nesse caso o nó com valor 11 passa a ser vermelho) e a árvore rotacionada para a direita. A Fig 5 detalha esse processo e a árvore resultante após a finalização da análise e rotações.
</p>

<p align="center">
  <img src="imgs/caso3.png" /><br/>
  <caption>Fig 5. Correção da estrutura considerando o problema abordado no caso 3.</caption>
</p>

<p align="justify">
 Após a finalização do caso 3, a estrutura volta a se encontrar balanceada. Para termos certeza basta identificar o número de nós pretos desde a raiz até as folhas, esses devem se apresentar em mesmo número para todos os caminhos. Se isso for verdade, a estrutura se encontrará correta. Por fim, a Fig 6 detalha um pseudo algoritmo que une os três casos segundo Cormen at. all. 
</p>

<p align="center">
  <img src="imgs/alg.png" /><br/>
  <caption>Fig 6. Pseudo algoritmo de balanceamento adotado pela árvore Red Black segundo Cormen at all.</caption>
</p>

<p align="justify">
	Segundo Cormen at. all, após a aplicação das estratégias acima abordadas para o balanceamento, a altura <i>h</i> de uma árvore RB com <i>n</i> chaves é de no máximo 2log(n+1). A prova é por indução e pode ser observada em detalhes no capítulo 13 do livro Algoritmos: Teoria e Prática. Por fim, como vantagem em comparação com a AVL, a RB emprega apenas rotações simples e não adota recursão para avaliar seus casos, o que pode beneficiar sua utilização para estruturas muito profundas.  
</p>

# Compilação e Execução

A estrutura árvore disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/michelpires369">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/michelpiressilva/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>


<a style="color:black" href="mailto:michel@cefetmg.br?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>michel@cefetmg.br</i>
</a>
