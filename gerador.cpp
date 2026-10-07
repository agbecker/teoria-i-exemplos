/*** Gerador de palavras aleatórias ***

 Seja uma linguagem sobre {a, b, c} tal que a quantidade de 'a's é igual à soma
 das quantidades de 'b's e 'c's na palavra, e todo prefixo da palavra tem uma
 quantidade de 'a's maior ou igual à quantidade somada de 'b's e 'c's.

 Interpretamos um cenário de uma máquina de vendas. a representa adicionar uma
 moeda, e b e c são produtos que custam uma moeda cada (salgadinho e chocolate).

 É dada pela GLC:

 S -> aB | aC | ε
 B -> SbS
 C -> ScS
*/

#include <iostream>
#include <random>
#include <string>

using namespace std;

/* Todas as funções recebem dois argumentos:
   moedas - o contador de moedas na máquina, incrementado com cada 'a' e
            decrementado com cada 'b' e 'c'.
   limite - o limite máximo de profundidade de derivação, para impedir palavras
            muito grandes. Decrementado a cada chamada de função.
   Todas retornam uma string, que é sua contribuição para a palavra final. */

string botaMoeda(int moedas, int limite);
string compraSalgadinho(int moedas, int limite);
string compraChocolate(int moedas, int limite);

mt19937 gerador{random_device{}()};

/* Sorteia um inteiro em [min, max] */
int randint(int min, int max) {
    return uniform_int_distribution<int>(min, max)(gerador);
}

/* S */
string botaMoeda(int moedas, int limite) {
    // Se excedeu a profundidade máxima, retorna "" (palavra vazia)
    if (limite <= 0)
        return "";

    // Sorteia uma produção.
    // Produções com 'a' incrementam a contagem de moedas
    switch (randint(1, 3)) {
        case 1: // aB
            moedas++;
            cout << "Adicionou moeda. " << moedas << " moedas na máquina.\n";
            return "a" + compraSalgadinho(moedas, limite - 1);

        case 2: // aC
            moedas++;
            cout << "Adicionou moeda. " << moedas << " moedas na máquina.\n";
            return "a" + compraChocolate(moedas, limite - 1);

        default: // ε
            return "";
    }
}

/* B */
string compraSalgadinho(int moedas, int limite) {
    // SbS
    // Chama S à esquerda e guarda o que foi retornado
    string s = botaMoeda(moedas, limite - 1);

    // b decrementa uma moeda
    moedas--;
    cout << "Comprou um salgadinho. " << moedas << " moedas na máquina.\n";

    // Retorna chamada à esquerda concatenada com b e chamada à direita
    return s + 'b' + botaMoeda(moedas, limite - 1);
}

/* C */
string compraChocolate(int moedas, int limite) {
    // ScS
    // Chama S à esquerda e guarda o que foi retornado
    string s = botaMoeda(moedas, limite - 1);

    // c decrementa uma moeda
    moedas--;
    cout << "Comprou um chocolate. " << moedas << " moedas na máquina.\n";

    // Retorna chamada à esquerda concatenada com c e chamada à direita
    return s + 'c' + botaMoeda(moedas, limite - 1);
}

int main() {
    string palavra = botaMoeda(0, 6);
    cout << "\nPalavra: " << palavra << "\n";
}