/*** Reconhecedor - simulador de autômato com pilha ***

 Seja uma linguagem sobre {a, b, c} tal que a quantidade de 'a's é igual à soma
 das quantidades de 'b's e 'c's na palavra, e todo prefixo da palavra tem uma
 quantidade de 'a's maior ou igual à quantidade somada de 'b's e 'c's.

 Interpretamos um cenário de uma máquina de vendas. a representa adicionar uma
 moeda, e b e c são produtos que custam uma moeda cada (salgadinho e chocolate).

 Seja o AP com dois estados q0 e q1. q0 é inicial e final. São suas transições:

 q0 -- a, ε, A --> q1
 q1 -- a, ε, A --> q1
 q1 -- b, A, ε --> q1
 q1 -- c, A, ε --> q1
 q1 -- ?, ?, ε --> q0
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Cada função representa um estado e simula o comportamento do AP naquele
   estado, dadas a entrada e pilha atuais.
   Toda vez que é lido um símbolo da entrada ele deve ser removido ao ser
   passado adiante.

   As funções retornam um booleano: true se a palavra for aceita, false se for
   rejeitada. */

bool q0(string entrada, vector<char> pilha, int moedas);
bool q1(string entrada, vector<char> pilha, int moedas);

bool q0(string entrada, vector<char> pilha, int moedas) {
    // Início da execução, quando a entrada começar com 'a'
    if (!entrada.empty() && entrada[0] == 'a') {
        moedas++;
        cout << "Adicionou moeda. " << moedas << " moedas na máquina.\n";
        pilha.push_back('A');
        return q1(entrada.substr(1), pilha, moedas);
    }

    // Aceita quando o input terminou e a pilha está vazia
    if (entrada.empty() && pilha.empty())
        return true;

    // Senão, rejeita
    return false;
}

bool q1(string entrada, vector<char> pilha, int moedas) {
    // Incrementa moedas para cada 'a' lido
    if (!entrada.empty() && entrada[0] == 'a') {
        moedas++;
        cout << "Adicionou moeda. " << moedas << " moedas na máquina.\n";
        pilha.push_back('A');
        return q1(entrada.substr(1), pilha, moedas);
    }

    // Decrementa moeda com 'b' se a pilha não estiver vazia
    if (!pilha.empty() && !entrada.empty() && entrada[0] == 'b') {
        pilha.pop_back();   // Remove último elemento da pilha
        moedas--;
        cout << "Comprou um salgadinho. " << moedas << " moedas na máquina.\n";
        return q1(entrada.substr(1), pilha, moedas);
    }

    // Decrementa moeda com 'c' se a pilha não estiver vazia
    if (!pilha.empty() && !entrada.empty() && entrada[0] == 'c') {
        pilha.pop_back();
        moedas--;
        cout << "Comprou um chocolate. " << moedas << " moedas na máquina.\n";
        return q1(entrada.substr(1), pilha, moedas);
    }

    // Se ambas a pilha e a entrada estiverem vazias, volta para q0
    if (entrada.empty() && pilha.empty())
        return q0(entrada, pilha, moedas);

    // Senão, rejeita a palavra
    return false;
}

int main() {
    string entrada;
    cout << "Palavra: ";
    getline(cin, entrada);

    bool resultado = q0(entrada, {}, 0);

    cout << "\n" << (resultado ? "Aceita" : "Rejeita") << "\n";
}