#pragma once
#include "cadastro.h"

inline int produtomenu() {
    int opcao;
    while (true) {
        std::cout << "Produto" << std::endl;
        std::cout << CADASTRAR_v1 << " - Incluir" << std::endl;
        std::cout << PESQUISAR_v1 << " - Pesquisar" << std::endl;
        std::cout << ALTERAR_v1 << " - Alterar" << std::endl;
        std::cout << EXCLUIR_v1 << " - Excluir" << std::endl;
        std::cout << "5 - Voltar" << std::endl;
        if (!lerInteiro(opcao) || opcao == 5) return 0;
        switch (opcao) {
        case CADASTRAR_v1: cadastrar(vetor1, IndiceVetor1); break;
        case PESQUISAR_v1: pesquisar(0, vetor1, IndiceVetor1); break;
        case ALTERAR_v1: alterar(0, vetor1, IndiceVetor1); break;
        case EXCLUIR_v1: excluir(0, vetor1, IndiceVetor1); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
