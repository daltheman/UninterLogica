//
//  main.c
//  Exercicio3
//
//  Created by Danilo Altheman on 15/10/20.
//

// Importa a biblioteca padrão
#include <stdio.h>
// A biblioteca ctype será a responsável pela função isupper usada para testar
// se o caractere é maiúsculo ou minúsculo.
#include <ctype.h>

int get_value(const char *message);
float char_converter(char character);

int main(int argc, const char * argv[]) {
    // As variáveis abaixo recebem a quantidade de linhas e colunas pela função get_value(char *).
    int row_max = get_value("Digite um valor para a quantidade de linhas de 1 à 10: ");
    int col_max = get_value("Digite um valor para a quantidade de colunas de 1 à 10: ");

    // Define uma variável do tipo matriz de caracteres que irá ser responsável por guardar as
    // informações fornecidas pelo usuário.
    char matrix[row_max][col_max];

    // Preenche a matriz bidimensional.
    for(int m = 0; m < row_max; m++) {
        for(int n = 0; n < col_max; n++) {
            printf("Digite um caractere: ");
            // Ignora a quebra de linha (\n) usando a expressão regular,
            // para verificar se o início da linha não contém espaço e também a \n.
            scanf(" %[^\n]s", &matrix[m][n]);
            // Limpa o buffer da entrada padrão stdin.
            setbuf(stdin, NULL);
        }
    }

    // Monta a tela(tabela) de apresentação das informações.
    printf("---------------------------\n");
    printf("| %-9s | %s |\n", "Caractere", "Ocorrencias");
    printf("---------------------------\n");

    // Este loop irá percorrer toda a matriz bidimensional.
    // Primeiramente irá percorrer todas as "linhas".
    for (int i = 0; i < row_max; i++){
        // Após todas as colunas.
        for (int j = 0; j < col_max; j++){
            // Variável que irá guardar o número de ocorrencias do caractere encontrado.
            int frequency = 0;
            // Cria uma variavél que armazena o valor corrente da matriz.
            int current_value = matrix[i][j];
            // Procura por um valor repetido e incrementa o contador.
            for (int row = 0; row < row_max; row++){
                for (int col = 0; col < col_max; col++){
                    if (current_value == matrix[row][col]){ frequency++; }
                }
            }
            // Imprime o caractere e o número de ocorrências encontrado do mesmo.
            printf("| %-9c | %-11i |\n", current_value, frequency);
        }
    }
    printf("---------------------------\n");
    
    //
    printf("A lettra %c é %s, portanto deve ser divida por %i. O resultado é %.2f\n",
           matrix[0][0],
           isupper(matrix[0][0]) ? "Maiúscula" : "Minúscula",
           isupper(matrix[0][0]) ? 10 : 2,
           char_converter(matrix[0][0]));

    return 0;
}

// Esta funcão será responsável por capturar a entrada de dados pelo usuário
// e verificar se o valor está entre 1 e 10.
int get_value(const char *message) {
    int value;
    // Executa o loop enquanto o valor digitado não estiver 1 e 10
    do {
        printf("%s", message);
        scanf("%i", &value);
    } while(value < 1 || value > 10);
    return value;
}

// Função que recebe o caractere
float char_converter(char character) {
    printf("O caractere %c corresponde ao valor %i na tabela ASCII\n", character, character);
    // Retorna o valor dividido por 10 se for maiúsculo ou dividido por 2 se for minúsculo
    // usando o operador ternário.
    return (isupper(character)) ? (float)character / 10 : (float)character / 2;
}
