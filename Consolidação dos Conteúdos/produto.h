#pragma once
#include <algorithm>
#include "constante.h"
#include "../entrada.h"

inline void cadastrarTexto(char v[TAMANHO][LARGURA], int indice) {
    if (cadastrados[indice] >= TAMANHO) {
        std::cout << "Cadastro cheio." << std::endl;
        return;
    }
    std::cout << "Entre com o veiculo a ser cadastrado:" << std::endl;
    std::string nome;
    if (!lerTexto(nome, LARGURA - 1)) return;
    std::cout << "Entre com a quilometragem desde a ultima revisao:" << std::endl;
    int km;
    if (!lerInteiro(km)) return;
    if (km < 0) {
        std::cout << "Quilometragem invalida." << std::endl;
        return;
    }
    const int p = cadastrados[indice];
    std::copy(nome.begin(), nome.end(), v[p]);
    v[p][nome.size()] = '\0';
    quilometragem[p] = km;
    ++cadastrados[indice];
}

inline void listarTexto(int i, char v[TAMANHO][LARGURA], int indice) {
    if (i >= cadastrados[indice]) return;
    std::cout << "Posicao " << i << ": " << v[i] << " - "
              << quilometragem[i] << " km" << std::endl;
    listarTexto(i + 1, v, indice);
}

inline void pesquisarTexto(int i, char v[TAMANHO][LARGURA], int indice,
                           const std::string& nome) {
    if (i >= cadastrados[indice]) {
        std::cout << "Registro nao encontrado." << std::endl;
        return;
    }
    if (nome == v[i]) {
        std::cout << v[i] << " - " << quilometragem[i] << " km" << std::endl;
        return;
    }
    pesquisarTexto(i + 1, v, indice, nome);
}

inline void listarRevisao(int i, char v[TAMANHO][LARGURA], int indice) {
    if (i >= cadastrados[indice]) return;
    if (quilometragem[i] >= 1500) {
        std::cout << "Revisao: " << v[i] << " - "
                  << quilometragem[i] << " km" << std::endl;
    }
    listarRevisao(i + 1, v, indice);
}
