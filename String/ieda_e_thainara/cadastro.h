#pragma once
#include <algorithm>
#include "constante.h"
#include "../../entrada.h"

inline void cadastrar(char v[TAMANHO][LARGURA], int indice) {
    if (cadastrados[indice] >= TAMANHO) {
        std::cout << "Cadastro cheio." << std::endl;
        return;
    }
    std::cout << "Entre com o texto a ser cadastrado:" << std::endl;
    std::string nome;
    if (!lerTexto(nome, LARGURA - 1)) return;
    char* destino = v[cadastrados[indice]];
    std::copy(nome.begin(), nome.end(), destino);
    destino[nome.size()] = '\0';
    ++cadastrados[indice];
}

inline void listarTexto(int i, char v[TAMANHO][LARGURA], int indice) {
    if (i >= cadastrados[indice]) return;
    std::cout << "Posicao " << i << ": " << v[i] << std::endl;
    listarTexto(i + 1, v, indice);
}

inline void pesquisar(int i, char v[TAMANHO][LARGURA], int indice) {
    std::cout << "Entre com o texto a ser pesquisado:" << std::endl;
    std::string nome;
    if (!lerTexto(nome, LARGURA - 1)) return;
    for (; i < cadastrados[indice]; ++i) {
        if (nome == v[i]) {
            std::cout << "Posicao " << i << ": " << v[i] << std::endl;
            return;
        }
    }
    std::cout << "Registro nao encontrado." << std::endl;
}

inline void alterar(int i, char v[TAMANHO][LARGURA], int indice) {
    listarTexto(i, v, indice);
    std::cout << "Entre com a posicao a ser alterada:" << std::endl;
    int p;
    if (!lerInteiro(p)) return;
    if (p < 0 || p >= cadastrados[indice]) {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }
    std::cout << "Entre com o novo texto:" << std::endl;
    std::string nome;
    if (!lerTexto(nome, LARGURA - 1)) return;
    std::copy(nome.begin(), nome.end(), v[p]);
    v[p][nome.size()] = '\0';
}

inline void reorganizar(int i, char v[TAMANHO][LARGURA], int indice) {
    if (i >= cadastrados[indice] - 1) return;
    std::copy(v[i + 1], v[i + 1] + LARGURA, v[i]);
    reorganizar(i + 1, v, indice);
}

inline void excluir(int i, char v[TAMANHO][LARGURA], int indice) {
    listarTexto(i, v, indice);
    std::cout << "Entre com a posicao a ser excluida:" << std::endl;
    int p;
    if (!lerInteiro(p)) return;
    if (p < 0 || p >= cadastrados[indice]) {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }
    reorganizar(p, v, indice);
    v[--cadastrados[indice]][0] = '\0';
}
