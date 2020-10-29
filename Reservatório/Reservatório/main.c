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
/*
 Coloca o sistema em modo de teste, o que irá utilizar o meu RU como entrada de dados
 Irei utilizá-la com as diretivas de compilador #ifdef, #elif, #endif.
*/
//#define TEST_MODE

// Cria uma estrutura de dados para armazenar a entrada pelo ususário.
struct dados_pluviometricos {
    int quantidade_chuva;
    int agua_utilizada;
};

// Cria um um ponteiro mutável para um array de strings imutável que irá armazenar o nome dos meses
const char *nome_meses[] = {
    "Janeiro",
    "Fevereiro",
    "Marco",
    "Abril",
    "Maio",
    "Junho",
    "Julho",
    "Agosto",
    "Setembro",
    "Outrubro",
    "Novembro",
    "Dezembro"
};

/*
    Esta função que retorna uma struct do tipo dados_pluviometricos e não recebe nenhum parâmetro, irá gerar dados
    de teste (dummy) utilizando os números do meu RU.
*/
struct dados_pluviometricos * gerar_dados_teste(void) {
    // Cria a struct e armazena espaço de memória (12 bytes) para os dados.
    struct dados_pluviometricos * reservatorio = calloc(12, sizeof(struct dados_pluviometricos));
    
    // Atribui os dados à struct
    reservatorio[0].quantidade_chuva = 10;
    reservatorio[0].agua_utilizada = 3;
    
    reservatorio[1].quantidade_chuva = 1;
    reservatorio[1].agua_utilizada = 3;
    
    reservatorio[2].quantidade_chuva = 0;
    reservatorio[2].agua_utilizada = 5;
    
    reservatorio[3].quantidade_chuva = 3;
    reservatorio[3].agua_utilizada = 0;
    
    reservatorio[4].quantidade_chuva = 3;
    reservatorio[4].agua_utilizada = 3;
    
    reservatorio[5].quantidade_chuva = 2;
    reservatorio[5].agua_utilizada = 5;
    
    reservatorio[6].quantidade_chuva = 10;
    reservatorio[6].agua_utilizada = 5;
    
    reservatorio[7].quantidade_chuva = 15;
    reservatorio[7].agua_utilizada = 3;
    
    reservatorio[8].quantidade_chuva = 8;
    reservatorio[8].agua_utilizada = 3;
    
    reservatorio[9].quantidade_chuva = 0;
    reservatorio[9].agua_utilizada = 5;
    
    reservatorio[10].quantidade_chuva = 0;
    reservatorio[10].agua_utilizada = 0;
    
    reservatorio[11].quantidade_chuva = 10;
    reservatorio[11].agua_utilizada = 3;
    
    // Retorna a struct
    return reservatorio;
}

int main(int argc, const char * argv[]) {
    // Inicializo as variáveis com valores 0
    int capacidade_tanque = 0;
    int quantidade_agua_tanque = 0;
// Aqui utilizo as diretivas de compilador para verificar se o programa está em modo de teste.
#ifdef TEST_MODE
    struct dados_pluviometricos * reservatorio = gerar_dados_teste();
    quantidade_agua_tanque = 0;
    capacidade_tanque = 10;
#else
    // Crio um array de struct do tipo dados_pluviometricos com capacidade de 12 elementos.
    struct dados_pluviometricos reservatorio[12];

    printf("Quantidade máxima do reservatório em mm: ");
    scanf("%i", &capacidade_tanque);

    // Loop para receber dados de cada mês do ano.
    for(int i = 0; i < 12; i++) {
        printf("Quantidade de chuva no mês de %s: ", nome_meses[i]);
        // Recebe a entrada do usuário e armazena na variável.
        scanf("%i", &reservatorio[i].quantidade_chuva);

        printf("Quantidade gasta de água para o mês de %s: ", nome_meses[i]);
        scanf("%i", &reservatorio[i].agua_utilizada);
    }
#endif
    printf("\n");
    // Imprime dos dados na tela, independente de estar em modo teste ou não!
    printf("%-13s%-19s%-19s%s\n\n", "Mês", "Qtde. de chuva", "Qtde. utilizada", "Estado tanque");

    // Looping que imprime o relatório
    for(int i = 0; i < 12; i++) {
        
        // Faz a soma do valores atuais e atribui à quantidade de água no tanque
        quantidade_agua_tanque += reservatorio[i].quantidade_chuva;
        quantidade_agua_tanque -= reservatorio[i].agua_utilizada;
        
        // Define uma variável temporária para armazenar um texto referente ao estado atual do reservatório
        const char *estado_tanque = "";

        if(quantidade_agua_tanque <= 0) { estado_tanque = "Vazio"; }
        else if(quantidade_agua_tanque > 0 && quantidade_agua_tanque < capacidade_tanque) { estado_tanque = "Normal"; }
        else { estado_tanque = "Cheio"; }
        
        printf("%-12s%-19i%-19i%s\n",
               nome_meses[i],
               reservatorio[i].quantidade_chuva,
               reservatorio[i].agua_utilizada,
               estado_tanque);
    }
    

    return 0;
}
