#pragma once
#include "constante.h"
#include "../../entrada.h"

inline void cadastrar(char v[TAMANHO], int indice) {
    if (pos[indice] >= TAMANHO) {
        std::cout << "Cadastro cheio." << std::endl;
        return;
    }
    std::cout << "Entre com um caractere:" << std::endl;
    std::string valor;
    if (!lerTexto(valor, 1)) return;
    v[pos[indice]++] = valor[0];
}

inline void pesquisar(int i, char v[TAMANHO], int indice) {
    if (i >= pos[indice]) return;
    std::cout << "Posicao " << i << ": " << v[i] << std::endl;
    pesquisar(i + 1, v, indice);
}

inline void alterar(int i, char v[TAMANHO], int indice) {
    pesquisar(i, v, indice);
    std::cout << "Entre com a posicao a ser alterada:" << std::endl;
    int p;
    if (!lerInteiro(p)) return;
    if (p < 0 || p >= pos[indice]) {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }
    std::cout << "Entre com um caractere:" << std::endl;
    std::string valor;
    if (lerTexto(valor, 1)) v[p] = valor[0];
}

inline void reorganizar(int i, char v[TAMANHO], int indice) {
    if (i >= pos[indice] - 1) return;
    v[i] = v[i + 1];
    reorganizar(i + 1, v, indice);
}

inline void excluir(int i, char v[TAMANHO], int indice) {
    pesquisar(i, v, indice);
    std::cout << "Entre com a posicao a ser excluida:" << std::endl;
    int p;
    if (!lerInteiro(p)) return;
    if (p < 0 || p >= pos[indice]) {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }
    reorganizar(p, v, indice);
    v[--pos[indice]] = '\0';
}
