# README: Trabalho Prático 1

# OBJETIVOS

<div align="justify">

<p>Foi proposto pelo Prof. Me. <b>Michel Pires da Silva</b> na disciplina de <b>Algoritmos e Estrutura de Dados II</b>, 
um trabalho no qual o objetivo era <b>criar um <i>heap</i> contendo os </b><i>'K'</i><b> elementos que mais se repetiam 
durante os textos de entrada inserido pelo usuário. Tirando as palavras inseridas no arquivo input.txt </b></p>

<p>Sendo assim, após a conclusão do projeto, temos aqui um algorítmo capaz de:

<b>- [✔️] Ler cada palavra dentro do arquivo input.txt;<br></b>
<b>- [✔️] Ler cada arquivo de texto;<br></b>
<b>- [✔️] Construir uma tabela hash com os 'n' termos que aparecerem em cada arquivo de texto, sem conter as palavras do
arquivo input.txt e removendo as stopwords;<br></b>
<b>- [✔️] Construir uma heap com os 'K' elementos que mais aparecem na tabela hash;<br></b>
<b>- [✔️] Criar uma árvore binária com essa heap;</br></b>
<b>- [✔️] Imprimir esta arvore pelo método Inorder;</br></b>
<b>- [✔️] Criar uma árvore AVL com a mesma heap;</br></b>
<b>- [✔️] Imprimir esta árvore pelo método Inorder;</br></b>
<b>- [✔️] Criar uma árvore Huffman com a mesma heap;</br></b>
<b>- [✔️] Imprimir esta árvore pelo método Inorder;</br></b>
<b>- [✔️] Mostrar o tempo necessário para inserir e imprimir cada uma das árvores em cada iteração do loop;</br></b>
</p>

<p>Vale informar aos que não conhecem, que as estruturas: <i>unordered_Map</i>, <i>vector</i> e <i>map</i> são próprias 
da linguagem C++, portanto, caso haja alguma dúvida quanto ao seu funcionamento, no site <i>CPlusPlus</i> é possível 
encontrar todas informações sobre estrutura, contexto, implementação e funções associadas de ambos. Também é válido 
introduzir o termo "<i>stopwords"</i> que nada mais são que palavras que devem ser desconsideradas durante a análise
do texto, pois impactariam diretamente no resultado durante a contagem de repetições. Estas, são palavras como: <b>não,
para, que, e, a, etc...</b> .</p> <p>Após a apresentação do tema, bem como a demonstração da lógica, serão apresentados
todos os resultados obtidos a partir dos testes feitos.</p>

# INTRODUÇÃO

As árvores desempenham um papel fundamental na programação, representando uma estrutura de dados essencial para
organizar e manipular informações de forma eficiente. Neste contexto, existem diversos tipos de árvores, cada uma com
suas características e aplicações específicas. Neste artigo, exploraremos o conceito de árvores na programação, com
foco em três tipos populares: árvores binárias, árvores AVL e árvores de Huffman.

Árvores binárias são estruturas de dados simples, compostas por nós que podem ter no máximo dois filhos, um à esquerda e
outro à direita. Elas são amplamente utilizadas em aplicações como busca binária e percorrer hierarquias de dados,
tornando-as valiosas em muitos algoritmos e sistemas.

As árvores AVL, por sua vez, são uma variação das árvores binárias que mantêm um balanceamento automático. Isso
significa que, ao inserir ou remover elementos, a árvore é reequilibrada para garantir que a diferença de altura entre
seus ramos esquerdo e direito seja limitada. Isso torna as operações de busca, inserção e remoção mais eficientes em
comparação com árvores binárias não balanceadas.

Por fim, as árvores de Huffman são utilizadas em compressão de dados. Elas são projetadas para atribuir códigos de
comprimento variável a símbolos de acordo com a frequência de ocorrência de cada símbolo em um conjunto de dados. Essa
técnica é amplamente utilizada em algoritmos de compactação de arquivos, como o formato ZIP.

# LÓGICA UTILIZADA

No contexto do objetivo do trabalho, o procedimento inicial envolveu abrir o arquivo com as palavras de entrada, arquivo
este chamado <i>"input.txt"</i>, que terá as palavras que posteriormente serão removidas da tabela hash, além da
abertura do arquivo de <i>stopwords</i>, o qual teria como conteúdo, algumas das palavras que deveriam ser
desconsideradas durante o processamento do texto de entrada.

Depois, é criada uma tabela hash contendo todas stopwords. Logo após, o programa entra em um laço de repetição, onde a
cada iteração, ele lê uma palavra do arquivo de entrada e cria uma heap, e os 'K' primeiros elementos dessa heap são
inseridos em uma arvore de cada tipo (binária, avl e huffman), lembrando que, nem a arvore e nem a heap podem conter a
palavra lida do arquivo input.txt.

Após a criação das arvores, elas serão impressas utilizando o método Pre-order, e após a criação e impressão de cada
arvore, será impresso na tela o tempo necessário para cada uma das palavras.

⚠️ Palavras com caracteres estranhos, presentes em qualquer um dos textos, não foram consideradas,
exemplo: <b>"--", "^", "-", " — ", " —", "—", "”", "“", "-”", "——", "—"</b>.

⚠️ Para alterar a quantidade de arquivos de texto que o programa lê, basta modificar o valor do literal qnt , no arquivo
main.cpp. Já para alterar o tamanho da Heap, basta modificar o literal K, no arquivo heap.hpp.

⚠️ As palavras inseridas no arquivo input.txt não podem ter acentos.

<h2>⚙️ Estruturas: </h2>

As estruturas utilizadas foram as seguintes:

* unordered_map (C++);
* vector (C++).
* Arvore Binária
* Arvore AVL
* Arvore Huffman

Onde o <i>"unordered_map"</i> foi utilizado para criar as Tabelas Hash, na qual os dados são armazenados após a leitura
dos arquivos, e o <i>"vector"</i>, utilizado para conter a Heap.

O contêiner <i>"unordered_map"</i>, baseado em uma Tabela Hash, oferece acesso com custo O(1). No entanto, uma questão a
ser considerada com tabelas hash é que, quando muito populadas, a adição de novos itens pode resultar em colisões. Caso
colisões se tornem frequentes, a performance do programa pode ser afetada negativamente.

Para contornar essa situação, a estrutura realiza uma troca de funções. Essa nova função, dada a entrada, calcula a
posição onde o item será inserido na hash e, se necessário, recalcula a posição de todos os itens existentes. Esse
procedimento é uma operação mais intensiva e pode impactar consideravelmente o desempenho.

O uso do <i>"unordered_map"</i> é vantajoso, pois é uma estrutura já implementada em C++, tornando sua utilização direta
e simples. Além disso, a implementação interna do <i>"unordered_map"</i> é otimizada, superando potencialmente tabelas
hash manuais. Isso se deve às otimizações empregadas, incluindo técnicas não convencionais, como deslocamentos (shifts),
que podem ser observadas, por exemplo, nas funções da família MurmurHash. Isso contribui para um desempenho eficiente e
confiável.

O Heap foi construído dentro de um <i>"vector"</i> em vez de uma lista, principalmente por razões de praticidade. O uso
da estrutura <i>vector</i> oferece maior flexibilidade e simplicidade em comparação com uma lista, sendo uma escolha
mais natural para uma implementação que visasse simplicidade no código e no entendimento.

A árvore binária é o tipo mais simples de árvore, onde cada nó, possui dois filhos, o direito e o esquerdo, sendo que o
filho direito é maior que o nó e o filho esquerdo menor. Nesta implementação, não é possível ter dois nós com as mesmas
palavras. O objetivo de uma árvore é tentar manter o custo de busca o mais proximo de O(log(n)) possível,
porém, graças a arvore binária não realizar rotações, caso os dados não estejam ordanados previamente, ela não
conseguirá
manter seu tempo de busca próximo de O(log(n)).

Já a árvore AVL é muito parecida com a árvore binária, porém a cada inserção, ela verifica se a árvore está
desbalanceada por meio de sua altura, caso esteja, ela utiliza de rotações simples ou duplas, que podem ser tanto para a
direita quanto para a esquerda, que irão de baixo para cima, balanceando a árvore. O problema, fica no custo de inserção
onde as constantes verificações com relação ao balanceamento da árvore irão aumentar o custo do programa. Em casos de
árvores muito pequenas, muitas vezes não compensa utilizar a árvore AVL, pois ela possívelente irá realizar várias
rotações, que deixará o programa mais lento do que somente ler a árvore de forma desbalanceada.

Por outro lado, a árvore Huffman é uma estrutura de dados especializada em compressão de dados, projetada para reduzir o tamanho de arquivos de maneira eficiente. Ela opera de forma diferente das árvores binárias e AVL, sendo construída com base na frequência de ocorrência de cada caractere em um conjunto de dados. Os caracteres mais frequentes são colocados em níveis mais altos da árvore, enquanto os menos frequentes ficam em níveis mais baixos. Isso permite que os caracteres mais comuns sejam representados por códigos mais curtos, economizando espaço de armazenamento.

O algoritmo de construção da árvore Huffman é extremamente eficaz na compactação de dados, tornando-a uma escolha ideal para a compressão de arquivos, como imagens, textos e áudios. No entanto, sua aplicação é limitada à compressão e descompressão de dados e não serve para fins de busca ou ordenação, como as árvores binárias e AVL. Portanto, a escolha da estrutura de dados depende das necessidades específicas do problema a ser resolvido.

Como já citado anteriormente, o objetivo principal do trabalho não era implementar as estrutras e sim dar resultados
mensuráveis para entender melhor as vantagens e desvantagens de cada arvore. Por conta disso, não estenderemos muito
sobre as funcionalidades de tabelas hash, nem do heap, nem de cada arvore individualmente. Portanto, para o melhor
entendimento das dos dois templates, recomendo o site CPPReference, presente nas referências deste README.

As árvores AVL e binária, só seram inseridas palavras cujo sua frequência seja diferente. Portanto, caso hajam duas
palavras armazenadas na heap, ambas com uma frequência igual, sómente a primeira será inserida na árvore. Pois as
arvores foram implementadas de modo que o identificador de cada palavra é sua string.

<h2>🕗 Tempo: </h2>

<p>Para coletar o tempo gasto entre cada interação, utilizou-se a biblioteca <code>< chrono ></code>. Após a captação, o tempo exibido para o usuário é apresentado 
em milisegundos.

# RESULTADOS E ANÁLISE

O computador no qual foi utilizado para realizar todos os testes que presentes abaixo possui as seguintes configurações:
Processador <b>i7
11800H</b>, <b>16GB</b> de memória principal, operando em <b> 3200MTs CL 22</b> e como Sistema Operacional foi usado
o <b>Arch Linux</b>.

Utilizando uma heap com o K = 20, e tendo como entrada o arquivo globalizacao.txt, provido pelo
pelo professor, e com o input.txt populado pela palavra realmente, conseguimos criar a seguinte tabela:


| Arquivo de Entrada | Tempo   (ms) | 
|--------------------|--------------|
| AVL                | 4.7828e-05   |
| Binária            | 6.555e-06    | 
| Huffman            | 7.3371e-05   |


Nessa fase de testes, a média aritmética dos tempos obtidos foi calculada e analisada, o que permitiu avaliar de maneira
confiável o desempenho do sistema em diferentes cenários de tamanho de heap. Esses resultados forneceram insights
valiosos sobre a eficácia e a eficiência do projeto como um todo.

<h2>📈 Conclusões: </h2>

Portanto, como o esperado, o tempo para inserir e imprimir uma árvore AVL foi maior que o da binária e da huffman, isso acontece
devido as rotações que ocorrem a cada inserção da árvore AVL. Neste caso, a árvore huffman acabou por gastar mais tempo
que a binária, pois enquanto a binária só insere, a hufftman ordena e por fim insere.
Oberservação: dado a forma com que as árvores foram implementadas, as árvores binárias e AVL não inserem palavras cujo seu value seja
igual a de outra palavra inserida anteriormente, já a Huffman, insere. Fazendo com que a árvore huffman sofra de uma leve
desvantagem.

# COMPILAÇÃO E EXECUÇÃO

O algorítmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para
tanto, temos as seguintes diretrizes de execução:

| Comando      | Função                                                                                  |                     
|--------------|-----------------------------------------------------------------------------------------|
| `make clean` | Apaga a última compilação realizada contida na pasta build                              |
| `make`       | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
| `make run`   | Executa o programa da pasta build após a realização da compilação                       |

É válido ressaltar a importância de seguir as seguintes instruções para garantir o bom funcionamento do programa:

1. Certifique-se de ter o arquivo de stop words na pasta ["dataset"](./dataset) com o
   nome ["stopwords.txt"](./dataset/stopwords.txt).

2. Coloque os arquivo de texto na mesma pasta, com o nome ["text0.txt"](./dataset/input0.txt).
    * Observação, em caso de mais de um arquivo, o segundo deverá se chamar "input1.txt", o terceiro "input2.txt" e
      assim por diante. Também será necessário mudar o tamanho da constante qnt, definido na main.

3. Insira o arquivo com as palavras de entrada na pasta ["dataset"](./dataset) com o
   nome ["input.txt"](./dataset/stopwords.txt).

Seguindo essas orientações, o programa será capaz de executar corretamente e imprimir o resultado no terminal.

# BIBLIOTECAS

Para o funcionamento desejado, fora utilizadas as seguintes bibliotecas:<br/>

<ul>
	<li><code>#include 'iostream'  </code></li>
	<li><code>#include 'fstream'</code></li>
	<li><code>#include 'chrono'</code></li>
	<li><code>#include 'string'</code></li>
	<li><code>#include 'vector'</code></li>
	<li><code>#include 'unordered_map'</code></li>
</ul>

<hr/>

# REFERÊNCIAS

<ul>
   <li>https://cplusplus.com/reference/iostream/</li>
    <li>https://cplusplus.com/reference/fstream/</li>
    <li>https://cplusplus.com/reference/chrono/</li>
    <li>https://cplusplus.com/reference/string/</li>
    <li>https://cplusplus.com/reference/vector/vector/</li>
    <li>https://cplusplus.com/reference/unordered_map/unordered_map/</li>
	<li><b>ROSEN, Kenneth</b>. Matemática Discreta e Suas Aplicações 6ª Ed. internet: https://www.mheducation.com/. 2009.</li>
	<li><b>CORMEN, Thomas</b>. Algoritmos - Teoria e Prática 3º Ed. internet: https://www.elsevier.com/pt-br, 2012.</li>
</ul>

</div>

# AUTOR

Criado por <b>César Henrique Resende Soares</b>;

Agradecimento especial a <b>Henrique Souza Fagundes</b> e ao <b>Daniel Alves Sanches</b>, ambos monitores da disciplina
de AEDS II pela ajuda durante o desenvolvimento do trabalho.

Aluno do <b>4</b>° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
