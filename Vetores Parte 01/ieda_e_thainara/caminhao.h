#pragma once
#include "cadastro.h"

inline int caminhaomenu() {
    int opcao;
    while (true) {
        std::cout << "Caminhao" << std::endl;
        std::cout << CADASTRAR_v2 << " - Incluir" << std::endl;
        std::cout << PESQUISAR_v2 << " - Pesquisar" << std::endl;
        std::cout << ALTERAR_v2 << " - Alterar" << std::endl;
        std::cout << EXCLUIR_v2 << " - Excluir" << std::endl;
        std::cout << "5 - Voltar" << std::endl;
        if (!lerInteiro(opcao) || opcao == 5) return 0;
        switch (opcao) {
        case CADASTRAR_v2: cadastrar(vetor2, IndiceVetor2); break;
        case PESQUISAR_v2: pesquisar(0, vetor2, IndiceVetor2); break;
        case ALTERAR_v2: alterar(0, vetor2, IndiceVetor2); break;
        case EXCLUIR_v2: excluir(0, vetor2, IndiceVetor2); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
