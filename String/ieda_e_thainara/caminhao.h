#pragma once
#include "cadastro.h"

inline int caminhaomenu() {
    int opcao;
    while (true) {
        std::cout << "Caminhao" << std::endl;
        std::cout << CADASTRAR_v2 << " - Incluir" << std::endl;
        std::cout << LISTAR_v2 << " - Listar" << std::endl;
        std::cout << PESQUISAR_v2 << " - Pesquisar" << std::endl;
        std::cout << ALTERAR_v2 << " - Alterar" << std::endl;
        std::cout << EXCLUIR_v2 << " - Excluir" << std::endl;
        std::cout << "6 - Voltar" << std::endl;
        if (!lerInteiro(opcao) || opcao == 6) return 0;
        switch (opcao) {
        case CADASTRAR_v2: cadastrar(caminhaov, Pos_caminhao); break;
        case LISTAR_v2: listarTexto(0, caminhaov, Pos_caminhao); break;
        case PESQUISAR_v2: pesquisar(0, caminhaov, Pos_caminhao); break;
        case ALTERAR_v2: alterar(0, caminhaov, Pos_caminhao); break;
        case EXCLUIR_v2: excluir(0, caminhaov, Pos_caminhao); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
