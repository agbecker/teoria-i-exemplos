### Reconhecedor - simulador de autômato com pilha ###

# Seja uma linguagem sobre {a, b, c} tal que a quantidade de 'a's é igual à soma das quantidades de 'b's e 'c's na palavra,
# e todo prefixo da palavra tem uma quantidade de 'a's maior ou igual à quantidade somada de 'b's e 'c's.

# Interpretamos um cenário de uma máquina de vendas. a representa adicionar uma moeda, e b e c são produtos
# que custam uma moeda cada (salgadinho e chocolate)

# Seja o AP com dois estados q0 e q1. q0 é inicial e final. São suas transições:

# q0 -- a, ε, A --> q1
# q1 -- a, ε, A --> q1
# q1 -- b, A, ε --> q1
# q1 -- c, A, ε --> q1
# q1 -- ?, ?, ε --> q0

# -----------------------------------------------------------

# Cada função representa um estado e simula o comportamento do AP naquele estado, dadas a entrada e pilha atuais
# Toda vez que é lido um símbolo da entrada ele deve ser removido ao ser passado adiante

# As funções retornam um booleano. Este será True se a palavra for aceita, ou False se for rejeitada

def q0(entrada : str, pilha : list, moedas : int):
    # Início da execução, quando a entrada começar com 'a'
    if len(entrada) > 0 and entrada[0] == 'a':
        moedas += 1
        print(f"Adicionou moeda. {moedas} moedas na máquina.")
        return q1(entrada[1:], pilha + ['A'], moedas)
    
    # Aceita quando o input terminou e a pilha está vazia
    if len(entrada) == len(pilha) == 0:
        return True

    # Senão, rejeita
    return False

def q1(entrada : str, pilha : list, moedas : int):
    # Incrementa moedas para cada 'a' lido
    if len(entrada) > 0 and entrada[0] == 'a':
        moedas += 1
        print(f"Adicionou moeda. {moedas} moedas na máquina.")
        return q1(entrada[1:], pilha + ['A'], moedas)

    # Decrementa moeda com 'b' ou 'c' se a pilha não estiver vazia
    if len(pilha) > 0 and len(entrada) > 0 and (entrada[0] == 'b'):
        pilha.pop() # Remove último elemento da pilha
        moedas -= 1
        print(f"Comprou um salgadinho. {moedas} moedas na máquina.")
        return q1(entrada[1:], pilha, moedas)

    if len(pilha) > 0 and len(entrada) > 0 and (entrada[0] == 'c'):
        pilha.pop() # Remove último elemento da pilha
        moedas -= 1
        print(f"Comprou um chocolate. {moedas} moedas na máquina.")
        return q1(entrada[1:], pilha, moedas)

    # Se ambas a pilha e a entrada estiverem vazias, volta para q0
    if len(entrada) == len(pilha) == 0:
        return q0(entrada, pilha, moedas)

    # Senão, rejeita a palavra
    return False

if __name__ == '__main__':
    entrada = input("Palavra: ")
    resultado = q0(entrada, [], 0)
    print()
    print("Aceita" if resultado else "Rejeita")