/*
BSD 2-Clause License

Copyright (c) 2020, Danilo Altheman
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "products.h"

// Função que não retorna nenhum valor e é responsável por exibir o menu.
// É passado como argumento da função um array de produtos.
void display_menu(struct product * products) {
    // system("clear");
    printf("%-4s %-20s %-6s %-14s\n", "Item", "Produto", "Código", "Preço Unitário");
    for(int i = 0; i < MAX_PRODUCTS; i++) {
        // Imprime na tela usando a formatação de espaços.
        printf("%-4i %-20s %-6i %-14.2f\n", i + 1, products[i].name, products[i].code, products[i].price);
    }
    printf("Digite qualquer outro número para encerrar a comanda!\n");
}

int main(void) {
    // Irei usar a biblioteca locale.h para fazer a formatação dos valores.
    // https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_7.html
    setlocale(LC_ALL, "pt_BR");
    
    printf("\t\tLancho .NET\n");
    
    // Cria um pointeiro do tipo struct que irá conter os produtos retornados pela função generate_products().
    struct product * available_products = generate_products();

    // Cria um array de inteiros para armazenar os produtos selecionados
    int selected_items[INT16_MAX];

    int index = 0;
    // Variável usada para armazenar o produto selecionado pelo usuário
    int selected_product;
    int amount = 0;
    
    // Este loop é reponsável por exibir o menu e aguardar a seleção do usuário.
    // Será executado até o a seleção seja um número fora da faixa de 1 até 7.
    while(1) {
        // Chama a função que exibe o menu com os produtos.
        display_menu(available_products);
        printf("--> ");
        // Recebe o input do usuário e armazena o valor na variável.
        scanf("%i", &selected_product);
        if(selected_product < 1 || selected_product > MAX_PRODUCTS) {
            break;
        }
        // Recebe a quantidade produto
        printf("Quantidade: ");
        scanf("%i", &amount);
        
        /*
         Este loop será o responsável por adicionar a quantidade selecionada
         de um determinado produto.
        */
        for(int i = 0; i < amount; i++) {
            // Adiciona o item selecionado no array.
            selected_items[index] = selected_product - 1;
            // Incrementa o index.
            index++;
        }
    }

    // Variável para fazer a soma dos produtos.
    float total_price = 0;
    // Imprime a lista de produtos que foram selecionados
    printf("\nOs produtos selecionados foram: \n");
    printf("---------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-6s | %-14s |\n", "Item", "Produto", "Código", "Valor Unitário");
    printf("---------------------------------------------------------\n");
    // Neste loop iremos fazer a iteração com a coleção e iremos imprimir os produtos selecionados.
    for(int i = 0; i < index ;i++) {
        printf("| %-4i | %-20s | %-6i | %-14.2f |\n", i + 1, available_products[selected_items[i]].name, available_products[selected_items[i]].code, available_products[selected_items[i]].price);
        printf("---------------------------------------------------------\n");
        // Faz a soma dos produtos
        total_price += available_products[selected_items[i]].price;
    }
    printf("| Valor total da comanda: R$ %03.2f                      |\n", total_price);
    printf("---------------------------------------------------------\n");
}
