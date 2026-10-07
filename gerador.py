### Gerador de palavras aleatórias ###

# Seja uma linguagem sobre {a, b, c} tal que a quantidade de 'a's é igual à soma das quantidades de 'b's e 'c's na palavra,
# e todo prefixo da palavra tem uma quantidade de 'a's maior ou igual à quantidade somada de 'b's e 'c's.

# Interpretamos um cenário de uma máquina de vendas. a representa adicionar uma moeda, e b e c são produtos
# que custam uma moeda cada (salgadinho e chocolate)

# É dada pela GLC:

# S -> aB | aC | ε
# B -> SbS
# C -> ScS

# -----------------------------------------------------------
from random import randint

# Todas as funções recebem dois argumentos:
# moedas - o contador de moedas na máquina, incrementado com cada 'a' e decrementado com cada 'b' e 'c'.
# limite - o limite máximo de profundidade de derivação, para impedir palavras muito grandes. Decrementado a cada chamada de função.
# Todas retornam uma string, que é sua contribuição para a palavra final. A palavra será concatenada destes retornos.


# S
def botaMoeda(moedas : int, limite : int):
    # Se excedeu a profundidade máxima, retorna '' (palavra vazia)
    if limite <= 0:
        return ''

    # Sorteia uma produção
    # Produções com 'a' incrementam a contagem de moedas
    escolha = randint(1, 3)
    match escolha:
        case 1: #aB
            moedas += 1
            print(f"Adicionou moeda. {moedas} moedas na máquina.")
            return 'a' + compraSalgadinho(moedas, limite-1)

        case 2: #aC
            moedas += 1
            print(f"Adicionou moeda. {moedas} moedas na máquina.")
            return 'a' + compraChocolate(moedas, limite-1)

        case 3: #ε
            return ''

# B
def compraSalgadinho(moedas : int, limite : int):
    #SbS
    # Chama S à esquerda e guarda o que foi retornado
    s = botaMoeda(moedas, limite-1)

    # b decrementa uma moeda
    moedas -= 1
    print(f"Comprou um salgadinho. {moedas} moedas na máquina.")

    # Retorna chamada à esquerda concatenada com b e chamada à direita
    return s + 'b' + botaMoeda(moedas, limite-1)

# C
def compraChocolate(moedas : int, limite : int):
    #ScS
    # Chama S à esquerda e guarda o que foi retornado
    s = botaMoeda(moedas, limite-1)

    # c decrementa uma moeda
    moedas -= 1
    print(f"Comprou um chocolate. {moedas} moedas na máquina.")

    # Retorna chamada à esquerda concatenada com b e chamada à direita
    return s + 'c' + botaMoeda(moedas, limite-1)

if __name__ == '__main__':
    palavra = botaMoeda(0, 6)
    print()
    print(f"Palavra: {palavra}")