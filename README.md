# Teoria da Computação I - Trabalho 2 - Exemplos

Este repositório contém exemplos em C++ e em Python de um gerador e um reconhecedor de uma linguagem livre de contexto. 

O gerador gera palavras aleatórias pertencentes à linguagem através da sua gramática. O reconhecedor simula o comportamento de um autômato com pilha que reconhece a linguagem. Ambos imprimem interpretações semânticas de cada símbolo gerado/lido no contexto que a linguagem representa, explicitando contadores quando apropriado.

A linguagem é definida sobre {a, b, c} tal que a quantidade de 'a's é igual à soma das quantidades de 'b's e 'c's na palavra, e todo prefixo da palavra tem uma quantidade de 'a's maior ou igual à quantidade somada de 'b's e 'c's.

Interpretamos um cenário de uma máquina de vendas. a representa adicionar uma moeda, e b e c são produtos que custam uma moeda cada (salgadinho e chocolate).