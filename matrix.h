// Vinicius Freitas (matricula)
//Natanel Neto (matricula)

typedef struct {
int *data;
int n_rows;
int n_cols;
int stride_rows;
int stride_cols;
int offset;
} Matrix;


// • data é um array unidimensional com os dados da matriz. Nós vamos
// guardar todos os dados num array unidimensional, o tratamento das
// dimensões será feito por outros membros da struct.
// • n_rows é o número de linhas da matriz.
// • n_cols é o número de colunas da matriz.
// Uma matriz do tipo:
// {{1, 2, 3},
// {4, 5, 6},
// {7, 8, 9}}
// Será guardada como:
// {1, 2, 3, 4, 5, 6, 7, 8, 9}
// • stride_rows é um número que determina quantos elementos devem ser
// “pulados” no array unidimensional para acessar uma próxima linha. No
// exemplo acima, considerando o elemento 1 (elemento da primeira linha e da
// primeira coluna), se quisermos acessar a próxima linha (elemento 4), temos
// que andar 3 elementos no array unidimensional. Assim, stride_rows tem
// o valor 3.
// • stride_cols é o número que determina quantos elementos devem ser
// “pulados” no array unidimensional para acessar a próxima coluna. Com
// uma matriz criada, stride_cols vai ser igual a 1, pois para acessar um
// elemento de uma próxima coluna basta acessar o próximo índice. Algumas
// funções vão modificar esse número, então é importante defini-lo mesmo
// que seu valor inicial seja sempre 1.
// • offset é o índice de onde devemos começar a considerar os dados do array
// unidimensional. Seu valor padrão quando uma matriz for criada é 0, pois
// vamos considerar os dados desde o início. Algumas funções vão modificar
// esse número, então é importante defini-lo mesmo que seu valor inicial seja
// sempre 0.
// Funções para criação de matrizes
// As funções para criação de matrizes que precisam ser implementadas são as
// seguintes.

// create_matrix
Matrix create_matrix(int *data, int n_rows, int n_cols);
// create_matrix é a principal função para criar uma matriz.
// • *data é um array unidimensional com os dados
// • n_rows é o número de linhas da matriz
// • n_cols é o número de colunas da matriz
// Note que os membros stride_rows, stride_cols e offset da struct retornada
// precisam ser iniciados.

// zeros_matrix
Matrix zeros_matrix(int n_rows, int n_cols);
// zeros_matrix cria uma matriz com todos os elementos iguais a zero.
// • n_rows é o número de linhas da matriz
// • n_cols é o número de colunas da matriz

// full_matrix
Matrix full_matrix(int n_rows, int n_cols, int value);
// full_matrix cria uma matriz com todos os elementos iguais a value.
// • n_rows é o número de linhas da matriz
// • n_cols é o número de colunas da matriz

// i_matrix
Matrix i_matrix(int n);
// i_matrix cria uma matriz identidade.
// • n é o tamanho da matriz. Lembre-se que a matriz identidade tem o mesmo
// número de linhas e colunas.

// tile
Matrix tile_matrix(Matrix matrix, int reps);
// tile_matrix cria uma nova matriz repetindo o conteúdo de matrix reps vezes.
// • matrix é a matriz de entrada
// • reps é o número de vezes que os elementos da matriz será replicado

// Funções para acessar elementos
// As funções para acessar os elementos de uma matriz que precisam ser implemen-
// tadas são as seguintes.
// get_element
int get_element(Matrix matrix, int ri, int ci);
// get_element retorna um elemento da matriz de acordo com sua posição.
// • matrix é a matriz que vai ser acessada
// • ri é o índice da linha do elemento
// • ci é o índice da coluna do elemento

// put_element
void put_element(Matrix matrix, int ri, int ci, int elem);
// put_element coloca um elemento na matriz de acordo com a posição.
// • matrix é a matriz que vai ser acessada
// • ri é o índice da linha do elemento
// • ci é o índice da coluna do elemento
// • elem é o elemento que vai ser colocado

// print_matrix
void print_matrix(Matrix matrix);
// print_matrix exibe os dados no formato da matriz.
// • matrix é a matriz que vai ser exibida

// Funções para manipulação de dimensões
// Os membros n_rows, n_cols, stride_rows, stride_cols e offset são funda-
// mentais para implementação dessas funções. Assim, o conteúdo de data não deve
// ser modificado, isto faz com que essas funções executem com grande velocidade.
// As funções para manipulação de dimensões de matrizes que precisam ser imple-
// mentadas são as seguintes:

// transpose
Matrix transpose(Matrix matrix);
// transpose retorna a matriz transposta.
// • matrix é a matriz usada para gerar a matriz transposta

// reshape
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols);
// reshape altera as dimensões da matriz. Note que nem todas as dimensões são
// válidas, pois a quantidade de elementos tem que coerente com as dimensões da
// matriz (quantidade_de_elementos = n_rows * n_cols).
// • matrix é a matriz que terá suas dimensões alteradas
// • new_n_rows é o novo número de linhas
// • new_n_colunas é o novo número de colunas

// slice
Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce);
// slice retorna um “recorte” da matriz original.
// • a_matrix é a matriz original
// • rs é o índice da linha inicial do recorte
// • re é o índice da linha final do recorte
// • cs é o índice da coluna inicial do recorte
// • ce é o índice da coluna final do recorte

// Dada a matriz:
// Matrix my_matrix;
// int data[] = {1,2,3,4,5,6,7,8,9};
// my_matrix = create_matrix(data, 3, 3);
// A chamada:
// my_matrix = slice(my_matrix, 0, 2, 1, 3);
// vai cortar my_matrix começando na linha 0 e indo até a linha de índice 1, e
// começando na coluna 1 e indo até a coluna de índice 2. É importante ressaltar
// que se re for 2 o índice final é 1, e se re for 3 o índice final é 2. Então, o índice
// final é sempre subtraído de 1.

// Funções de agregação
// As funções de agregação que precisam ser implementadas são as seguintes.

// min
int min(Matrix matrix);
// min retorna o menor elemento da matriz.
// • matrix é a matriz onde o menor elemento será procurado

// max
int max(Matrix matrix);
// max retorna o maior elemento da matriz.
// • matrix é a matriz onde o maior elemento será procurado

// argmin
int argmin(Matrix matrix);
// argmin retorna o índice do menor elemento da matriz.
// • matrix é a matriz onde o índice do menor elemento será procurado

// argmax
int argmax(Matrix matrix);
// argmax retorna o índice do maior elemento da matriz.
// • matrix é a matriz onde o índice do maior elemento será procurado

// Funções de operações aritméticas
// As funções de operações aritméticas que precisam ser implementadas são as
// seguintes.
Matrix add(Matrix matrix_1, Matrix matrix_2);
Matrix sub(Matrix matrix_1, Matrix matrix_2);
Matrix division(Matrix matrix_1, Matrix matrix_2);
Matrix mul(Matrix matrix_1, Matrix matrix_2);

// add, sub, div e mul são as quatro operações aritméticas. Essas funções fazem
// as operações elemento por elemento e retornam a matriz.