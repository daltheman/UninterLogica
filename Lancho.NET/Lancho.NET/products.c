/*
BSD 2-Clause License

Copyright (c) 2020, Danilo Altheman
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "products.h"

struct product * generate_products(void) {
    // Cria um array de structs do tipo products e aloca memória para a mesma, 
    // já que após o return a variável sai da pilha
    struct product * products = calloc(MAX_PRODUCTS, sizeof(struct product));

    // Cria um produto usando a struct definida anteriormente.
    struct product product1;
    product1.name = "Cachorro-quente";
    product1.code = 100;
    product1.price = 5.0;
    // Adiciona o produto no array
    products[0] = product1;

    struct product product2;
    product2.name = "X-Salada";
    product2.code = 101;
    product2.price = 8.79;
    products[1] = product2;
    
    struct product product3;
    product3.name = "X-Bacon";
    product3.code = 102;
    product3.price = 9.99;
    products[2] = product3;

    struct product product4;
    product4.name = "Misto";
    product4.code = 103;
    product4.price = 6.89;
    products[3] = product4;

    struct product product5;
    product5.name = "Salada";
    product5.code = 104;
    product5.price = 4.80;
    products[4] = product5;

    struct product product6;
    product6.name = "Agua";
    product6.code = 105;
    product6.price = 3.49;
    products[5] = product6;

    struct product product7;
    product7.name = "Refrigerante";
    product7.code = 106;
    product7.price = 4.99;
    products[6] = product7;

    // desaloca products da memória
    free(products);

    // Retorna o ponteiro da struct.
    return products;
}
